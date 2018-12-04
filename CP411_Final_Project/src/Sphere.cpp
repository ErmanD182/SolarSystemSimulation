//Erman Dinsel and Stuart isley
//160364040		   160757220

#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 1.0;
	mode = MODE_TEXTURE;
	textureID = 0;
	splices = 50;
	stacks = 50;
	quad = gluNewQuadric();
}

Sphere::~Sphere() {
	gluDeleteQuadric(quad);
}

void Sphere::draw() {
		if (mode == MODE_TEXTURE) {
		quad = gluNewQuadric();
		gluQuadricTexture(this->quad, GL_TRUE);
		gluQuadricOrientation(this->quad, GLU_OUTSIDE);
		gluQuadricNormals(this->quad, GLU_SMOOTH);

		glPushMatrix();
		ctmMultiply();
		glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, textureID);
		gluSphere(this->quad, radius, 50, 50);
		glDisable(GL_TEXTURE_2D);
		gluDeleteQuadric(this->quad);
		glPopMatrix();

	}


}


void Sphere::drawField3D(){
	glColor4f(0.176,0.224,0.5,0.5);
	gluSphere(this->quad,radius,50,50);
	glColor4f(0.176,0.224,0.5,0.5);
}
