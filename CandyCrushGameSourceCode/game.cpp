//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include "drawGrid.h"
#include<sstream>  
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"DrawCircle.h"
#include"Shapes.h"
#include"DisplayScreen.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include"drawSquare.h"
#include"drawTriangle.h"
#include"drawRoundRectangle.h"
#include "drawPillar.h"
#include "AppStructConsts.h"
#include "ProjectManager.h"
using namespace std;

ProjectManager prjctMgr;



void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void drawCongratulations()
{

     DrawRoundRect(380, 300, 250, 150, colors[GREEN], 30);
     DrawString(435, 365, "Congratulations", colors[WHITE]);

     DrawRoundRect(280, 150, 500, 50, colors[GREEN], 30);
     DrawString(425, 170, "Move To Next Level", colors[WHITE]);

}

void GameDisplay()/**/{
     stringstream  DisplayscoreFetch;//carry int type of score 
     string Displayscore;//carry string type of score
     stringstream  DisplayLevelFetch;//carry int type of level nmbr
     string DisplayLevel;//carry string type of level nmbr

	glClearColor(0.2/*Red Component*/, 0.3,	//148.0/255/*Green Component*/,
			0.6/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


    if (prjctMgr.getLevelUpgrade())
    {
         prjctMgr.setcurrentDisplayedPage(FRAME_CONGRATULATIONS);
         drawCongratulations();
         
    }
    else
    {

         //Display Score
         DisplayScreen displayScreenObj;

         //player name


         DrawString(10, 650, "Player Name", colors[WHITE]);
         DrawString(200, 650, prjctMgr.getScreenObj()->getPlayerName(), colors[WHITE]);
         //score   
         DrawString(10, 600, "score", colors[WHITE]);
         DisplayscoreFetch << prjctMgr.getScreenObj()->getScore();
         DisplayscoreFetch >> Displayscore;
         DrawString(200, 600, Displayscore, colors[WHITE]);
         //hint box
         DrawString(10, 550, "Hint Box", colors[WHITE]);
         DrawRoundRect(200, 550, 50, 25, colors[GREEN], 0);

         //level

         DisplayLevelFetch << prjctMgr.getScreenObj()->getLevelNmbr();
         DisplayLevelFetch >> DisplayLevel;
         DrawString(700, 650, "Level", colors[WHITE]);

         DrawString(800, 650, DisplayLevel, colors[WHITE]);
         //progrees line
         DrawString(700, 600, "Progress Line", colors[WHITE]);
         DrawLine(500, 550, 1000, 550, 50, colors[BLACK]);//upper line
         DrawLine(500, 535, 1000, 535, 50, colors[BLACK]);//bottom 
         DrawLine(500, 550, 500, 535, 50, colors[BLACK]);//left line

         DrawLine(1000, 550, 1000, 535, 50, colors[BLACK]);//RIGHT line


                                                           //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
         DrawLine(0, 440, 1024, 440, 50, colors[CHOCOLATE]);
         DrawLine(0, 450, 1024, 450, 50, colors[BLANCHED_ALMOND]);

         DrawRoundRect(10, 460, 100, 50, colors[GREEN], 0);
         DrawString(30, 475, "Pause", colors[WHITE]);

         DrawRoundRect(120, 460, 100, 50, colors[GREEN], 0);
         DrawString(150, 475, "Save", colors[WHITE]);

         prjctMgr.DisplayProgressBar();
         drawGrid GridObj;
         GridObj.DisplayGrid();
         prjctMgr.DisplayShapes();
         prjctMgr.IsGroupFormedInRow();
         prjctMgr.IsGroupFormedInColumn();
         prjctMgr.setIskeyPressed(false);
         prjctMgr.DrawRectangleOnSelectedCell();
         prjctMgr.DisplaySelectedShape();
         if (prjctMgr.gethintchk())
         {
              prjctMgr.WhenHintButtonPressed();
         }

    }
                                   
    
    glutSwapBuffers(); // do not modify this line..
}

//menu
void drawMenu()
{
     glClearColor(0.2/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
          0.3/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
     glClear(GL_COLOR_BUFFER_BIT); //Update the colors
     DrawRoundRect(300, 550,400,50, colors[GREEN], 0);
     DrawString(440, 565, "Start Game", colors[WHITE]);

     DrawRoundRect(300, 450, 400,50, colors[GREEN], 0);
     DrawString(425, 465, "Resume Game", colors[WHITE]);

     DrawRoundRect(300, 350, 400,50, colors[GREEN], 0);
     DrawString(435, 365, "Load Game", colors[WHITE]);

     DrawRoundRect(300, 250, 400, 50, colors[GREEN], 0);
     DrawString(420, 265, "Select Game Mode", colors[WHITE]);

     DrawRoundRect(300, 150, 400, 50, colors[GREEN], 0);
     DrawString(435, 165, "Highest score", colors[WHITE]);

     DrawRoundRect(300, 50, 400, 50, colors[GREEN], 0);
     DrawString(450, 65, "Settings", colors[WHITE]);

     glutSwapBuffers();
}

//settings
void drawSetting()
{
     glClearColor(0.2/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
          0.3/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
     glClear(GL_COLOR_BUFFER_BIT); //Update the colors
     DrawRoundRect(180,550, 100,125, colors[GREEN], 0);
     DrawString(200,610, "Music", colors[WHITE]);

     DrawRoundRect(480, 590,60,50, colors[GREEN], 0);
     DrawString(490,610, "ON", colors[WHITE]);

     DrawRoundRect(570, 590, 60, 50, colors[GREEN], 0);
     DrawString(580, 610, "OFF", colors[WHITE]);

     DrawRoundRect(180, 400, 100, 125, colors[GREEN], 0);
     DrawString(185,455,"Difficulty", colors[WHITE]);

     DrawRoundRect(480, 440,100, 50, colors[GREEN], 0);
     DrawString(505,455, "High", colors[WHITE]);

     DrawRoundRect(630, 440, 100, 50, colors[GREEN], 0);
     DrawString(660, 455, "Low", colors[WHITE]);
    
     DrawRoundRect(780, 440, 100, 50, colors[GREEN], 0);
     DrawString(790, 455, "Medium", colors[WHITE]);

     DrawRoundRect(300, 300, 400, 50, colors[GREEN], 0);
     DrawString(460, 315, "How to Play", colors[WHITE]);

     DrawRoundRect(300, 200, 400, 50, colors[GREEN], 0);
     DrawString(460, 215, "Player Profile", colors[WHITE]);

     DrawRoundRect(300, 100, 400, 50, colors[GREEN], 0);
     DrawString(460, 115, "Back To Menu", colors[WHITE]);

     glutSwapBuffers();
}

//How to Play
void drawHowToPlay()
{
     glClearColor(0.2/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
          0.3/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
     glClear(GL_COLOR_BUFFER_BIT); //Update the colors

     DrawRoundRect(225,150,650,500, colors[GREEN], 0);
     DrawString(270,570, "*", colors[WHITE]);
     DrawString(285, 570, "Make chain shapes in a similar Row or column", colors[WHITE]);

     DrawString(270,520, "*", colors[WHITE]);
     DrawString(285,520, "Use mouse left button to swipe shape", colors[WHITE]);

     DrawString(270,470, "*", colors[WHITE]);
     DrawString(285,470, "Joining more than Three  shapes reward Bonus points", colors[WHITE]);

     DrawString(270,420, "*", colors[WHITE]);
     DrawString(285,420, "Required points much be acheived before going to next level", colors[WHITE]);

     DrawString(270,370, "*", colors[WHITE]);
     DrawString(285,370, "You have to fill the progress line to win", colors[WHITE]);

     DrawString(270,320, "*", colors[WHITE]);
     DrawString(285,320, "You can also use hint button", colors[WHITE]);

     DrawString(270, 270, "*", colors[WHITE]);
     DrawString(285, 270, "increase in level increase difficulty", colors[WHITE]);

     DrawString(270, 220, "*", colors[WHITE]);
     DrawString(285, 220, "You can only use mouse left button to drag", colors[WHITE]);

     DrawString(270, 170, "*", colors[WHITE]);
     DrawString(285, 170, "Moving diagnal s not allowed", colors[WHITE]);

     DrawRoundRect(450,50,200, 50, colors[GREEN], 30);
     DrawString(475,70, "Back To Menu", colors[WHITE]);

     glutSwapBuffers();
}

//Game Mode
void drawGameMode()
{
     glClearColor(0.2/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
          0.3/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
     glClear(GL_COLOR_BUFFER_BIT); //Update the colors

     DrawRoundRect(380,400,250,150, colors[GREEN], 30);
     DrawString(445,465, "Normal Mode", colors[WHITE]);

     DrawRoundRect(380, 150,250, 150, colors[GREEN], 30);
     DrawString(435, 215, "Time Trial Mode", colors[WHITE]);

     glutSwapBuffers();
}

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
         

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
         prjctMgr.setIskeyPressed(!prjctMgr.getIskeyPressed());

	}
	glutPostRedisplay();

}
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y)
{

     prjctMgr.setmCurrentMouseX(x);
     prjctMgr.setmCurrentMouseY(670 - y);
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;



	glutPostRedisplay();
}



void MouseClicked(int button, int state, int x, int y) {
     
     y = 670 - y; 
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{

          if(prjctMgr.getcurrentDisplayedPage() == FRAME_MENU)
          {
               //from menu to start game
               if ((x >300 && x <695) && (y<600 && y>553))
               {
                    glutDisplayFunc(GameDisplay);
                    prjctMgr.setcurrentDisplayedPage(FRAME_GAME_DISPLAY);
               }
               //from menu to  resume game
               else if ((x >305 && x <700) && (y<497 && y>455))
               {
                    glutDisplayFunc(GameDisplay);
                    prjctMgr.setcurrentDisplayedPage(FRAME_GAME_DISPLAY);
                   
               }
               //from menu to  load game
               else if ((x >304 && x <695) && (y<396 && y>355))
               {
                    //glutDisplayFunc(drawSetting);
                    //currentDisplayedPage = FRAME_LOAD_GAME;
               }
               //from menu to  select game mode 
               else if ((x >304 && x <700) && (y<300 && y>255))
               {
                    glutDisplayFunc(drawGameMode);
                    prjctMgr.setcurrentDisplayedPage(FRAME_GAME_MODE);
               }
               //from menu to  heighst score
               else if ((x >302 && x <700) && (y<200 && y>155))
               {
                    //glutDisplayFunc(drawSetting);
                    //currentDisplayedPage = FRAME_HEIGHST_SCORE;
               }
               //from menu to  setting
               else if ((x >304 && x <700) && (y<100 && y>55))
               {
                    glutDisplayFunc(drawSetting);
                    prjctMgr.setcurrentDisplayedPage(FRAME_SETTINGS);
               }
               
          }
          else if(prjctMgr.getcurrentDisplayedPage() == FRAME_GAME_DISPLAY)
          {
               
               //from pause(game display) to menu
                if ((x >14 && x <110) && (y<506 && y>465))
                {
                     glutDisplayFunc(drawMenu);
                     prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
                }
                //save button in game display
                else if ((x >123 && x <216) && (y<506 && y>465))
                {
                     glutDisplayFunc(drawMenu);
                     prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
                }
                //cursor on grid
                
                else if ((x > 295 && x < 650) && (y < 400 && y>50))
                {
                     if (state == GLUT_DOWN)
                     {
                          prjctMgr.FirstSelectedCellNumber(x, y);
                          prjctMgr.setisMouseLeftButtonDown(true);
                          
                     }
                     if(state == GLUT_UP)
                     {
                          prjctMgr.SecondSelectedCellNumber(x, y);
                          prjctMgr.setisMouseLeftButtonDown(false);
                          //prjctMgr.IsGroupFormedInRow();
                     }                   

                }
                else if ((x > 202 && x < 247) && (y < 574 && y>554))
                {
                     if(state==GLUT_DOWN)
                     prjctMgr.sethintchk(true);
                     if(state==GLUT_UP)
                     prjctMgr.sethintchk(false);
                }

          }
          else if(prjctMgr.getcurrentDisplayedPage() == FRAME_SETTINGS)
          {
               //high difficulty
               if ((x >482 && x <575) && (y<486 && y>443))
               {
                   
                    
                    /*glutDisplayFunc(drawSetting);
                    currentDisplayedPage = FRAME_SETTINGS;*/
               }
               //low difficulty
               else if ((x >633 && x <727) && (y<487 && y>445))
               {
                    
                   /* glutDisplayFunc(drawHowToPlay);
                    currentDisplayedPage = FRAME_HOW_TO_PLAY;*/
               }
               //medium difficulty
               else  if ((x >782 && x <876) && (y<485 && y>444))
               {
                    /*glutDisplayFunc(drawMenu);
                    currentDisplayedPage = FRAME_MENU;*/
               }
               //how to play
               else if ((x >303 && x <700) && (y<347 && y>304))
               {
                    glutDisplayFunc(drawHowToPlay);
                    prjctMgr.setcurrentDisplayedPage(FRAME_HOW_TO_PLAY);
               }
               //player  profile
               else if ((x >303 && x <700) && (y<247 && y>304))
               {
                    /*glutDisplayFunc(drawHowToPlay);
                    currentDisplayedPage = FRAME_HOW_TO_PLAY;*/
               }
               //back to menu
               else  if ((x >303 && x <700) && (y<147 && y>104))
               {
                    glutDisplayFunc(drawMenu);
                    prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
               }
               //Sound ON
               else if ((x >483 && x <537) && (y<636 && y>594))
               {
                    PlaySound(NULL, 0, 0);
                    PlaySound(TEXT("CandyCrushSoundtrack4.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
                    prjctMgr.setisSoundON(true);
               }
               //Sound OFF
               else  if ((x >572 && x <628) && (y<638 && y>595))
               {
                    PlaySound(NULL, 0, 0);
                    prjctMgr.setisSoundON(false);
               }

          }
          else if(prjctMgr.getcurrentDisplayedPage() == FRAME_SAVE_GAME)
          {

          }
          else if(prjctMgr.getcurrentDisplayedPage() == FRAME_HOW_TO_PLAY)
          {
               //back to menu
               if ((x >452 && x <645) && (y<97 && y>57))
               {
                    glutDisplayFunc(drawMenu);
                    prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
               }

          }
          else if(prjctMgr.getcurrentDisplayedPage() == FRAME_GAME_MODE)
          {
               //normal mode
               if ((x >381 && x <625) && (y<546 && y>406))
               {
                    prjctMgr.getmodeObj()->setNormalMode(true);
                    prjctMgr.getmodeObj()->setTimeTrialMode(false);
                    glutDisplayFunc(drawMenu);
                    prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
               }
               //time trial mode
               else if ((x >384 && x <625) && (y<296 && y>156))
               {
                    prjctMgr.getmodeObj()->setNormalMode(false);
                    prjctMgr.getmodeObj()->setTimeTrialMode(true);
                    glutDisplayFunc(drawMenu);
                    prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
               }
          }
          else if (prjctMgr.getcurrentDisplayedPage() == FRAME_CONGRATULATIONS)
          {
               //level up
               if ((x >284 && x <775) && (y<198 && y>158))
               {
                    prjctMgr.setLevelUpgrade(false);
                    
                    glutDisplayFunc(GameDisplay);
                    prjctMgr.setcurrentDisplayedPage(FRAME_GAME_DISPLAY);

                    PlaySound(NULL, 0, 0);
                    
                    if (prjctMgr.getisSoundON())
                    {
                         PlaySound(TEXT("CandyCrushSoundtrack4.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
                    }

               }
              
          }
          
	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
     RECT desktop;
     // Get a handle to the desktop window
     const HWND hDesktop = GetDesktopWindow();
     // Get the size of screen to the variable desktop
     GetWindowRect(hDesktop, &desktop);
     // The top left corner will have coordinates (0,0)
     // and the bottom right corner will have coordinates
     // (horizontal, vertical)
     horizontal = desktop.right;
     vertical = desktop.bottom;
}

void toggleGlutWindowMaximizeBox(char *szWindowTitle)
{
     long dwStyle;
     HWND hwndGlut;

     hwndGlut = FindWindowA(NULL, szWindowTitle);

     dwStyle = GetWindowLong(hwndGlut, GWL_STYLE);
     dwStyle ^= WS_MAXIMIZEBOX;
     SetWindowLong(hwndGlut, GWL_STYLE, dwStyle);
}

void DisplayProgressBar(int m)
{
    // prjctMgr.DisplayProgressBar();
     glutTimerFunc(1000.0, DisplayProgressBar, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
     string plyrName;
     int MyDesktopWidth = 0;
     int MyDesktopHeight = 0;
     GetDesktopResolution(MyDesktopWidth, MyDesktopHeight);
     cout << MyDesktopWidth << '\n' << MyDesktopHeight << '\n';
     prjctMgr.setcurrentDisplayedPage(FRAME_MENU);
     int MyDesktopWidthCenter = MyDesktopWidth/2;
     int MyDesktopHeightCenter = MyDesktopHeight/2;
     
     cout << "enter player name\n";
     cin >> plyrName;
     prjctMgr.getScreenObj()->setPlayerName(plyrName);
     //1366 X 768
	int width =1024, height =670; // i have set my window size to be 800 x 600
    char *szWindowTitle = "OOP Project";

    int GameDisplayWidthCenter = width/2;
    int GameDisplayHeightCenter = height / 2;

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(abs(MyDesktopWidthCenter - GameDisplayWidthCenter), abs(MyDesktopHeightCenter - GameDisplayHeightCenter)); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow(szWindowTitle); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
    toggleGlutWindowMaximizeBox(szWindowTitle);

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(drawMenu);
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
    glutTimerFunc(1000.0, DisplayProgressBar, 0);
        
    PlaySound(TEXT("CandyCrushSoundtrack4.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
