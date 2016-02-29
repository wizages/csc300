#include "Node.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#ifdef __APPLE__
  #include <GLUT/glut.h>
  #include <OpenGL/OpenGL.h>
#else
  #include <GL/glut.h>
#endif

Node* insert(Node* root, int val);

using namespace std;

class AVLTree
{
   string nodeVal;
   Node *root;

public:
   void addToNodeVal(char key);
   void draw();
};
