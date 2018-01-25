#pragma once
class Boat
{
	GLuint VAO1, VAO2, VAO3;
	GLuint VBO1, VBO2, VBO3;
	std::vector<GLfloat> boatCoord;
	std::vector<GLfloat> rudderCoord;
	std::vector<GLfloat> wheelCoord;
public:
	Boat(GLfloat scale);
	~Boat();
	void initBuffers(GLuint &vao, GLuint &vbo, const std::vector<GLfloat> &vec);
	void drawBoat(const glm::mat4&, GLuint modelLoc) const;
	void drawRudder(const glm::mat4&, GLuint modelLoc) const;
	void drawWheel(const glm::mat4&, GLuint modelLoc) const;
	void loadVertices(std::vector<GLfloat> &vec, const GLfloat *v, int n, GLfloat scale);
};

static GLfloat bottom[] = {
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,		//bottom
	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.15f, -0.5f, 1.0f, 0.0f,
	0.25f, -0.15f, -0.5f, 1.0f, 0.0f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.15f, 0.5f, 1.0f, 1.0f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.15f, 0.5f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.5f, 0.5f,

	-0.25f, -0.1f, 0.5f, 0.0f, 1.0f,		//top
	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	-0.25f, -0.1f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, 0.5f, 1.0f, 1.0f,
	-0.25f, -0.1f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, 0.5f, 1.0f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.5f, 0.5f,

	-0.25f, -0.1f, 0.5f, 1.0f, 1.0f,		//left
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	-0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	-0.25f, -0.1f, -0.5f, 1.0f, 0.0f,

	0.25f, -0.1f, 0.5f, 1.0f, 1.0f,			//right
	0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,

	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,		//front left
	-0.25f, -0.1f, 0.5f, 0.0f, 0.5f,
	0.0f, -0.1f, 0.8f, 0.5f, 0.5f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.5f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.5f, 0.5f,

	0.25f, -0.15f, 0.5f, 1.0f, 1.0f,		//front right
	0.25f, -0.1f, 0.5f, 1.0f, 0.5f,
	0.0f, -0.1f, 0.8f, 0.5f, 0.5f,
	0.25f, -0.15f, 0.5f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.5f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.5f, 0.5f,

	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,		//back
	-0.25f, -0.15f, -0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	-0.25f, -0.15f, -0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 0.0f,
	0.25f, -0.15f, -0.5f, 1.0f, 1.0f,
};

static GLfloat leftSide[] = {
	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,		//outside
	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f,
	-0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	-0.35f, 0.1f, 0.65f, 1.0f, 1.0f,

	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,		//inside
	-0.32f, 0.1f, -0.55f, 1.0f, 0.0f,
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,
	-0.25f, -0.1f, 0.5f, 0.0f, 1.0f,
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,

	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f, 		//top
	-0.32f, 0.1f, -0.55f, 0.9f, 0.0f, 
	-0.32f, 0.1f, 0.65f, 0.9f, 1.0f, 
	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f, 
	-0.35f, 0.1f, 0.65f, 1.0f, 1.0f, 
	-0.32f, 0.1f, 0.65f, 0.9f, 1.0f, 

	-0.35f, 0.1f, 0.65f, 0.0f, 0.0f,			//front
	-0.32f, 0.1f, 0.65f, 1.0f, 0.0f,
	-0.25f, -0.1f, 0.5f, 1.0f, 1.0f,
	-0.35f, 0.1f, 0.65f, 0.0f, 0.0f,
	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	-0.25f, -0.1f, 0.5f, 1.0f, 1.0f,

	-0.35f, 0.1f, -0.55f, 0.0f, 0.0f,		//back
	-0.32f, 0.1f, -0.55f, 1.0f, 0.0f,
	-0.25f, -0.1f, -0.5f, 1.0f, 1.0f,
	-0.35f, 0.1f, -0.55f, 0.0f, 0.0f,
	-0.25f, -0.15f, -0.5f, 0.0f, 1.0f,
	-0.25f, -0.1f, -0.5f, 1.0f, 1.0f
};

static GLfloat rightSide[] = {
	0.25f, -0.15f, -0.5f, 0.0f, 0.0f,		//outside
	0.35f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.35f, 0.1f, 0.65f, 1.0f, 1.0f,

	0.25f, -0.1f, -0.5f, 0.0f, 0.0f,		//inside
	0.32f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.25f, -0.1f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.1f, 0.5f, 0.0f, 1.0f,
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,

	0.35f, 0.1f, -0.55f, 1.0f, 0.0f, 		//top
	0.32f, 0.1f, -0.55f, 0.9f, 0.0f,
	0.32f, 0.1f, 0.65f, 0.9f, 1.0f,
	0.35f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.32f, 0.1f, 0.65f, 0.9f, 1.0f,

	0.35f, 0.1f, 0.65f, 0.0f, 0.0f,			//front
	0.32f, 0.1f, 0.65f, 1.0f, 0.0f,
	0.25f, -0.1f, 0.5f, 1.0f, 1.0f,
	0.35f, 0.1f, 0.65f, 0.0f, 0.0f,
	0.25f, -0.15f, 0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, 0.5f, 1.0f, 1.0f,

	0.35f, 0.1f, -0.55f, 0.0f, 0.0f,		//back
	0.32f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 1.0f,
	0.35f, 0.1f, -0.55f, 0.0f, 0.0f,
	0.25f, -0.15f, -0.5f, 0.0f, 1.0f,
	0.25f, -0.1f, -0.5f, 1.0f, 1.0f
};

static GLfloat back[] = {
	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,		//inside
	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.35f, 0.1f, -0.55f, 1.0f, 1.0f,
	-0.25f, -0.1f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.1f, -0.5f, 0.0f, 1.0f,
	0.35f, 0.1f, -0.55f, 1.0f, 1.0f,

	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,		//outside
	-0.35f, 0.1f, -0.6f, 1.0f, 0.0f,
	0.35f, 0.1f, -0.6f, 1.0f, 1.0f,
	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,
	0.25f, -0.15f, -0.5f, 0.0f, 1.0f,
	0.35f, 0.1f, -0.6f, 1.0f, 1.0f,

	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f,		//top
	-0.35f, 0.1f, -0.6f, 0.9f, 0.0f,
	0.35f, 0.1f, -0.6f, 0.9f, 1.0f,
	-0.35f, 0.1f, -0.55f, 1.0f, 0.0f,
	0.35f, 0.1f, -0.55f, 1.0f, 1.0f,
	0.35f, 0.1f, -0.6f, 0.9f, 1.0f,

	-0.25f, -0.15f, -0.5f, 0.0f, 0.0f,		//left
	-0.35f, 0.1f, -0.6f, 1.0f, 0.0f,
	-0.35f, 0.1f, -0.55f, 1.0f, 0.2f,

	0.25f, -0.15f, -0.5f, 0.0f, 0.0f,		//right
	0.35f, 0.1f, -0.6f, 1.0f, 0.0f,
	0.35f, 0.1f, -0.55f, 1.0f, 0.2f
};

static GLfloat frontLeft[] = {
	-0.25f, -0.1f, 0.5f, 0.0f, 1.0f,		//inside
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.0f, 0.0f,
	0.0, 0.1f, 1.0f, 1.0f, 0.0f,
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.0f, 0.0f,

	-0.25f, -0.15f, 0.5f, 0.0f, 1.0f,		//outside
	-0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.0f, 0.0f,
	0.0, 0.1f, 1.05f, 1.0f, 0.0f,
	-0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.0f, 0.0f,

	-0.35f, 0.1f, 0.65f, 0.9f, 1.0f,		//top
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, 0.1f, 1.05f, 0.9f, 0.0f,
	0.0, 0.1f, 1.0f, 1.0f, 0.0f,
	-0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, 0.1f, 1.05f, 0.9f, 0.0f
};

static GLfloat frontRight[] = {
	0.25f, -0.1f, 0.5f, 0.0f, 1.0f,			//inside
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.0f, 0.0f,
	0.0, 0.1f, 1.0f, 1.0f, 0.0f,
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.1f, 0.8f, 0.0f, 0.0f,

	0.25f, -0.15f, 0.5f, 0.0f, 1.0f,		//outside
	0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.0f, 0.0f,
	0.0, 0.1f, 1.05f, 1.0f, 0.0f,
	0.35f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, -0.15f, 0.8f, 0.0f, 0.0f,

	0.35f, 0.1f, 0.65f, 0.9f, 1.0f,			//top
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, 0.1f, 1.05f, 0.9f, 0.0f,
	0.0, 0.1f, 1.0f, 1.0f, 0.0f,
	0.32f, 0.1f, 0.65f, 1.0f, 1.0f,
	0.0f, 0.1f, 1.05f, 0.9f, 0.0f
};

static GLfloat wheelPillar[] = {
	0.02f, -0.1f, -0.2f, 0.0f, 1.0f,		//front
	-0.02f, -0.1f, -0.2f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 1.0f, 1.0f,
	-0.02f, 0.05f, -0.2f, 1.0f, 0.5f,
	-0.02f, -0.1f, -0.2f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 1.0f, 1.0f,

	0.02f, -0.1f, -0.24f, 0.0f, 1.0f,		//back
	-0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.24f, 1.0f, 1.0f,
	-0.02f, 0.05f, -0.24f, 1.0f, 0.5f,
	-0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.24f, 1.0f, 1.0f,

	-0.02f, -0.1f, -0.2f, 0.0f, 1.0f,		//left
	-0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	-0.02f, 0.05f, -0.2f, 1.0f, 1.0f,
	-0.02f, 0.05f, -0.24f, 1.0f, 0.5f,
	-0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	-0.02f, 0.05f, -0.2f, 1.0f, 1.0f,

	0.02f, -0.1f, -0.2f, 0.0f, 1.0f,		//right
	0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 1.0f, 1.0f,
	0.02f, 0.05f, -0.24f, 1.0f, 0.5f,
	0.02f, -0.1f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 1.0f, 1.0f,

	-0.02f, 0.05f, -0.2f, 0.0f, 1.0f,		//top
	-0.02f, 0.05f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 0.5f, 1.0f,
	0.02f, 0.05f, -0.24f, 0.5f, 0.5f,
	-0.02f, 0.05f, -0.24f, 0.0f, 0.5f,
	0.02f, 0.05f, -0.2f, 0.5f, 1.0f
};

static GLfloat rudderAttach[] = {
	-0.005f, -0.05f, -0.52f, 0.0f, 1.0f,		//left
	0.0f, -0.05f, -0.53f, 0.0f, 0.8f,
	-0.005f, -0.14f, -0.52f, 1.0f, 1.0f,
	0.0f, -0.14f, -0.53f, 1.0f, 0.8f,
	0.0f, -0.05f, -0.53f, 0.0f, 0.8f,
	-0.005f, -0.14f, -0.52f, 1.0f, 1.0f,

	0.005f, -0.05f, -0.52f, 0.0f, 1.0f,		//right
	0.0f, -0.05f, -0.53f, 0.0f, 0.8f,
	0.005f, -0.14f, -0.52f, 1.0f, 1.0f,
	0.0f, -0.14f, -0.53f, 1.0f, 0.8f,
	0.0f, -0.05f, -0.53f, 0.0f, 0.8f,
	0.005f, -0.14f, -0.52f, 1.0f, 1.0f,

	-0.005f, -0.05f, -0.52f, 0.0f, 1.0f,		//front
	0.005f, -0.05f, -0.52f, 0.0f, 0.8f,
	-0.005f, -0.14f, -0.52f, 1.0f, 1.0f,
	0.005f, -0.14f, -0.52f, 1.0f, 0.8f,
	0.005f, -0.05f, -0.52f, 0.0f, 0.8f,
	-0.005f, -0.14f, -0.52f, 1.0f, 1.0f
};

static GLfloat rudder[] = {
	-0.01f, -0.14f, -0.51f, 0.0f, 1.0f,		//top
	0.01f, -0.14f, -0.51f, 0.0f, 0.8f,
	0.0f, -0.14f, -0.62f, 1.0f, 0.9f,

	-0.01f, -0.24f, -0.51f, 0.0f, 1.0f,		//bottom
	0.01f, -0.24f, -0.51f, 0.0f, 0.8f,
	0.0f, -0.24f, -0.62f, 1.0f, 0.9f,

	-0.01f, -0.14f, -0.51f, 0.0f, 1.0f,		//front
	0.01f, -0.14f, -0.51f, 0.0f, 0.6f,
	-0.01f, -0.24f, -0.51f, 1.0f, 1.0f,
	0.01f, -0.24f, -0.51f, 1.0f, 0.6f,
	0.01f, -0.14f, -0.51f, 0.0f, 0.6f,
	-0.01f, -0.24f, -0.51f, 1.0f, 1.0f,

	0.0f, -0.14f, -0.62f, 0.0f, 1.0f,		//left
	-0.01f, -0.14f, -0.51f, 0.0f, 0.0f,
	0.0f, -0.24f, -0.62f, 1.0f, 1.0f,
	-0.01f, -0.24f, -0.51f, 1.0f, 0.0f,
	-0.01f, -0.14f, -0.51f, 0.0f, 0.0f,
	0.0f, -0.24f, -0.62f, 1.0f, 1.0f,

	0.0f, -0.14f, -0.62f, 0.0f, 1.0f,		//right
	0.01f, -0.14f, -0.51f, 0.0f, 0.0f,
	0.0f, -0.24f, -0.62f, 1.0f, 1.0f,
	0.01f, -0.24f, -0.51f, 1.0f, 0.0f,
	0.01f, -0.14f, -0.51f, 0.0f, 0.0f,
	0.0f, -0.24f, -0.62f, 1.0f, 1.0f
};

static GLfloat wheel[] = {
	-0.01f, 0.04f, -0.24f, 0.0f, 0.0f,		//side
	-0.01f, 0.04f, -0.26f, 0.2f, 0.0f,
	0.01f, 0.04f, -0.24f, 0.0f, 0.2f,
	0.01f, 0.04f, -0.26f, 0.2f, 0.2f,
	-0.01f, 0.04f, -0.26f, 0.2f, 0.0f,
	0.01f, 0.04f, -0.24f, 0.0f, 0.2f,

	-0.01f, 0.04f, -0.26f, 0.0f, 0.0f,		//back
	0.01f, 0.04f, -0.26f, 0.0f, 0.2f,
	0.0f, 0.022679f, -0.26f, 0.2f, 0.1f,

	-0.01f, 0.04f, -0.24f, 0.0f, 0.0f,		//front
	0.01f, 0.04f, -0.24f, 0.0f, 0.2f,
	0.0f, 0.022679f, -0.24f, 0.2f, 0.1f,

	-0.005f, 0.1f, -0.245f, 0.0f, 0.0f,		//handle top
	0.005f, 0.1f, -0.245f, 0.0f, 0.1f,
	0.0f, 0.1f, -0.255f, 0.1f, 0.05f,

	-0.005f, 0.1f, -0.245f, 0.0f, 0.0f,		//handle front
	0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	-0.005f, 0.03f, -0.245f, 0.0f, 1.0f,
	0.005f, 0.03f, -0.245f, 0.2f, 1.0f,
	0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	-0.005f, 0.03f, -0.245f, 0.0f, 1.0f,

	0.0f, 0.1f, -0.255f, 0.0f, 0.0f,		//handle left
	-0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	0.0f, 0.03f, -0.255f, 0.0f, 1.0f,
	-0.005f, 0.03f, -0.245f, 0.2f, 1.0f,
	-0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	0.0f, 0.03f, -0.255f, 0.0f, 1.0f,

	0.0f, 0.1f, -0.255f, 0.0f, 0.0f,		//handle right
	0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	0.0f, 0.03f, -0.255f, 0.0f, 1.0f,
	0.005f, 0.03f, -0.245f, 0.2f, 1.0f,
	0.005f, 0.1f, -0.245f, 0.2f, 0.0f,
	0.0f, 0.03f, -0.255f, 0.0f, 1.0f
};