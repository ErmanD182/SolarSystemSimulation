/*
 * circle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman and stuart
 */

#include"circle.hpp"

planet2D * new_planet(GLint x1, GLint y1, GLint radius, GLint radiusOrb, GLint radiusGrav, GLuint texture){

    planet2D *p = (planet2D *)malloc(sizeof(planet2D));
    p->c.x1 = x1;
    p->c.y1 = y1;
	p->c.radius = radius;
	p->radiusOrb = radiusOrb;
	p->radiusGrav = radiusGrav;
    p->texture = texture;

    return p;
}

void drawPlanet(planet2D *p)
{
    float angle, radian, x, y, xcos, ysin, tx, ty;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, p->texture);
    glColor3f(225,225,225);
    glBegin(GL_POLYGON);

    for (angle=0.0; angle<360.0; angle+=2.0)
    {
    	radian = angle * (3.14/180.0f);

    	xcos = (float)cos(radian);
    	ysin = (float)sin(radian);
    	x = xcos * p->c.radius  + p->c.x1;
    	y = ysin * p->c.radius  + p->c.y1;
    	tx = xcos * 0.5 + 0.5;
    	ty = ysin * 0.5 + 0.5;

    	glTexCoord2f(tx, ty);
    	glVertex2f(x, y);
    }
    glEnd();
    glColor3f(225,225,225);
    glDisable(GL_TEXTURE_2D);

}



void drawOrbit(GLint x, GLint y, GLint radius){
	glColor3f(0.176,0.224,0.5);
	circleMidpoint(x,y,radius);
	glColor3f(0.176,0.224,0.5);
}

void drawField(GLint x, GLint y, GLint radius){
	glColor4f(0.176,0.224,0.5,0.5);
	circleMidpointFill(x,y,radius);
	glColor4f(0.176,0.224,0.5,0.5);
}

void circleMidpointFill(GLint x1, GLint y1, GLint radius){

	GLint p = 1-radius;
	GLint x=0,y=radius;
	circlePlotPointsFill(x1,y1,x,y);
	while(x<y){
		x++;
		if(p<0){
			p +=2*x+1;
		}else{
			y--;
			p += 2*(x-y)+1;
		}
		circlePlotPointsFill(x1,y1,x,y);
	}
}

void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y) {
	glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc + y, yc - x);
    glEnd();
}

void setPixel(GLint x, GLint y) {
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void circlePlotPoints(const GLint& xc, const GLint& yc, const GLint& x, const GLint& y) {
	setPixel(xc+ x, yc+ y);
	setPixel(xc-x, yc+ y);
	setPixel(xc+ x, yc- y);
	setPixel(xc-x, yc-y);
	setPixel(xc+ y, yc+ x);
	setPixel(xc-y, yc+ x);
	setPixel(xc+ y, yc- x);
	setPixel(xc-y, yc-x);
}

void circleMidpoint(GLint xc, GLint yc, GLfloat r) {
	GLint p = 1 - r;
		GLint x = 0, y = r;
		circlePlotPoints(xc, yc, x, y);
		while (x < y) {
				x++;
				if (p < 0){
					p += 2 * x + 1;
				}else {
					y--;
					p += 2 * (x - y) + 1;
				}
				circlePlotPoints(xc, yc, x, y);
			}
}



//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
//This code was used from this website to load our textures to be used with our objects
GLuint loadBMP_custom(const char * imagepath){//For 2D Objects

	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE * file = fopen(imagepath,"rb");
	if (!file){
		printf("Image could not be opened\n");
		return 0;
	}

	if (fread(header, 1, 54, file)!= 54){ // If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}

	if ( header[0]!='B' || header[1]!='M' ){
	    printf("Not a correct BMP file\n");
	    return 0;
	}


	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);


	if (imageSize==0){
		imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	}
	if (dataPos==0){
		dataPos=54; // The BMP header is done that way
	}

	data = new unsigned char [imageSize];

	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return textureID;

}
