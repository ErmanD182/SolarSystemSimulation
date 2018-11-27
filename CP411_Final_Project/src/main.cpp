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
#include"menu.hpp"

GLint winWidth = 1200, winHeight = 750;



void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(150, 20);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Solar System Simulator");
	glutSwapBuffers();

}


void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), GLdouble(newHeight), 0.0);
	winWidth = newWidth;
	winHeight = newHeight;
	glFlush();
}

void mouseAction(GLint button, GLint action, GLint x, GLint y) {

}

void mouseMotion(GLint x, GLint y) {

}


int main(int argc, char** argv) {

	setvbuf(stdout, NULL, _IONBF, 0); //for printing on Eclipse console
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);
	Menu();

	init();

	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseAction);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//add right click menu
	glutMainLoop();

	return 0;
}
