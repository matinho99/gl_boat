#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Water.h"

Water::Water(GLfloat scale) {
	loadVertices(waterCoord, water, _countof(water), scale);
	initBuffers(VAO, VBO, waterCoord);
}

Water::~Water() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Water::initBuffers(GLuint &vao, GLuint &vbo, const std::vector<GLfloat> &vec) {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* vec.size(), &(vec[0]), GL_STATIC_DRAW);

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex texture coordinates
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Water::draw(const glm::mat4& modelTrans, GLuint modelLoc) const {
	glBindVertexArray(VAO);

	// no internal transformations for now
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glDrawArrays(GL_TRIANGLES, 0, (GLuint)waterCoord.size());

	// all is drawn - unbind vertex array
	glBindVertexArray(0);
}

void Water::loadVertices(std::vector<GLfloat> &vec, const GLfloat *v, int n, GLfloat scale) {
	for (int i = 0; i < n / 5; ++i) {
		vec.push_back(v[i * 5] * scale);
		vec.push_back(v[i * 5 + 1] * scale);
		vec.push_back(v[i * 5 + 2] * scale);
		vec.push_back(v[i * 5 + 3]);
		vec.push_back(v[i * 5 + 4]);
	}
}