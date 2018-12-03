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

	if (mode == MODE_WIRE) {
		glPushMatrix();
		this->ctmMultiply();
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		gluSphere(this->quad, radius, splices, stacks);
		glPopMatrix();
	}

	else if (mode == MODE_TEXTURE) {
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

