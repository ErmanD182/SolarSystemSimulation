/**
 *	File Matrix.cpp
 **	//Erman Dinsel and Stuart isley
	//160364040		   160757220
 *
 */

#include "Matrix.hpp"


Matrix::Matrix() {
	reset();
}

void Matrix::reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}


void Matrix::matrixPreMultiply(Matrix* m) {
	GLfloat temp[4][4], sum=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m->mat[i][k] * mat[k][j];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}



void Matrix::transpose() {
	GLfloat temp[4][4];
	for (int i = 0; i< 4; i++){
		for (int j = 0; j < 4; j++){
			temp[j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}

}


void Matrix::normalize() {
	GLfloat norm = sqrt(mat[0][0]*mat[0][0] + mat[1][0]*mat[1][0]+mat[2][0]*mat[2][0]);
	mat[0][0] = mat[0][0]/norm;
	mat[1][0] = mat[1][0]/norm;
	mat[2][0] = mat[2][0]/norm;
	mat[0][2] = mat[1][0]*mat[2][1]-mat[2][0]*mat[1][1];
	mat[1][2] = mat[2][0]*mat[0][1]-mat[0][0]*mat[2][1];
	mat[2][2] = mat[0][0]*mat[1][1]-mat[1][0]*mat[0][1];
	norm = sqrt(mat[0][2]*mat[0][2] + mat[1][2]*mat[1][2]+mat[2][2]*mat[2][2]);
	mat[0][2] = mat[0][2]/norm;
	mat[1][2] = mat[1][2]/norm;
	mat[2][2] = mat[2][2]/norm;
	mat[0][1] = mat[1][2]*mat[2][0]-mat[1][0]*mat[2][2];
	mat[1][1] = mat[2][2]*mat[0][0]-mat[2][0]*mat[0][2];
	mat[2][1] = mat[0][2]*mat[1][0]-mat[0][0]*mat[1][2];
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}


void Matrix::multiplyVector(GLfloat *v) {
	GLfloat sum, temp[4];
		for (int i = 0; i < 4; i++) {
			sum = 0;
			for (int j = 0; j < 4; j++) {
				sum +=  mat[i][j] * v[j];
			}
			temp[i] = sum;
		}
		for (int i = 0; i < 4; i++) {
			v[i] = temp[i];
		}

}


void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	GLfloat radianAngle = angle * 3.1415926/180;
	GLfloat axisVectLength = sqrt (rx* rx + ry*ry + rz*rz);
	GLfloat cosA = cos (radianAngle);
	GLfloat oneC = 1 - cosA;
	GLfloat sinA = sin (radianAngle);
	GLfloat ux = (rx) / axisVectLength;
	GLfloat uy = (ry) / axisVectLength;
	GLfloat uz = (rz) / axisVectLength;

	mat[0][0] = ux*ux*oneC + cosA;
	mat[0][1] = ux*uy*oneC - uz*sinA;
	mat[0][2] = ux*uz*oneC + uy*sinA;
	mat[0][3] = 0;

	mat[1][0] = uy*ux*oneC + uz*sinA;
	mat[1][1] = uy*uy*oneC + cosA;
	mat[1][2] = uy*uz*oneC - ux*sinA;
	mat[1][3] = 0;

	mat[2][0] = uz*ux*oneC - uy*sinA;
	mat[2][1] = uz*uy*oneC + ux*sinA;
	mat[2][2] = uz*uz*oneC + cosA;
	mat[2][3] = 0;

	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

