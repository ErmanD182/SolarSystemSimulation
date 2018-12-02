/*
 * solarsystem.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: stuua
 */
#include"solarsystem.hpp"

planet2D *sun, *mercury, *venus, *earth, *mars, *jupitor, *saturn, *uranus, *neptune, *pluto;
float posX[9], posY[9], angle[9];
const int SUNX = 600, SUNY = 400;
extern GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture,jupitorTexture;
extern GLuint saturnTexture, uranusTexture, neptuneTexture, plutoTexture;
extern GLint view,orbits,gravFields;

void draw(void){
	//Sun

	//texture = loadBMP_custom("sun.bmp");
	sun = new_planet(SUNX,SUNY,53,0,0,sunTexture);
	drawPlanet(sun);

	//Mercury
	mercury = new_planet(0,0,15,100,20,mercuryTexture);


	//Venus
	venus = new_planet(0,0,20,150,30,venusTexture);


	//Earth
	earth = new_planet(0,0,21,210,30,earthTexture);


	//Mars
	mars = new_planet(0,0,16,250,30,marsTexture);


	//Jupitor
	jupitor = new_planet(0,0,30,340,30,jupitorTexture);


	//Saturn
	saturn = new_planet(0,0,25,420,30,saturnTexture);


	//Uranus
	uranus = new_planet(0,0,22,500,30,uranusTexture);


	//Neptune
	neptune = new_planet(0,0,21.5,570,30,neptuneTexture);


	//Pluto
	pluto = new_planet(0,0,12,630,30,plutoTexture);


	if(orbits == 0){
		drawOrbit(SUNX,SUNY,mercury->radiusOrb);
		drawOrbit(SUNX + 4,SUNY + 2,venus->radiusOrb);
		drawOrbit(SUNX - 6,SUNY + 3,earth->radiusOrb);
		drawOrbit(SUNX - 4,SUNY + 2,mars->radiusOrb);
		drawOrbit(SUNX,SUNY,jupitor->radiusOrb);
		drawOrbit(SUNX + 3,SUNY + 2, saturn->radiusOrb);
		drawOrbit(SUNX - 2,SUNY + 1, uranus->radiusOrb);
		drawOrbit(SUNX - 4,SUNY + 2, neptune->radiusOrb);
		drawOrbit(SUNX + 13,SUNY + 5, pluto->radiusOrb);

	}



	animate();

}

void update(int) {
	if(view == 3){//RESET
		for(int i =0;i<9;i++){
			posX[i] = 0;
			posY[i] = 0;
			angle[i] = 0;
		}
		view = 0;
	}
	else if(view==0){//DRAW 2D

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
	angle[4] = angle[4] + 0.0023;
	posX[4] = (SUNX) + jupitor->radiusOrb*cos(angle[4]);
	posY[4] = (SUNY) + jupitor->radiusOrb*sin(angle[4]);

	//Saturn
	angle[5] = angle[5] + 0.002;
	posX[5] = (SUNX + 3) + saturn->radiusOrb*cos(angle[5]);
	posY[5] = (SUNY + 2) + saturn->radiusOrb*sin(angle[5]);

	//Uranus
	angle[6] = angle[6] + 0.0018;
	posX[6] = (SUNX - 2) + uranus->radiusOrb*cos(angle[6]);
	posY[6] = (SUNY + 1) + uranus->radiusOrb*sin(angle[6]);

	//Uranus
	angle[7] = angle[7] + 0.0016;
	posX[7] = (SUNX - 4) + neptune->radiusOrb*cos(angle[7]);
	posY[7] = (SUNY + 2) + neptune->radiusOrb*sin(angle[7]);

	//Pluto
	angle[8] = angle[8] + 0.0012;
	posX[8] = (SUNX + 13) + pluto->radiusOrb*cos(angle[8]);
	posY[8] = (SUNY + 5) + pluto->radiusOrb*sin(angle[8]);
	}else if(view == 1){

	}

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void animate(void){
	if(gravFields == 0){
		drawField(posX[0],posY[0],mercury->radiusGrav);
		drawField(posX[1],posY[1],venus->radiusGrav);
		drawField(posX[2],posY[2],earth->radiusGrav);
		drawField(posX[3],posY[3],mars->radiusGrav);
		drawField(posX[4],posY[4],jupitor->radiusGrav);
		drawField(posX[5],posY[5],saturn->radiusGrav);
		drawField(posX[6],posY[6],uranus->radiusGrav);
		drawField(posX[7],posY[7],neptune->radiusGrav);
		drawField(posX[8],posY[8],pluto->radiusGrav);
	}

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

	glPushMatrix();
	glTranslatef(posX[5], posY[5], 0);
	drawPlanet(saturn);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[6], posY[6], 0);
	drawPlanet(uranus);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[7], posY[7], 0);
	drawPlanet(neptune);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX[8], posY[8], 0);
	drawPlanet(pluto);
	glPopMatrix();

	glutSwapBuffers();

}

