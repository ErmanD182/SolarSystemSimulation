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


circle *cir;
planet2D *sun, *mercury;
GLint winWidth = 1200, winHeight = 750;
GLuint texture;



void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glFlush();

}

void mouseAction(GLint button, GLint action, GLint x, GLint y) {

}

void mouseMotion(GLint x, GLint y) {

}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	//Sun

	texture = loadBMP_custom("sun.bmp");
	sun = new_planet(600,400,53, 0, 0, texture);
	drawPlanet(sun);

	//Mercury
	texture = loadBMP_custom("mercury.bmp");
	mercury = new_planet(700,400,15, 100, 20, texture);
	drawPlanet(mercury);


	//venus orbit
	//circleMidpoint(600,400,130);


	glFlush();
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

	glutDisplayFunc(draw);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseAction);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//add right click menu
	glutMainLoop();

	return 0;
}
