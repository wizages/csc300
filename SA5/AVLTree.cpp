#include "AVLTree.h"

const int NODE_WIDTH = 20;
const int NODE_HEIGHT = 20;
const float color[] = {1.0, 1.0, 1.0};

void DrawFilledRectangle(int x1, int y1, int x2, int y2);
void DrawEllipse( float xRadius, float yRadius, int x, int y);
void DrawTextString( const char *string, int x, int y);
void DrawLine(int x1, int y1, int x2, int y2);

void AVLTree::addToNodeVal(char key)
{
   if (key == 13)
   {
      int val;
      stringstream stream1;
      stream1.str(nodeVal);
      stream1 >> val;
      root = insert(root, val);
      nodeVal.clear();
   }

   nodeVal += key;
}



void drawNode(int x, int y, Node* root, int depth)
{
   if (root == nullptr) return;

   stringstream ss;
   ss << root->val;
   //cout << root->val <<endl;
   DrawTextString(ss.str().c_str(), x, y);
   if (root->left != nullptr)
   {
      drawNode(x - (256 >> depth), y - 64, root->left, depth+1);
      DrawLine(x, y, x-(256 >> depth), y-64);
   }
   if (root->right != nullptr)
   {
      drawNode(x + (256 >> depth), y - 64, root->right, depth+1);
      DrawLine(x, y, x+(256 >> depth), y-64);
   }
   return;
}

void AVLTree::draw()
{
   int xs = glutGet(GLUT_WINDOW_WIDTH) / 2;
   int ys = glutGet(GLUT_WINDOW_HEIGHT) - 30;
   drawNode(xs, ys, root, 0);
}

void DrawFilledRectangle(int x1, int y1, int x2, int y2)
{
    float color[] = {1.0, 1.0, 1.0};
    glColor3fv( color );
    glBegin( GL_POLYGON );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

void DrawTextString( const char *string, int x, int y)
{
    glColor3fv( color );
    glRasterPos2i( x, y );
    while ( *string )
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *string++ );
}

void DrawEllipse( float xRadius, float yRadius, int x, int y)
{
    float radius = xRadius < yRadius ? xRadius : yRadius;
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

void DrawLine(int x1, int y1, int x2, int y2)
{
    glColor3fv(color);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

