/*
 * main.cpp
 *
 *  Created on: Nov 26, 2018
=======
 *      Author: Erman Dinsel and Stuart Isley
 */

#include "circle.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include"menu.hpp"
#include"Camera.hpp"
#include <math.h>
#include "solarsystem.hpp"

GLint winWidth = 1200, winHeight = 750;
GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture,jupitorTexture;
GLuint saturnTexture,uranusTexture, neptuneTexture, plutoTexture, asteroidTexture;

GLint move = 0;
GLint xbegin = 0, ybegin = 0;
GLint view = 0, option = 0, cameraSelect = 0, orbits = 0, gravFields = 0, lockCamera = 0;

GLint theta;
Camera camera;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-winWidth / 0.9 + 1200, winWidth / 0.9, -winHeight / 0.9 + 550, winHeight / 0.9 + 250);
	glColor3f(1.0, 0.0, 0.0);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
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
	asteroidTexture = loadBMP_custom("asteroid.bmp");
	camera.setDefaultCamera();
	glFlush();
}


void mouseAction(GLint button, GLint action, GLint x, GLint y) {
if (button == GLUT_LEFT_BUTTON){
	if (action == GLUT_DOWN){
		move = 1;
		xbegin = x;
	}

	else if (action == GLUT_UP) {
		move = 0;
	}
}

}
void mouseMotion(GLint x, GLint y) {
	if (move == 1){
		if (view == 1 && cameraSelect == 1){
			if (option == 1){
				theta = (xbegin - x < 0) ? 1 : -1;
				camera.rotate(1,0,0,theta);
			}

			else if (option == 2){
				theta = (xbegin - x < 0) ? 1 : -1;
				camera.rotate(0,1,0,theta);
			}

			else if (option == 3){
				theta = (xbegin - x < 0) ? 1 : -1;
				camera.rotate(0,0,1,theta);
			}

			//Translate x
			else if (option == 4){
				theta = (xbegin - x < 0) ? 1 : -1;
				//camera.farDist = 15;
				camera.translate(theta,0,0);
			}
			//Translate y
			else if (option == 5){
				theta = (xbegin - x < 0) ? 1 : -1;
				//camera.farDist = 15;
				camera.translate(0,theta,0);
			}
			//Translate z
			else if (option == 6){
				theta = (xbegin - x < 0) ? 1 : -1;
				//camera.farDist = 15;
				camera.translate(0,0,theta);
			}
		}



	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (view == 0){
		draw2D();
	}
	else if (view == 1){
		camera.setProjectionMatrix();
		draw3D();
	}
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
