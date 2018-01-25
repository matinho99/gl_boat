#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Boat.h"

Boat::Boat(GLfloat scale) {
	loadVertices(boatCoord, bottom, _countof(bottom), scale);
	loadVertices(boatCoord, leftSide, _countof(leftSide), scale);
	loadVertices(boatCoord, rightSide, _countof(rightSide), scale);
	loadVertices(boatCoord, back, _countof(back), scale);
	loadVertices(boatCoord, frontLeft, _countof(frontLeft), scale);
	loadVertices(boatCoord, frontRight, _countof(frontRight), scale);
	loadVertices(boatCoord, wheelPillar, _countof(wheelPillar), scale);
	loadVertices(rudderCoord, rudderAttach, _countof(rudderAttach), scale);
	loadVertices(rudderCoord, rudder, _countof(rudder), scale);
	loadVertices(wheelCoord, wheel, _countof(wheel), scale);
	initBuffers(VAO1, VBO1, boatCoord);
	initBuffers(VAO2, VBO2, rudderCoord);
	initBuffers(VAO3, VBO3, wheelCoord);
}

void Boat::initBuffers(GLuint &vao, GLuint &vbo, const std::vector<GLfloat> &vec) {
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

void Boat::drawBoat(const glm::mat4& modelTrans, GLuint modelLoc) const {
	glBindVertexArray(VAO1);

	// no internal transformations for now
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glDrawArrays(GL_TRIANGLES, 0, (GLuint)boatCoord.size());

	// all is drawn - unbind vertex array
	glBindVertexArray(0);
}

void Boat::drawRudder(const glm::mat4& modelTrans, GLuint modelLoc) const {
	glBindVertexArray(VAO2);

	// no internal transformations for now
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glDrawArrays(GL_TRIANGLES, 0, (GLuint)rudderCoord.size());

	// all is drawn - unbind vertex array
	glBindVertexArray(0);
}

void Boat::drawWheel(const glm::mat4& modelTrans, GLuint modelLoc) const {
	glBindVertexArray(VAO3);

	// no internal transformations for now
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glDrawArrays(GL_TRIANGLES, 0, (GLuint)wheelCoord.size());

	// all is drawn - unbind vertex array
	glBindVertexArray(0);
}

void Boat::loadVertices(std::vector<GLfloat> &vec, const GLfloat *v, int n, GLfloat scale) {
	for (int i = 0; i < n / 5; ++i) {
		vec.push_back(v[i * 5] * scale);
		vec.push_back(v[i * 5 + 1] * scale);
		vec.push_back(v[i * 5 + 2] * scale);
		vec.push_back(v[i * 5 + 3]);
		vec.push_back(v[i * 5 + 4]);
	}
}

Boat::~Boat() {
	glDeleteVertexArrays(1, &VAO1);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteVertexArrays(1, &VAO3);
	glDeleteBuffers(1, &VBO1);
	glDeleteBuffers(1, &VBO2);
	glDeleteBuffers(1, &VBO3);
}
