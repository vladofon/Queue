#pragma once
#include<string>

template<class E>
class Queue
{
public:
   virtual E element() = 0;

   virtual E peek() = 0;

   virtual void remove() = 0;

   virtual void offer(E element) = 0;

   virtual void clean() = 0;

   virtual long getSize() = 0;

   virtual std::string toString() = 0;
};