#pragma once
class Water
{
	GLuint VAO;
	GLuint VBO;
	std::vector<GLfloat> waterCoord;
public:
	Water(GLfloat scale);
	~Water();
	void initBuffers(GLuint &vao, GLuint &vbo, const std::vector<GLfloat> &vec);
	void draw(const glm::mat4&, GLuint modelLoc) const;
	void loadVertices(std::vector<GLfloat> &vec, const GLfloat *v, int n, GLfloat scale);
};

static GLfloat water[] = {
	-5.0f, -0.09f, 5.0f, 0.0f, 0.0f,
	5.0f, -0.09f, 5.0f, 0.0f, 1.0f,
	-5.0f, -0.09f, -5.0f, 1.0f, 0.0f,
	5.0f, -0.09f, -5.0f, 1.0f, 1.0f,
	5.0f, -0.09f, 5.0f, 0.0f, 1.0f,
	-5.0f, -0.09f, -5.0f, 1.0f, 0.0f
};