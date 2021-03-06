//Erman Dinsel and Stuart isley
//160364040		   160757220

#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"



Camera::Camera() {
	setDefaultCamera();
	setViewNorm();
}

void Camera::setDefaultCamera(void) { // make default camera
	eye.set(5.0, 10.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 0, 1);
	aspect = 1.5, viewAngle = 70.0, nearDist = 1.0, farDist = 500.0;
	setViewNorm();
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 40.0;
	setViewNorm();
}


void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle, aspect, nearDist, farDist);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x,viewup.y,viewup.z);

}

void Camera::setViewNorm() {
	GLfloat x, y, z, sr;
	x = ref.x-eye.x;
	y = ref.y-eye.y;
	z = ref.z-eye.z;
	sr = sqrt(x*x + y*y + z*z);
	x = x/sr;
	y = y/sr;
	z = z/sr;
	viewNorm.set(x, y, z);
}


void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) { //w.r.p.t WC
Matrix *m =  new Matrix();
m->rotateMatrix(rx, ry, rz, angle);
GLfloat vec[4];
vec[0] = eye.x;
vec[1] = eye.y;
vec[2] = eye.z;
vec[3] = 1;
m->multiplyVector(vec);
eye.x = vec[0];
eye.y = vec[1];
eye.z = vec[2];
setViewNorm();

}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz){ //w.r.p.t WC
eye.x = eye.x + tx;
eye.y = eye.y + ty;
eye.z = eye.z + tz;
setViewNorm();
}

