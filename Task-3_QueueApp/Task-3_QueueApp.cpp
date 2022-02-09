#include <iostream>
#include"Queue.h"
#include"LinkedQueue.h"

using namespace std;

int main()
{
   Queue<long>* queue = new LinkedQueue<long>();

   queue->offer(100);
   queue->offer(200);
   queue->offer(300);
   queue->offer(400);
   queue->offer(500);

   long size = queue->getSize();
   for (long i = 0; i < size; i++)
   {
      cout << queue->element() << endl;
   }
}


