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

#include "circle.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include"menu.hpp"

#include <math.h>
#include "solarsystem.hpp"

GLint winWidth = 1200, winHeight = 750;
GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture,jupitorTexture;
GLuint saturnTexture,uranusTexture, neptuneTexture, plutoTexture;

GLint move = 0;
GLint xbegin = 0, ybegin = 0;
GLint view = 0, option = 0;

GLint theta;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	sunTexture = loadBMP_custom("sun.bmp");
	mercuryTexture = loadBMP_custom("mercury.bmp");
	venusTexture = loadBMP_custom("venus.bmp");
	earthTexture = loadBMP_custom("earth.bmp");
	marsTexture = loadBMP_custom("mars.bmp");
	jupitorTexture = loadBMP_custom("jupitor.bmp");
	saturnTexture = loadBMP_custom("saturn.bmp");
	uranusTexture = loadBMP_custom("uranus.bmp");
	neptuneTexture = loadBMP_custom("neptune.bmp");
	plutoTexture = loadBMP_custom("pluto.bmp");
	glFlush();
}


void mouseAction(GLint button, GLint action, GLint x, GLint y) {
if (button == GLUT_LEFT_BUTTON){
	if (action == GLUT_DOWN){
		move = 1;
		xbegin = x;
	}
}

}
void mouseMotion(GLint x, GLint y) {
	theta = (xbegin - x > 0) ? 1 : -1;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
	glFlush();
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

int main(int argc, char** argv) {

	setvbuf(stdout, NULL, _IONBF, 0); //for printing on Eclipse console
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);
	Menu();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 20);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Solar System Simulator");

	init();

	glutDisplayFunc(display);
	glutTimerFunc(25, update, 0);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseAction);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//add right click menu
	glutMainLoop();

	return 0;
}
