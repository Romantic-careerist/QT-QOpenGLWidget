#ifndef AXBOPENGLWIDGET_H
#define AXBOPENGLWIDGET_H

#include <QOpenGLWidget>
#include<QOpenGLFunctions_3_3_Core>
class AXBOpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
public:
    explicit AXBOpenGLWidget(QWidget* parent = nullptr);
    ~AXBOpenGLWidget();
    void drawRectangle();
    void clear();
    void setPolygonMode(bool isWire);
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
private:
    bool isDraw=false;
    int ShapeType=GL_TRIANGLES;
};

#endif // AXBOPENGLWIDGET_H
