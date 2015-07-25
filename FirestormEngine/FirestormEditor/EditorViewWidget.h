#include<qopenglwidget.h>
#include<QtGui/qopenglfunctions.h>

class EditorViewWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	EditorViewWidget(QWidget *parent);
protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer VBO;
	int position_attribute;
	int color_uniform;
	float Vertices[9];
	const char* vert = "#version 150          \n"
		"                                           \n"
		"   in vec3 position;                       \n"
		"                                           \n"
		"   void main()                             \n"
		"   {                                       \n"
		"       gl_Position = vec4(position, 1.0);  \n"
		"   }";
	const char* frag = "#version 150          \n"
		"                                           \n"
		"   uniform vec3 Color;                     \n"
		"   out vec4 outColor;                      \n"
		"                                           \n"
		"   void main()                             \n"
		"   {                                       \n"
		"       outColor = vec4(Color, 1.0);        \n"
		"   }";
};