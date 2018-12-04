/**
 *	file Shape.hpp
 *	//Erman Dinsel and Stuart isley
	//160364040		   160757220
 *
 */

#ifndef CSHAPE_H
#define CSHAPE_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace std;


class Shape {
protected:
	Matrix mc;
	GLfloat s;

public:
	Shape();
	virtual ~Shape();
	Matrix getMC();
	void ctmMultiply();
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void reset();
	virtual void draw() = 0; // draw function must be overwritten

};

#endif
