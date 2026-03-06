#include "axbopenglwidget.h"
unsigned int VBO,VAO,EBO;
#include<QTime>
#include<QFile>
#include<QDebug>

float vertices[]={
    //position  //colorsRGB //texture coords
    0.5f,0.5f,0.0f,1.0f,0.0f,0.0f,2.0f,2.0f,//0 top right
    0.5f,-0.5f,0.0f,0.0f,1.0f,0.0f,2.0f,-1.0f,//1 bottom right
    -0.5f,-0.5f,0.0f,0.0f,0.0f,1.0f,-1.0f,-1.0f,//2 bottom left
    -0.5f,0.5f,0.0f,0.5f,0.5f,0.5f,-1.0f,2.0f//3 top left
};
//纹理坐标的范围通常是从(0, 0)到(1, 1)若把纹理坐标设置在范围之外，OpenGL默认的行为是重复这个纹理图像

unsigned int indices[]={
    0,1,3, //first triangle
    1,2,3 //second triangle
};

AXBOpenGLWidget::AXBOpenGLWidget(QWidget* parent):QOpenGLWidget(parent)
{}

AXBOpenGLWidget::~AXBOpenGLWidget()
{
    delete textureWall;
    makeCurrent();
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    doneCurrent();
}

void AXBOpenGLWidget::drawRectangle()
{
    ShapeType=GL_TRIANGLES;
    isDraw=true;
    update();
}

void AXBOpenGLWidget::clear()
{
    isDraw=false;
    update();
}

void AXBOpenGLWidget::setPolygonMode(bool isWire)
{
    makeCurrent();
    if(isWire)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    doneCurrent();
    update();


}

void AXBOpenGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    // 测试资源文件
    QFile vertFile(":/shaders/shapes.vert");
    if (!vertFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open :/shaders/shapes.vert:" << vertFile.errorString();
    } else {
        qDebug() << "Successfully opened :/shaders/shapes.vert, size:" << vertFile.size();
        vertFile.close();
    }

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindVertexArray(VAO);
    //将数据传入显存
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    //告知显卡如何解析
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(GLvoid*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(GLvoid*)(3*sizeof(float)));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(GLvoid*)(6*sizeof(float)));
    //开启VAO属性
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    //EBO
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);


    //link shaders
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/shaders/shapes.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/shaders/shapes.frag");
    bool success=shaderProgram.link();
    if(!success){
        qDebug()<<shaderProgram.log();
    }
    shaderProgram.bind();

    textureWall=new QOpenGLTexture(QImage(":/resources/dedec41c5d2da800d4d6b46028a0becf.jpeg"));
    textureLe=new QOpenGLTexture(QImage(":/resources/20250927210934.png"));
    shaderProgram.setUniformValue("textureWall",0);
    shaderProgram.setUniformValue("textureLe",1);


    //解绑VAO，VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);

}

void AXBOpenGLWidget::resizeGL(int w, int h)
{

}

void AXBOpenGLWidget::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram.bind();
    if(!isDraw)return;
    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES,0,6);
    textureWall->bind(0);
    textureLe->bind(1);
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_MIRRORED_REPEAT);//左右镜像
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_MIRRORED_REPEAT);//上下镜像
    float borderColor[]={1.0f,1.0f,0.0f,1.0f};
    glTexParameterfv(GL_TEXTURE_2D,GL_TEXTURE_BORDER_COLOR,borderColor);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER);

    glDrawElements(ShapeType,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
