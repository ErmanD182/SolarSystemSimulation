/*
 * main.cpp
 *
 *  Created on: Nov 26, 2018
<<<<<<< HEAD
 *      Author: erman is a stupid idoit...
=======
 *      Author: Erman Dinsel and Stuart Isley
>>>>>>> branch 'master' of https://github.com/ErmanD182/SolarSystemSimulation.git
 */


#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
GLint winWidth = 640, winHeight = 480;



void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Solar System Simulator");
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseDraw(GLint button, GLint action, GLint xMouse, GLint yMouse) {

}

void mouseMotion(GLint xMouse, GLint yMouse) {

}


int main(int argc, char** argv) {

	setvbuf(stdout, NULL, _IONBF, 0); //for printing on Eclipse console
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);


	init();

	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseDraw);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//add right click menu
	glutMainLoop();

	return 0;
}
