/***************************************************************************//**
@file
@brief A function used to consolidate various openGL event calls
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "util.h"
#include "mouse.h"
#include "AVLTree.h"

/// Symbolic constants for the backspace and escape keys.
static const int BSP = 8;
static const int ESC = 27;

/***************************************************************************//**
@author Paul Hinker and John Colton

@par Description:
This function gets called when an event happens in callbacks. Depending on the
enum and data passed in it will do different things. When a mouse click is
passed in, it sends that data to the click function in the container class
screen. When a mouse drag is sent in, it sends it to the clickAndDrag function
in screen. It does the same for keyboard presses, sending them to
keyboardAction in screen.

@param[in] event - structure that contains data about the event to handle
*******************************************************************************/
void utilityCentral(const Event & event) {
	static Mouse mouse;
    static AVLTree avlTree;

    // GameBoard hold the game state between events
    
	switch (event.event) {
		case INIT: {
			break;
		}
		case DISPLAY: {
            avlTree.draw();
			break;
		}
		case KEYBOARD:
        {
           if (event.key == 27) exit(-1);
           avlTree.addToNodeVal(event.key);
           glutPostRedisplay();
        }
			break;
		case MOUSECLICK:
			mouse.mouseClick(event.button, event.state, event.x, event.y);
			break;
		case MOUSEDRAG:
			break;
	}
}
