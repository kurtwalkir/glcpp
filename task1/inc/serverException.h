#pragma once
#include <iostream>

class serverException
{
   char *str;

public:
   serverException(char *str)
   {
      this->str = str;
   }

   void display(void)
   {
      std::cout<<"Server error:"<<str<<std::endl;
   }
};