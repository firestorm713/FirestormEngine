#include"EditorViewWidget.h"
EditorViewWidget::EditorViewWidget(QWidget* parent)
	:QOpenGLWidget(parent)
{
	float v[] = {
		0.0, 0.5, 0.0,
		0.5, -0.5, 0.0,
		-0.5, -0.5, 0.0
	};
	for (int i = 0; i < 9; i++)
		Vertices[i] = v[i];
}

void EditorViewWidget::initializeGL()
{
	initializeOpenGLFunctions();
	vao.create();
	vao.bind();

	//glGenBuffers(1, &VBO);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	shaderProgram = new QOpenGLShaderProgram(this);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vert);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, frag);
	shaderProgram->link();
	shaderProgram->bind();
	position_attribute = shaderProgram->attributeLocation("position");
	color_uniform = shaderProgram->uniformLocation("Color");
	VBO.create();
	VBO.bind();
	VBO.allocate(&Vertices, 9 * sizeof(float));
	shaderProgram->enableAttributeArray(position_attribute);
	shaderProgram->setAttributeArray(position_attribute, Vertices, 3);
	shaderProgram->setUniformValue(color_uniform, 1.0f, 1.0f, 1.0f);
	//glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void EditorViewWidget::resizeGL(int w, int h)
{
}

void EditorViewWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	VBO.bind();
	VBO.allocate(&Vertices, 9 * sizeof(float));
	shaderProgram->enableAttributeArray(position_attribute);
	shaderProgram->setAttributeArray(position_attribute, Vertices, 3, 0);
	shaderProgram->setUniformValue(color_uniform, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	shaderProgram->disableAttributeArray(position_attribute);
}