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
#include <math.h>
#include "solarsystem.hpp"
#include "circle.hpp"

cirlce c;
GLint winWidth = 1200, winHeight = 750;



void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
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

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat r;

	new_object(500,200,300,100,&c);
	printf("%d",c.x2);
	r = sqrt(pow(c.x2-c.x1,2)+pow(c.y2-c.y1,2));
	glColor3f(c.r,c.g,c.b);
	circleMidpointFill(c.x1,c.y1,r);
	glColor3f(c.r,c.g,c.b);

	glFlush();
}

int main(int argc, char** argv) {

	setvbuf(stdout, NULL, _IONBF, 0); //for printing on Eclipse console
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);


	init();

	glutDisplayFunc(draw);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseAction);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//add right click menu
	glutMainLoop();

	return 0;
}
