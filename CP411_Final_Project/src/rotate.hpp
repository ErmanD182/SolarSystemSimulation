/*
 * rotate.hpp
 *
 *  Created on: Nov 28, 2018
 *      Author: erman
 */

#ifndef ROTATE_HPP_
#define ROTATE_HPP_

#include "matrix.hpp"
Matrix mc; // the Model coordinate system (X, Y, Z, 0) in WC, represent the position of the object in WC
GLfloat s; // scale factor

void ctmMultiply();    // function to do the CTM * MC
void scaleChange(GLfloat x); // to change the scale factor
void translate(GLfloat tx, GLfloat ty, GLfloat tz); //translate the MC origin
void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);      // rotate object in WC
void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// just rotate the origin of object in WC
void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);


#endif /* ROTATE_HPP_ */
