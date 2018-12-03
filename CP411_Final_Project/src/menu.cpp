/*
 * menu.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: erman
 */

#include"menu.hpp"
extern GLint view, option, cameraSelect, orbits, gravFields, lockCamera;
GLint oldView, spawn = 0;

void mainMenu(GLint option) {
    switch (option) {
    case 1:{
    	oldView = view;
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
	cameraSelect = 1;

	glutPostRedisplay();
}

void lockCamSubMenu(GLint transOption){
	option = transOption;

	if (option == 1){
		lockCamera = 0;
	}

	else if (option == 2){
		lockCamera = 1;
	}

	else if (option == 3){
		lockCamera = 2;
	}

	else if (option == 4){
		lockCamera = 3;
	}

	else if (option == 5){
		lockCamera = 4;
	}

	else if (option == 6){
		lockCamera = 5;
	}

	else if (option == 7){
		lockCamera = 6;
	}

	else if (option == 8){
		lockCamera = 7;
	}

	else if (option == 9){
		lockCamera = 8;
	}

	else if (option == 10){
		lockCamera = 9;
	}

	glutPostRedisplay();
}

void asteroidSubMenu(GLint transOption){
	option = transOption;
	if (option == 1){
		spawn = 1;
	}
	glutPostRedisplay();
}

void modelSubMenu(GLint transOption){
	option = transOption;
	//Turn on/off orbits. 0 for on, 1 for off
	if(option == 1){
		if(orbits == 0){
			orbits = 1;
		}else{
			orbits = 0;
		}
	//Turn on/off gravitational fields
	}else if(option == 2){
		if(gravFields == 0){
			gravFields = 1;
		}else{
			gravFields = 0;
		}
	}
}





void Menu(){
	GLint lockCam_SubMenu = glutCreateMenu(lockCamSubMenu);
	glutAddMenuEntry(" Sun ", 1);
	glutAddMenuEntry(" Mercury ", 2);
	glutAddMenuEntry(" Venus ", 3);
	glutAddMenuEntry(" Earth ", 4);
	glutAddMenuEntry(" Mars ", 5);
	glutAddMenuEntry(" Jupitor ", 6);
	glutAddMenuEntry(" Saturn ", 7);
	glutAddMenuEntry(" Uranus ", 8);
	glutAddMenuEntry(" Neptune ", 9);
	glutAddMenuEntry(" Pluto ", 10);

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
	glutAddSubMenu("Lock Camera to Planet",lockCam_SubMenu);

	GLint asteroid_SubMenu = glutCreateMenu(asteroidSubMenu);
	glutAddMenuEntry("Spawn Asteroid", 1);

	GLint model_SubMenu = glutCreateMenu(modelSubMenu);
	glutAddMenuEntry("Orbits (On/Off)", 1);
	glutAddMenuEntry("Gravitational Fields (On/Off)",2);

	glutCreateMenu(mainMenu);
	glutAddMenuEntry(" Restart Animation", 1);
	glutAddSubMenu(" View Switch",viewSwitch_SubMenu);
	glutAddSubMenu(" Camera",camera_SubMenu);
	glutAddSubMenu(" Asteroid Options",asteroid_SubMenu);
	glutAddSubMenu(" Model Options",model_SubMenu);
	glutAddMenuEntry(" Quit", 2);


}
