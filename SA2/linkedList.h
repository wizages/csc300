#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H
#include <iostream>
#include <assert.h>

using namespace std;


template <class T>
class listNode
{
public:
   T data;
   listNode<T>* next;
    
   listNode<T>(T d = -1, listNode<T> *n = nullptr) : data(d), next(n){}
};

template <class T>
class linkedList
{
   listNode<T>* head;

public:
   linkedList<T>(listNode<T>* head = nullptr);
   
   void printList();
   listNode<T>* find(int d);
   void push_front(int d);
   void push_back(int d);
   listNode<T>* pop_front();
   listNode<T>* pop_back();
};

template <class T>
linkedList<T>::linkedList(listNode<T>* h)
{
   head = h;
}

template <class T>
void linkedList<T>::printList()
{
   listNode<T>* ptr = head;
   while (ptr != nullptr)
   {
      cout << ptr->data;
      if (ptr->next != nullptr) cout << "->";
      ptr = ptr->next;
   }
   cout << endl;
}

template <class T>
listNode<T>* linkedList<T>::find(int d)
{
   listNode<T>* ptr = head;
   while (ptr != nullptr)
   {
      if (ptr->data == d)
          return ptr;

      ptr = ptr->next;
   }
   return nullptr;
}

template <class T>
void linkedList<T>::push_front(int d)
{
   listNode<T>* newNode = new (nothrow) listNode<T>(d, head);
   assert(newNode != nullptr);

   head = newNode;
}

template <class T>
void linkedList<T>::push_back(int d)
{
   listNode<T>* newNode = new (nothrow) listNode<T>(d);
   assert(newNode != nullptr);

   if (head == nullptr)
   {
      head = newNode;
      return;
   }

   listNode<T>* ptr = head;
   while (ptr->next != nullptr)
      ptr = ptr->next;

   ptr->next = newNode;
}

template <class T>
listNode<T>* linkedList<T>::pop_front()
{
   if (head == nullptr) return nullptr;

   listNode<T>* node = head;
   head = head->next;
   return node;
}

template <class T>
listNode<T>* linkedList<T>::pop_back()
{
   if (head == nullptr) return nullptr;

   listNode<T>* node = head;

   if (head->next == nullptr)
   {
      head = nullptr;
      return node;
   }

   listNode<T>* trailer = node;
   node = node->next;

   while (node->next != nullptr)
   {
      trailer = node;
      node = node->next;
   }

   trailer->next = nullptr;
   return node;
}

#endif
