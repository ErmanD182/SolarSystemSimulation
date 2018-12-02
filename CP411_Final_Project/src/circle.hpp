/*
 * circle.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "GL/glew.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <windows.h>


typedef struct circle{
    GLint x1,y1,x2,y2;
    GLint radius;
}circle;

typedef struct planet2D{
	circle c;
	GLint radiusOrb;
	GLint radiusGrav;
	GLuint texture;
	circle orbit;
}planet2D;

planet2D * new_planet(GLint x1, GLint y1, GLint radius, GLint radiusOrb, GLint radiusGrav, GLuint texture);
GLuint loadBMP_custom(const char * imagepath);
void setPixel(GLint x, GLint y);
void circleMidpoint(GLint xc, GLint yc, GLfloat r);
void circlePlotPoints(const GLint& xc, const GLint& yc, const GLint& x, const GLint& y);
void drawPlanet(planet2D *p);
void circleMidpointFill(GLint x1, GLint y1, GLint radius);
void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y);
void drawOrbit(GLint x, GLint y,GLint radius);
void drawField(GLint x, GLint y, GLint radius);


#endif /* CIRCLE_HPP_ */
