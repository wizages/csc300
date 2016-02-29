/***************************************************************************//**
@author Dr. Hinker
@file
@brief This file contains the declaration for the Mouse class. The Mouse class
keeps track of the last state the mouse was in.
*******************************************************************************/
#ifndef __MOUSE_H
#define __MOUSE_H
#include <iostream>
#ifdef __APPLE__
  #include <GLUT/glut.h>
  #include <OpenGL/OpenGL.h>
#else
  #include <GL/glut.h>
#endif

/// MouseClicked enum
enum MouseClicked {
   RIGHT_CLICKED = 1,
   LEFT_CLICKED = 2,
};

/***************************************************************************//**
@author Dr. Hinker
@class Mouse

@brief This class keeps track of mouse information.

@par Description Keeps the mouse state between events.
*******************************************************************************/
class Mouse {
	/// Is the left mouse button down
	bool leftDown;
	/// Is the right mouse button down
	bool rightDown;
	/// Was the mouse clicked
	int clicked;
	/// Where was the button down event (x-coord)
	int downX;
	/// Where was the button down event (y-coord)
	int downY;


	public:

	Mouse() : leftDown(false), rightDown(false), clicked(0), downX(-1), downY(-1) {}
	/// Called when a mouse click event happens
	void mouseClick(const int button, const int state, const int x, const int y);
	/// Called when a mouse drag event is raised
	void mouseDrag(const int x, const int y);
	/// Boolean telling if a mouse click happen (click is down then up)
	int mouseClicked() const { return clicked; }
	/// Function to clear the mouse click status
	void clearMouseClicked() { clicked = 0; }
	/// Get the X position of the mouse when the last button went down 
	int getDownX() const { return downX; }
	/// Get the Y position of the mouse when the last button went down
	int getDownY() const { return downY; }

	#ifdef UNIT_TEST
	friend class MouseTest;
	#endif
};

#endif /* __MOUSE_H */
