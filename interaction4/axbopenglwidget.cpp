#include "axbopenglwidget.h"
unsigned int VBO,VAO,EBO;
unsigned int shaderProgram;

float vertices[]={

    0.5f,0.5f,0.0f,//0 top right
    0.5f,-0.5f,0.0f,//1 bottom right
    -0.5f,-0.5f,0.0f,//2 bottom left
    -0.5f,0.5f,0.0f,//3 top left
};
unsigned int indices[]={
    0,1,3, //first triangle
    1,2,3 //second triangle
};

const char*vertexShaderSource = "#version 330 core\n"
                                "layout(location=0)in vec3 aPos;\n"
                                "void main()"
                                "{\n"
                                "gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                "}\0";

const char*fragmentShaderSource="#version 330 core\n"
                                "out vec4 FragColor;\n"
                                "void main()\n"
                                "{\n"
                                "FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
                                "}\0";

AXBOpenGLWidget::AXBOpenGLWidget(QWidget* parent):QOpenGLWidget(parent) {}

AXBOpenGLWidget::~AXBOpenGLWidget()
{
    makeCurrent();
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(shaderProgram);
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
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindVertexArray(VAO);
    //将数据传入显存
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    //告知显卡如何解析
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(GLvoid*)0);
    //开启VAO属性
    glEnableVertexAttribArray(0);
    //EBO
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

    //编译顶点着色
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);


    //编译片段着色器
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    //link shaders
    shaderProgram=glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);


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

    if(!isDraw)return;
    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES,0,6);
    glDrawElements(ShapeType,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
