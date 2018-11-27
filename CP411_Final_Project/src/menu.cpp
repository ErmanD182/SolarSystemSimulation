/*
 * menu.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"menu.hpp"


void mainMenu(GLint option) {
    switch (option) {
    case 1:{
    	//restartAnimation();
    }
        break;
    case 2:{
        exit(0);
    }
    }
    glutPostRedisplay();
}

void viewSwitchSubMenu(GLint option){
	 switch (option) {
	 case 1:{
		 //2d view
	 }
	 break;
	 case 2:{
		 //3dview
	 }
	 break;
	 }

	 glutPostRedisplay();
}


void cameraSubMenu(GLint option){
	switch(option){






	}

}
void asteroidSubMenu(GLint option){
	switch(option){




	}

}





void Menu(){
	GLint viewSwitch_SubMenu = glutCreateMenu(viewSwitchSubMenu);
	glutAddMenuEntry("2D View", 1);
	glutAddMenuEntry("3D View", 2);

	GLint camera_SubMenu = glutCreateMenu(cameraSubMenu);
	glutAddMenuEntry("Rotate x ", 1);
	glutAddMenuEntry("Rotate y ", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x ", 4);
	glutAddMenuEntry("Translate y ", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint asteroid_SubMenu = glutCreateMenu(asteroidSubMenu);
	glutAddMenuEntry("Spawn Asteroid", 1);


	glutCreateMenu(mainMenu);
	glutAddMenuEntry(" Restart Animation", 1);
	glutAddSubMenu(" View Switch",viewSwitch_SubMenu);
	glutAddSubMenu(" Camera",camera_SubMenu);
	glutAddSubMenu(" Asteroid Options",asteroid_SubMenu);
	glutAddMenuEntry(" Quit", 2);


}
