/*
 * solarsystem.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: stuua
 */
#include"solarsystem.hpp"

planet2D *sun, *mercury, *venus, *earth, *mars, *jupitor, *saturn, *uranus, *neptune, *pluto;
float posX[10], posY[10], angle[10];
const int SUNX = 600, SUNY = 400;
extern GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture,jupitorTexture;
extern GLuint saturnTexture,uranusTexture, neptuneTexture, plutoTexture;

void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	//Sun

	//texture = loadBMP_custom("sun.bmp");
	sun = new_planet(SUNX,SUNY,53,0,0,sunTexture);
	drawPlanet(sun);

	//Mercury
	mercury = new_planet(0,0,15,100,20,mercuryTexture);
	drawOrbit(SUNX,SUNY,mercury->radiusOrb);

	//Venus
	venus = new_planet(0,0,20,150,30,venusTexture);
	drawOrbit(SUNX + 4,SUNY + 2,venus->radiusOrb);

	//Earth
	earth = new_planet(0,0,23,210,30,earthTexture);
	drawOrbit(SUNX - 6,SUNY + 3,earth->radiusOrb);

	//Mars
	mars = new_planet(0,0,16,250,30,marsTexture);
	drawOrbit(SUNX - 4,SUNY + 2,mars->radiusOrb);

	//Mars
	jupitor = new_planet(0,0,28,340,30,jupitorTexture);
	drawOrbit(SUNX,SUNY,jupitor->radiusOrb);

	animate();


	glFlush();
	glutSwapBuffers();

}

void update(int) {
	//Mercury
	angle[0] = angle[0] + 0.013;
	posX[0] = SUNX + mercury->radiusOrb*cos(angle[0]);
	posY[0] = SUNY + mercury->radiusOrb*sin(angle[0]);

	//Venus
	angle[1] = angle[1] + 0.009;
	posX[1] = (SUNX + 4) + venus->radiusOrb*cos(angle[1]);
	posY[1] = (SUNY + 2) + venus->radiusOrb*sin(angle[1]);

	//Earth
	angle[2] = angle[2] + 0.008;
	posX[2] = (SUNX - 6) + earth->radiusOrb*cos(angle[2]);
	posY[2] = (SUNY + 3) + earth->radiusOrb*sin(angle[2]);

	//Mars
	angle[3] = angle[3] + 0.005;
	posX[3] = (SUNX - 4) + mars->radiusOrb*cos(angle[3]);
	posY[3] = (SUNY + 2) + mars->radiusOrb*sin(angle[3]);

	//Jupitor
	angle[4] = angle[4] + 0.002;
	posX[4] = (SUNX) + jupitor->radiusOrb*cos(angle[4]);
	posY[4] = (SUNY) + jupitor->radiusOrb*sin(angle[4]);

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void animate(void){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glPushMatrix();

	glTranslatef(posX[0], posY[0], 0);
	drawPlanet(mercury);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[1], posY[1], 0);
	drawPlanet(venus);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[2], posY[2], 0);
	drawPlanet(earth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[3], posY[3], 0);
	drawPlanet(mars);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[4], posY[4], 0);
	drawPlanet(jupitor);
	glPopMatrix();

	glutSwapBuffers();

}

