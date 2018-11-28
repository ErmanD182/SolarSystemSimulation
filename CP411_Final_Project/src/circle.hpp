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
    GLfloat r, g, b;
    GLint radius;
} circle;

circle * new_object(GLint x1, GLint y1, GLint x2,  GLint y2);
void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y, GLuint texture);
void circleMidpointFill(GLint xc, GLint yc, GLfloat r, GLuint texture);
GLuint loadBMP_custom(const char * imagepath);

void drawCircleOutline(circle *c, GLuint texture);


#endif /* CIRCLE_HPP_ */
