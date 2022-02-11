#include <iostream>
#include"Queue.h"
#include"LinkedQueue.h"
#include"QueueFormatter.h"
#include"Point.h"
#include"List.h"
#include"ArrayList.h"
#include"Number.h"

using namespace std;

void generateRandomLongQueue(Queue<Number<long>>& queue)
{
   for (long i = 0; i < 10; i++)
   {
      long randNumber = rand() % 10 + 1;
      randNumber *= (i % 2 == 0) ? (-1) : 1;

      queue.offer(Number<long>(randNumber));
   }
}

void generateRandomPointQueue(Queue<Point>& queue)
{
   for (long i = 0; i < 10; i++)
   {
      long randNumberX = rand() % 10 + 1;
      randNumberX *= (i % 2 == 0) ? (-1) : 1;

      long randNumberY = rand() % 10 + 1;
      randNumberY *= (i % 2 == 0) ? 1 : (-1);

      queue.offer(Point(randNumberX, randNumberY));
   }
}

int main()
{
   List<Queue<Number<long>>*>* numbers = new ArrayList<Queue<Number<long>>*>();

   Queue<Number<long>>* numbersQueue1 = new LinkedQueue<Number<long>>();
   Queue<Number<long>>* numbersQueue2 = new LinkedQueue<Number<long>>();
   Queue<Number<long>>* numbersQueue3 = new LinkedQueue<Number<long>>();
   Queue<Number<long>>* numbersQueue4 = new LinkedQueue<Number<long>>();
   Queue<Number<long>>* numbersQueue5 = new LinkedQueue<Number<long>>();

   generateRandomLongQueue(*numbersQueue1);
   generateRandomLongQueue(*numbersQueue2);
   generateRandomLongQueue(*numbersQueue3);
   generateRandomLongQueue(*numbersQueue4);
   generateRandomLongQueue(*numbersQueue5);

   numbers->add(numbersQueue1);
   numbers->add(numbersQueue2);
   numbers->add(numbersQueue3);
   numbers->add(numbersQueue4);
   numbers->add(numbersQueue5);

   Queue<Point>* pointsQueue = new LinkedQueue<Point>();

   generateRandomPointQueue(*pointsQueue);

   QueueFormatter* formatter = new QueueFormatter();
   string result = formatter->format(pointsQueue, numbers);

   cout << result;
}


