#pragma once
#include<string>

using namespace std;

template<class T>
class Number
{
public:
   Number(T number)
   {
      this->number = number;
   }

   Number() {}

   string toString()
   {
      return to_string(number);
   }

private:
   T number;
};