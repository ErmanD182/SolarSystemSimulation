//Erman Dinsel and Stuart isley
//160364040		   160757220
#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <GL/gl.h>
#include <math.h>

using namespace std;

class Matrix {
public:
	GLfloat mat[4][4];
	Matrix();
	void reset();
	void matrixPreMultiply(Matrix* m);
	void multiplyVector(GLfloat* v);
	void normalize();
	void transpose();
	void rotateMatrix(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
};

#endif
