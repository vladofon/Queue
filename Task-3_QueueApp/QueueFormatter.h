#pragma once
#include<string>
#include"List.h"
#include"Queue.h"
#include"ArrayList.h"
#include "TableSchema.h"
#include "SchemaParser.h"
#include "Point.h"
#include "Number.h"

using namespace std;

class QueueFormatter
{
public:
   QueueFormatter(TableSchema* schema)
   {
      this->schema = schema;
   }

   QueueFormatter()
   {
      // If constructor empty define default schema
      this->schema = new TableSchema();
      initDefaultSchema();
   }

   string format(Queue<Point>* points, List<Queue<Number<long>>*>* numbers)
   {
      List<string>* firstColumn = new ArrayList<string>();
      List<string>* secondColumn = new ArrayList<string>();

      firstColumn = parsePoints(points);
      secondColumn = parseNumbers(numbers);

      schema->fillColumn(0, 0, firstColumn);
      schema->fillColumn(1, 0, secondColumn);

      SchemaParser* parser = new SchemaParser(*schema);
      return parser->parseSchema();
   }

private:
   TableSchema* schema;

   void initDefaultSchema()
   {
      schema->createRow("=======+ Coordinates of points +=======");
      schema->getRow(0).createColumn("Points list:");
      schema->createRow("=======+ Queue of integer numbers +=======");
      schema->getRow(1).createColumn("Numbers list:");
   }

   List<string>* parsePoints(Queue<Point>* points)
   {
      List<string>* stringPoints = new ArrayList<string>();

      long size = points->getSize();
      for (long i = 0; i < size; i++)
      {
         stringPoints->add(points->element().toString());
      }

      return stringPoints;
   }

   List<string>* parseNumbers(List<Queue<Number<long>>*>* numbers)
   {
      List<string>* stringNumbers = new ArrayList<string>();

      long size = numbers->getSize();
      for (long i = 0; i < size; i++)
      {
         stringNumbers->add(numbers->get(i)->toString());
      }

      return stringNumbers;
   }
};