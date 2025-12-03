#include<iostream>
using namespace std;

 class Array
{
    private:
        int Capacity, last_index;
        int *ptr;
    public:
       Array(int size)
       {   
           Capacity = size;
           last_index = -1;
           ptr = new int[size]; 
       } 
       ~Array(){    delete []ptr;    }

       bool isEmpty();
       void append(int);
       void insert(int, int);
       void edit(int, int);
       void remove(int index);
       bool isfull();
       int getIndex(int);
       int countArray(){  return last_index+1;  }
       int find(int);
};
     bool Array::isEmpty()
     {
         if ( last_index == -1)  return true;
          else return false;
     }
     void Array::append(int value)
     {
        if( last_index == Capacity-1 ) 
           cout<<"Array is Full"<<endl;
        else 
        {
            last_index++;
            ptr[last_index] = value;  // *(ptr+last_index) = value;  => are same
        }
     }
     void Array::insert(int index, int value)
     {
        if(index == last_index + 1)
         {
            last_index++;
            ptr[last_index] = value;
         }
         else if ( index >= 0 && index <= last_index && index <= Capacity-2 )
           {
              int i;
              for ( i = last_index; i >= index; i--)
               {  ptr[i+1] = ptr[i]; }
              
               last_index++;
                ptr[last_index] = value;
           }
              

     }
     void Array::edit(int index, int value)
     {
        if (last_index >= index && index >= 0)
           ptr[index] = value;
        else
           cout<<"Invailed Index"<<endl;
        
     }
     void Array::remove(int index)
     {
        for (int i = index; i < last_index; i++)
        {
            ptr[i] = ptr[i+1];
        }
          last_index--;
        
     }
     bool Array::isfull()
     {
        if(last_index == Capacity-1 )  return true;
        else  return false;
     }
     int Array::getIndex(int index)
     {
         if(index <= last_index && index  >= 0)
           return ptr[index];
         else 
         {
              cout<<"Invailed Index"<<endl;
              return -1;
         }
     }
     int Array::find(int value)
     {
        for (int i = 0; i <= last_index; i++)
        {
           if (ptr[i] == value) return i;
        }

           return -1;
     }

    int main()
{
        
        
    return 0;
}