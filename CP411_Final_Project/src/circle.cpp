/*
 * circle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"circle.hpp"

circle * new_object(GLint x1, GLint y1, GLint x2,  GLint y2){
	circle *p = (circle *) malloc(sizeof(circle));
    p->x1 = x1;
    p->y1 = y1;
    p->x2 = x2;
    p->y2 = y2;


    p->r = 0.0;
    p->g = 0.0;
    p->b = 0.0;

    p->radius = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    return p;
}

void drawCircleOutline(circle *c, GLuint texture)
{
    float angle, radian, x, y, xcos, ysin, tx, ty;       // values needed by drawCircleOutline

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_POLYGON);

    for (angle=0.0; angle<360.0; angle+=2.0)
    {
    	radian = angle * (3.14/180.0f);

    	xcos = (float)cos(radian);
    	ysin = (float)sin(radian);
    	x = xcos * c->radius  + c->x1;
    	y = ysin * c->radius  + c->y1;
    	tx = xcos * 0.5 + 0.5;
    	ty = ysin * 0.5 + 0.5;

    	glTexCoord2f(tx, ty);
    	glVertex2f(x, y);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}


void circlePlotPointsFill(GLint xc, GLint yc, GLint x, GLint y, GLuint texture) {
	glLineWidth(2.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(xc, yc);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc + y, yc - x);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void circleMidpointFill(GLint xc, GLint yc, GLfloat r, GLuint texture) {
	GLint p = 1 - r;
	GLint x = 0, y = r;
	circlePlotPointsFill(xc, yc, x, y, texture);
	while (x < y) {
			x++;
			if (p < 0){
				p += 2 * x + 1;
			}else {
				y--;
				p += 2 * (x - y) + 1;
			}
			circlePlotPointsFill(xc, yc, x, y, texture);
		}
}


GLuint loadBMP_custom(const char * imagepath){
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
