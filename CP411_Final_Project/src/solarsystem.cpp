/*
 * solarsystem.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: stuua
 */
#include"solarsystem.hpp"

planet2D *sun, *mercury, *venus, *earth, *mars, *jupitor, *saturn, *uranus, *neptune, *pluto;
float posX[9], posY[9], angle[9], posX3D[9], posY3D[9], angle3D[9], asteroidX = 100, asteroidY = 0, random;
const int SUNX = 600, SUNY = 400;
extern GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture,jupitorTexture;
extern GLuint saturnTexture, uranusTexture, neptuneTexture, plutoTexture, asteroidTexture;
extern GLint view, orbits, gravFields, winWidth, winHeight, lockCamera;
extern Camera camera;
extern GLint oldView, spawn;
extern GLfloat speed;
GLfloat rx,ry,rz;
Sphere *sun3D = new Sphere(), *mercury3D = new Sphere(), *venus3D = new Sphere(), *earth3D = new Sphere();
Sphere *mars3D = new Sphere(), *jupitor3D = new Sphere(), *saturn3D = new Sphere(), *uranus3D = new Sphere();
Sphere *neptune3D = new Sphere(), *pluto3D = new Sphere(), *asteroid = new Sphere();;

void spawnAsteroid(void){
	srand((unsigned int)time(NULL));
	random = ((float)rand()/(float)(RAND_MAX)) * 0.05;

	glPushMatrix();
	glTranslatef(asteroidX, asteroidY, 0);
	glTranslatef(asteroidX, asteroidY, 0);
	rx = asteroid->getMC().mat[0][1];
	ry = asteroid->getMC().mat[1][1];
	rz =asteroid->getMC().mat[2][1];
	asteroid->rotateMC(rx,ry,rz,1);
	asteroid->draw();
	glPopMatrix();
}


void draw2D(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glClearColor(0.0, 0.0, 0.0, 1.0);

		//Sun
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
		jupitor = new_planet(0,0,30,340,40,jupitorTexture);


		//Saturn
		saturn = new_planet(0,0,25,420,30,saturnTexture);


		//Uranus
		uranus = new_planet(0,0,22,500,30,uranusTexture);


		//Neptune
		neptune = new_planet(0,0,21.5,570,30,neptuneTexture);


		//Pluto
		pluto = new_planet(0,0,12,630,20,plutoTexture);


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

void draw3D(void){
sun3D->textureID = sunTexture;
sun3D->radius = 2;

mercury3D->textureID = mercuryTexture;
mercury3D->radius = 0.5;


venus3D->textureID = venusTexture;
venus3D->radius = 0.6;

earth3D->textureID = earthTexture;
earth3D->radius = 0.9;

mars3D->textureID = marsTexture;
mars3D->radius = 0.58;

jupitor3D->textureID = jupitorTexture;
jupitor3D->radius = 1.5;

saturn3D->textureID = saturnTexture;
saturn3D->radius = 1.3;

uranus3D->textureID = uranusTexture;
uranus3D->radius = 1.2;

neptune3D->textureID = neptuneTexture;
neptune3D->radius = 1.3;

pluto3D->textureID = plutoTexture;
pluto3D->radius = 0.3;

asteroid->textureID = asteroidTexture;
asteroid->radius = 0.5;


if (orbits == 0){
	drawOrbit(0,0,4);
	drawOrbit(0,0,8);
	drawOrbit(0,0,14);
	drawOrbit(0,0,22);
	drawOrbit(0,0,36);
	drawOrbit(0,0,44);

	drawOrbit(0,0,56);
	drawOrbit(0,0,68);
	drawOrbit(0,0,80);
}




lockCam();
animate();
//spawn = 0;
}

void update(int) {

	if(view == 3){//RESET
			for(int i =0;i<9;i++){
				posX[i] = 0;
				posY[i] = 0;
				angle[i] = 0;

				posX3D[i] = 0;
				posY3D[i] = 0;
				angle3D[i] = 0;
			}
			view = oldView;
		}
		else if(view==0){//DRAW 2D

		//Mercury
		angle[0] = angle[0] + 0.013*speed;
		posX[0] = SUNX + mercury->radiusOrb*cos(angle[0]);
		posY[0] = SUNY + mercury->radiusOrb*sin(angle[0]);

		//Venus
		angle[1] = angle[1] + 0.009*speed;
		posX[1] = (SUNX + 4) + venus->radiusOrb*cos(angle[1]);
		posY[1] = (SUNY + 2) + venus->radiusOrb*sin(angle[1]);

		//Earth
		angle[2] = angle[2] + 0.008*speed;
		posX[2] = (SUNX - 6) + earth->radiusOrb*cos(angle[2]);
		posY[2] = (SUNY + 3) + earth->radiusOrb*sin(angle[2]);

		//Mars
		angle[3] = angle[3] + 0.005*speed;
		posX[3] = (SUNX - 4) + mars->radiusOrb*cos(angle[3]);
		posY[3] = (SUNY + 2) + mars->radiusOrb*sin(angle[3]);

		//Jupitor
		angle[4] = angle[4] + 0.0023*speed;
		posX[4] = (SUNX) + jupitor->radiusOrb*cos(angle[4]);
		posY[4] = (SUNY) + jupitor->radiusOrb*sin(angle[4]);

		//Saturn
		angle[5] = angle[5] + 0.002*speed;
		posX[5] = (SUNX + 3) + saturn->radiusOrb*cos(angle[5]);
		posY[5] = (SUNY + 2) + saturn->radiusOrb*sin(angle[5]);

		//Uranus
		angle[6] = angle[6] + 0.0018*speed;
		posX[6] = (SUNX - 2) + uranus->radiusOrb*cos(angle[6]);
		posY[6] = (SUNY + 1) + uranus->radiusOrb*sin(angle[6]);

		//Uranus
		angle[7] = angle[7] + 0.0016*speed;
		posX[7] = (SUNX - 4) + neptune->radiusOrb*cos(angle[7]);
		posY[7] = (SUNY + 2) + neptune->radiusOrb*sin(angle[7]);

		//Pluto
		angle[8] = angle[8] + 0.0012*speed;
		posX[8] = (SUNX + 13) + pluto->radiusOrb*cos(angle[8]);
		posY[8] = (SUNY + 5) + pluto->radiusOrb*sin(angle[8]);
		}else if(view == 1){
			//Mercury
			angle3D[0] = angle3D[0] + 0.013*speed;
			posX3D[0] = 2*cos(angle3D[0]);
			posY3D[0] = 2*sin(angle3D[0]);

			//Venus
			angle3D[1] = angle3D[1] + 0.009*speed;
			posX3D[1] = 4*cos(angle3D[1]);
			posY3D[1] = 4*sin(angle3D[1]);

			//Earth
			angle3D[2] = angle3D[2] + 0.008*speed;
			posX3D[2] = 7*cos(angle3D[2]);
			posY3D[2] = 7*sin(angle3D[2]);

			//Mars
			angle3D[3] = angle3D[3] + 0.005*speed;
			posX3D[3] = 11*cos(angle3D[3]);
			posY3D[3] = 11*sin(angle3D[3]);

			//Jupitor
			angle3D[4] = angle3D[4] + 0.0023*speed;
			posX3D[4] = 18*cos(angle3D[4]);
			posY3D[4] = 18*sin(angle3D[4]);

			//Saturn
			angle3D[5] = angle3D[5] + 0.002*speed;
			posX3D[5] = 22*cos(angle3D[5]);
			posY3D[5] = 22*sin(angle3D[5]);

			//Uranus
			angle3D[6] = angle3D[6] + 0.0018*speed;
			posX3D[6] = 28*cos(angle3D[6]);
			posY3D[6] = 28*sin(angle3D[6]);

			//Neptune
			angle3D[7] = angle3D[7] + 0.0016*speed;
			posX3D[7] = 34*cos(angle3D[7]);
			posY3D[7] = 34*sin(angle3D[7]);

			//Pluto
			angle3D[8] = angle3D[8] + 0.0012*speed;
			posX3D[8] = 40*cos(angle3D[8]);
			posY3D[8] = 40*sin(angle3D[8]);

			if (spawn == 1){
				asteroidX = asteroidX - 0.1;
				asteroidY = asteroidY + random;
			}
		}
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);

}

void animate(void){

	if (view == 0){
		glDisable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
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
	}

	else if (view == 1){
		//glEnable(GL_LIGHTING);
		//glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_CULL_FACE);
		glEnable(GL_NORMALIZE);

		//Enable material properties for lighting
		//glEnable(GL_COLOR_MATERIAL);
		//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glColor3f(225,225,225);

		glPushMatrix();
		glTranslatef(posX3D[0], posY3D[0], 0);
		glTranslatef(posX3D[0], posY3D[0], 0);
		rx = mercury3D->getMC().mat[0][1];
		ry = mercury3D->getMC().mat[1][1];
		rz =mercury3D->getMC().mat[2][1];
		mercury3D->rotateMC(rx,ry,rz,2);
		mercury3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[1], posY3D[1], 0);
		glTranslatef(posX3D[1], posY3D[1], 0);
		rx = venus3D->getMC().mat[0][1];
		ry = venus3D->getMC().mat[1][1];
		rz =venus3D->getMC().mat[2][1];
		venus3D->rotateMC(rx,ry,rz,2);
		venus3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[2], posY3D[2], 0);
		glTranslatef(posX3D[2], posY3D[2], 0);
		rx = earth3D->getMC().mat[0][1];
		ry = earth3D->getMC().mat[1][1];
		rz =earth3D->getMC().mat[2][1];
		earth3D->rotateMC(rx,ry,rz,2);
		earth3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[3], posY3D[3], 0);
		glTranslatef(posX3D[3], posY3D[3], 0);
		rx = mars3D->getMC().mat[0][1];
		ry = mars3D->getMC().mat[1][1];
		rz =mars3D->getMC().mat[2][1];
		mars3D->rotateMC(rx,ry,rz,2);
		mars3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[4], posY3D[4], 0);
		glTranslatef(posX3D[4], posY3D[4], 0);
		rx = jupitor3D->getMC().mat[0][1];
		ry = jupitor3D->getMC().mat[1][1];
		rz =jupitor3D->getMC().mat[2][1];
		jupitor3D->rotateMC(rx,ry,rz,2);
		jupitor3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[5], posY3D[5], 0);
		glTranslatef(posX3D[5], posY3D[5], 0);
		rx = saturn3D->getMC().mat[0][1];
		ry = saturn3D->getMC().mat[1][1];
		rz =saturn3D->getMC().mat[2][1];
		saturn3D->rotateMC(rx,ry,rz,2);
		saturn3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[6], posY3D[6], 0);
		glTranslatef(posX3D[6], posY3D[6], 0);
		rx = uranus3D->getMC().mat[0][1];
		ry = uranus3D->getMC().mat[1][1];
		rz =uranus3D->getMC().mat[2][1];
		uranus3D->rotateMC(rx,ry,rz,2);
		uranus3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[7], posY3D[7], 0);
		glTranslatef(posX3D[7], posY3D[7], 0);
		rx = neptune3D->getMC().mat[0][1];
		ry = neptune3D->getMC().mat[1][1];
		rz =neptune3D->getMC().mat[2][1];
		neptune3D->rotateMC(rx,ry,rz,2);
		neptune3D->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX3D[8], posY3D[8], 0);
		glTranslatef(posX3D[8], posY3D[8], 0);
		rx = pluto3D->getMC().mat[0][1];
		ry = pluto3D->getMC().mat[1][1];
		rz =pluto3D->getMC().mat[2][1];
		pluto3D->rotateMC(rx,ry,rz,2);
		pluto3D->draw();
		glPopMatrix();

		if (spawn == 1){
			spawnAsteroid();
		}

		sun3D->draw();
	}

	glutSwapBuffers();
}

void lockCam(void){
	Point p;
	if (lockCamera != 0){
		camera.viewAngle = 60;
	}
	else{
		camera.viewAngle = 70;
	}

	if (lockCamera == 0){
		p.set(0,0,0);
	}
	else if (lockCamera == 1){
		p.set(posX3D[0],posY3D[0],0);
	}

	else if (lockCamera == 2){
		p.set(posX3D[1],posY3D[1],0);
	}

	else if (lockCamera == 3){
		p.set(posX3D[2],posY3D[2],0);
	}

	else if (lockCamera == 4){
		p.set(posX3D[3],posY3D[3],0);
	}

	else if (lockCamera == 5){
			p.set(posX3D[4],posY3D[4],0);
		}

	else if (lockCamera == 6){
			p.set(posX3D[5],posY3D[5],0);
		}

	else if (lockCamera == 7){
			p.set(posX3D[6],posY3D[6],0);
		}

	else if (lockCamera == 8){
			p.set(posX3D[7],posY3D[7],0);
		}

	else if (lockCamera == 9){
			p.set(posX3D[8],posY3D[8],0);
		}

	camera.ref = p;

}

