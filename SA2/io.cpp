#include "io.h"

linkedList<int>* fillList(ifstream& fin)
{
   linkedList<int>*ll = new linkedList<int>();

   int data;
   while (fin >> data)
      ll->push_back(data);
   
   return ll;
}
