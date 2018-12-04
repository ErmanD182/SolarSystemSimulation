/*
 * rotate.hpp
 *
 *  Created on: Nov 28, 2018
 *      //Erman Dinsel and Stuart isley
		//160364040		   160757220
 */

#ifndef ROTATE_HPP_
#define ROTATE_HPP_

#include "matrix.hpp"
Matrix mc;
GLfloat s;

void ctmMultiply();
void scaleChange(GLfloat x);
void translate(GLfloat tx, GLfloat ty, GLfloat tz);
void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);


#endif /* ROTATE_HPP_ */
