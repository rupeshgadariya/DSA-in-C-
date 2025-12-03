/*  1. Define a copy constructor in Array class to perform deep copy.
    2. Define a copy assignment operator in Array class to perform deep copy.   */
#include<iostream>
using namespace std;

 class Array
 {
    private:
      int capacity, last_index;
      int *ptr;
    public:
      ~Array(){   delete []ptr;     }
      Array(int size)
      {  capacity = size;
         last_index = -1;
         ptr = new int[size];  
      }
      Array(Array &c)
      {
         capacity = c.capacity;
         last_index = c.last_index;
         ptr = new  int[capacity];
         for (int i = 0; i <= last_index; i++)
         {
            ptr[i] = c.ptr[i];
         }
      }
      Array& operator=(Array&); 
 };
      Array& Array::operator=(Array &c)
      {
          delete []ptr;
         capacity = c.capacity;
         last_index = c.last_index;
         ptr = new int[capacity];
         for (int i = 0; i <= last_index; i++)
         {
            ptr[i] = c.ptr[i];
         }
         return *this;
      }

    int main()
{
        
        
    return 0;
}