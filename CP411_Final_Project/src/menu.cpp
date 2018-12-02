/*
 * menu.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"menu.hpp"
extern GLint view, option;
GLint oldView;
void mainMenu(GLint option) {
	view = 0;
    switch (option) {
    case 1:{
    	view = 3;
    }
        break;
    case 2:{
        exit(0);
    }
    }
    glutPostRedisplay();
}

void viewSwitchSubMenu(GLint transOption){
	 option = transOption;

	 //2D
	 if (option == 1){
		 view = 0;
	 }
	 //3D
	 else if (option == 2){
		 view = 1;
	 }
	 //Pause
	 else if(option == 3){
		 if(view != 2){
			 oldView = view;
			 view = 2;
		 }else{
			 view = oldView;
		 }

	 }

	 glutPostRedisplay();
}


void cameraSubMenu(GLint transOption){
	option = transOption;

	glutPostRedisplay();
}
void asteroidSubMenu(GLint transOption){
	switch(option){




	}

}





void Menu(){
	GLint viewSwitch_SubMenu = glutCreateMenu(viewSwitchSubMenu);
	glutAddMenuEntry("2D View", 1);
	glutAddMenuEntry("3D View", 2);
	glutAddMenuEntry("Pause Animation/Resume Animation",3);

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
