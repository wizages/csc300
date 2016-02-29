#include <iostream>
#include <queue>
#include "util.h"
#include "Node.h"
#ifdef __APPLE__
  #include <GLUT/glut.h>
  #include <OpenGL/OpenGL.h>
#else
  #include <GL/glut.h>
#endif

using namespace std;

typedef unsigned char byte;

Node* insert(Node* root, int val);
void DrawFilledRectangle();

void printInOrderTree(Node* root)
{
   if (root == nullptr) return;

   printInOrderTree(root->left);
   cout << root->val << " ";
   printInOrderTree(root->right);
   return;
}

void printLevelOrder(Node* root)
{
  queue<Node *> myQue;
  Node *temp_Node = root;

  while(temp_Node)
  {
    cout << temp_Node->val << "[" << temp_Node->ht << "] ";

    if(temp_Node->left) myQue.push(temp_Node->left);

    if(temp_Node->right) myQue.push(temp_Node->right);

    temp_Node = myQue.front();
    myQue.pop();
  }
  cout << endl;
}

void display(void);
void keyboard(const byte key, const int x, const int y);
void initOpenGL(int ncols, int nrows);
void mouseClick(int state, int button, int x, int y);
void reshape(const int w, const int h);

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   initOpenGL(1024, 500);
   glutMainLoop();
   return 0;
}

void initOpenGL(int ncols, int nrows) 
{
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(ncols,nrows);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Tree Viewer - Enter integers followed by <return>");

    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutReshapeFunc(reshape);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   utilityCentral(Event());
   glFlush();
}

void keyboard(const byte key, const int x, const int y)
{
   utilityCentral(Event(key, x, y));
}

void mouseClick(int state, int button, int x, int y)
{
   utilityCentral(Event(button, state, x, y));
}

void reshape(const int w, const int h) {
    glLoadIdentity();           // initialize transformation matrix
    gluOrtho2D(0.0,w,0.0,h);
    glViewport(0,0,w,h);        // adjust viewport to new window
    glutPostRedisplay();
}
