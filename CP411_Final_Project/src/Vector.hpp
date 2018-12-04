//Erman Dinsel and Stuart isley
//160364040		   160757220

#ifndef CVECTOR_H
#define CVECTOR_H

#include <GL/glut.h>
#include "Point.hpp"

class Vector {
 public:
	GLfloat x,y,z;
	Vector();
	Vector(GLfloat dx, GLfloat dy, GLfloat dz);
	void set(GLfloat dx, GLfloat yy, GLfloat dz);
	void set(Vector v);
	void setDiff(Point a, Point b);
	void flip();
	void normalize();
	Vector diff(Point a, Point b);
	Vector cross(Vector b);
	GLfloat dot(Vector b);
	void build4tuple(GLfloat v[]);
	void printVector();
};

#endif
