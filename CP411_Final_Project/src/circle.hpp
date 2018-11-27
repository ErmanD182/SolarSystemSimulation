/*
 * circle.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void setPixel(GLint x, GLint y);
void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y);
void circleMidpointFill(GLint xc, GLint yc, GLfloat r);



#endif /* CIRCLE_HPP_ */
