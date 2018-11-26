/*
 * main.cpp
 *
 *  Created on: Nov 26, 2018
 *      Author: erman is a stupid idoit...
 */
#include <GL/gl.h>
#include <GL/glut.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640, 480, 0.0);
    glutCreateWindow("SolarSyetem");
    glColor3f(1.0, 0.0, 0.0);
    glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc,argv);

	init();
	glutMainLoop();
}



