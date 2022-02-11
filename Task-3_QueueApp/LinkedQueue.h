#pragma once
#include"Queue.h"
#include<string>

using namespace std;

template<class E>
class LinkedQueue : public Queue<E>
{
public:

   LinkedQueue()
   {
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
   }

   void offer(E element)
   {
      if (size == 0)
      {
         Node* newElement = new Node(element);

         head = newElement;
         tail = newElement;
      }
      else if (size == 1)
      {
         tail = new Node(element, head);
         head->pPrev = tail;
      }
      else
      {
         Node* newElement = new Node(element, tail);

         tail->pPrev = newElement;
         tail = tail->pPrev;
      }

      size++;
   }

   void remove()
   {
      Node* toDelete = head;

      head = head->pPrev;

      delete toDelete;

      size--;
   }

   E element()
   {
      E resultElement = head->element;

      remove();

      return resultElement;
   }

   E peek()
   {
      return head->element;
   }

   void clean()
   {
      while (size != 0)
         remove();
   }

   long getSize()
   {
      return size;
   }

   string toString()
   {
      string result = "";

      Node* current = head;

      while (current->pPrev != nullptr)
      {
         result += "[" + current->element.toString() + "] ";
         current = current->pPrev;
      }

      return result;
   }

private:

   class Node
   {
   public:
      Node* pNext;
      Node* pPrev;
      E element;

      Node(E element, Node* pNext = nullptr, Node* pPrev = nullptr)
      {
         this->pNext = pNext;
         this->pPrev = pPrev;
         this->element = element;
      }
   };

   Node* head;
   Node* tail;

   long size;
};