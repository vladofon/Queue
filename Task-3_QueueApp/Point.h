#pragma once
#include<string>

class Point
{
public:
   Point(long x, long y)
   {
      this->x = x;
      this->y = y;
   }

   Point() {}

   std::string toString()
   {
      return "(" + std::to_string(x) + " ; " + std::to_string(y) + ")";
   }

private:
   long x;
   long y;
};