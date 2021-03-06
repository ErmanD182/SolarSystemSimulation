/*
 * solarsystem.hpp
 *
 *  Created on: Nov 27, 2018
 *      //Erman Dinsel and Stuart isley
		//160364040		   160757220
 */

#ifndef SOLARSYSTEM_HPP_
#define SOLARSYSTEM_HPP_

#include "circle.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include"Sphere.hpp"
#include"Camera.hpp"
#include <time.h>


void draw2D(void);
void draw3D(void);
void update(int);
void animate(void);
void lockCam(void);
void spawnAsteroid(void);



#endif /* SOLARSYSTEM_HPP_ */
