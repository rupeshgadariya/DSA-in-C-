/*1. Define a class Stack with capacity, top and ptr pointer as member variables.
   Implement stack using array.
2. In question 1, define a parameterzied constructor to initialise member variables.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. In question 1, define a method to check stack overflow
8. In question 1, define a method to check stack underflow.
9. Define a method to reverse a stack.
10. Define a solution to keep track of minimum value element in the stack. */
#include<iostream>
using namespace std;
 
 class stack
 {
    private:
        int capacity, top, *ptr;
    public:
        stack(int);
        void push(int);
        void peek();
        void pop();
        ~stack();
        bool overflow();
        bool underflow();
 };
    stack::stack(int capacity)
    {
        this->capacity = capacity;
        top = -1;
        ptr = new int[capacity];
    }
    void stack::push(int value)
    {
        if(top < capacity - 1)
        {
            top++;
            ptr[top] = value;
        }
        else
            cout<<"Element are not push\n";

    }
    void stack::peek()
    {  
        if(top >= 0)
        cout<<"Top element : "<<ptr[top]<<endl;
    }
    void stack::pop()
    {  
        if(top >= 0)
         top--;
    }
    stack::~stack()
    {
        delete []ptr;
    }
    bool stack::overflow()
    {
        if(capacity-1 == top) return true;
        else    return false;
    }
    bool stack::underflow()
    {
        if(top == -1 )      return true;
        else return false;
    }

    int main()
{
        
        
    return 0;
}