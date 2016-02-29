/***************************************************************************//**
@file
@brief This file contains the function definitions for the Mouse class.
*******************************************************************************/

#include "mouse.h"

/***************************************************************************//**
@author Paul Hinker
@date Jan 5, 2016
@brief Process a mouse click event.

@param[in] button	- describes which button was clicked
@param[in] state	- describes whether the button went down or up
@param[in] x		- the x-coordinate of where the click took place
@param[in] y		- the y-coordinate of where the click took place
*******************************************************************************/
void Mouse::mouseClick(const int button, const int state, const int x, const int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) leftDown = true;
		else if (button == GLUT_RIGHT_BUTTON) rightDown = true;
		downX = x;
		downY = y;
		clicked = 0;
	} else if (state == GLUT_UP) {  
		if (button == GLUT_LEFT_BUTTON) {
			#ifdef DEBUG
			std::cout << "Left Mouse Released\n";
			#endif
			leftDown = false;
			if (abs(x-downX) < 5 && abs(y-downY) < 5)
				clicked |= LEFT_CLICKED;
		} else if (button == GLUT_RIGHT_BUTTON) {
			#ifdef DEBUG
			std::cout << "Right Mouse Released\n";
			#endif
			rightDown = false;
			if (abs(x-downX) < 5 && abs(y-downY) < 5)
				clicked |= RIGHT_CLICKED;
		}

		#ifdef DEBUG
		std::cout << '(' << x << ", " << y << ")\n";
		#endif
		downX = -1;
		downY = -1;
	}
}

/***************************************************************************//**
@brief Process a mouse drag event. This means one or more buttons are in the
	   down state and the mouse position is moving.

@param[in] x - the x-coordinate of the mouse drag event
@param[in] y - the y-coordiante of the mouse drag event
*******************************************************************************/
void Mouse::mouseDrag(const int x, const int y) {
	if (leftDown && rightDown) 	{
		#ifdef DEBUG
		std::cout << "Dragging Left and Right\n";
		#endif
	} else if (leftDown) {
		#ifdef DEBUG
		std::cout << "Dragging Left\n";
		#endif
	} else if (rightDown) {
		#ifdef DEBUG
		std::cout << "Dragging Right\n";
		#endif
	} 
}
