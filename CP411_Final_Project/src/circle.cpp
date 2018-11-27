/*
 * circle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"circle.hpp"

circle * new_object(GLint x1, GLint y1, GLint x2,  GLint y2){
	circle *p = (circle *) malloc(sizeof(circle));
    p->x1 = x1;
    p->y1 = y1;
    p->x2 = x2;
    p->y2 = y2;


    p->r = 1.0;
    p->g = 0.0;
    p->b = 0.0;

    return p;
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
