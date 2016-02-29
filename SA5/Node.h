#ifndef __NODE_H
#define __NODE_H
struct Node
{
   int val;
   Node *left;
   Node *right;
   int ht;

   Node(int v, Node* l=nullptr, Node* r=nullptr, int h=0): val(v), left(l), right(r), ht(h) {}
};
#endif
