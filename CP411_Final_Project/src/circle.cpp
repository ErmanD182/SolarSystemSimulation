/*
 * circle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"circle.hpp"


void setPixel(GLint x, GLint y) {
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y) {
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc + y, yc - x);
	glEnd();
}

void circleMidpointFill(GLint xc, GLint yc, GLfloat r) {
	GLint p = 1 - r;
	GLint x = 0, y = r;
	circlePlotPointsFill(xc, yc, x, y);
	while (x < y) {
			x++;
			if (p < 0){
				p += 2 * x + 1;
			}else {
				y--;
				p += 2 * (x - y) + 1;
			}
			circlePlotPointsFill(xc, yc, x, y);
		}
}
