//Erman Dinsel and Stuart isley
//160364040		   160757220

#ifndef SPHERE_H
#define SPHERE_H

#include <windows.h>
#include <GL/glut.h>
#include "Shape.hpp"

class Sphere: public Shape {
public:
	enum RenderMode {
		MODE_WIRE = 0,
		MODE_SOLID,
		MODE_GLSL_SOLID,
		MODE_TEXTURE
	};

	RenderMode mode;
	GLfloat radius;
	GLint splices, stacks;
	GLuint textureID;
	GLUquadric *quad;
	Sphere();
	~Sphere();
	void draw();
	void drawField3D();
};

#endif
