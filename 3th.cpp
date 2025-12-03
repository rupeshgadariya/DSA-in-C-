#include<iostream>
using namespace std;

class DynArray
{
    private:
       int Capacity, Last_Index;
       int *ptr;

    protected:
       void doubleArray();
       void halfArray();
       
    public:
       DynArray() 
       {    Capacity = 10;
            Last_Index = -1;
            ptr = new int[Capacity];     
        }
       ~DynArray()  {   delete []ptr;    }
       int Current_Capacity();
       bool isEmpty();
       void append(int);
       void insert(int, int);
       void edit(int, int);
       void remove(int);
       bool isFull();
       int get(int);
       int count();
       int find(int);
};
    void DynArray::doubleArray()
    { 
        Capacity = Capacity * 2;
        int *temp = new int[Capacity];
        for (int i = 0; i <= Last_Index; i++)
          temp[i] = ptr[i];

        delete []ptr;
        ptr=temp;
        
    }
    void DynArray::halfArray()
    {
        Capacity = Capacity / 2;
        int *temp = new int[Capacity];
        for(int i=0; i<=Last_Index; i++)
          temp[i] = ptr[i];
        delete []ptr;
        ptr = temp;
     
    }
    int DynArray::Current_Capacity()
    {
        return Capacity;
    }
    bool DynArray::isEmpty()
    {
        if (Last_Index == -1 )
          return true;
        else
          return false;
        
    }
    void DynArray::append(int value)
    {
       if(Last_Index+1 == Capacity)     doubleArray();

        Last_Index++;
        ptr[Last_Index] = value;
         
      if(Capacity/2 > Last_Index + 1)       halfArray();
    }
    void DynArray::insert(int index, int value)
    {  
        if( Last_Index == Capacity-1 )  doubleArray();

        if( index >=0 && index <= Last_Index+1 )
        {
          for(int i = Last_Index; i >= index; i--)
            ptr[i+1] = ptr[i];

          ptr[index] = value;
          Last_Index++;
        }  
    }
    void DynArray::edit(int index, int value)
    {
        if (index >= 0 && index <= Last_Index)
        {
            ptr[index] = value;
        }
        
    }
    void DynArray::remove(int index)
    {
        if(index >= 0 && index <= Last_Index )
         {
            for(int i = index; i < Last_Index ; i++)
             ptr[i] = ptr[i+1];

             Last_Index--;
         }
    }
    bool DynArray::isFull()
    {
        if( Last_Index+1 == Capacity )  return true;
        else      return false;
    }
    int DynArray::get(int index)
    {
        if(index >=0 && index <= Last_Index ) return ptr[index];
        else 
        {
            cout << "Error: Index out of range.\n";
            return 0;
        }  
    }
    int DynArray::count()
    {
        return Last_Index+1;
    }
    int DynArray::find(int value)
    {
        for (int i = 0; i <= Last_Index; i++)
          if(ptr[i] == value ) 
            return i;
        return -1;
        
    }

    int main()
{
        
        
    return 0;
}