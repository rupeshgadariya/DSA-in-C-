/*
1. Define a class Stack with node type pointer top as member variable. 
   Implement stack using linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. Define a method to reverse a stack.
8. Define a method to check whether a given number is a palindrome or not
   using stack.
9. Define a method to convert infix to postfix expression.
10. Define a method to evaluate postfix expression.
*/
#include<iostream>
using namespace std;

class node
{
    public:
        int value;
        node *next;
};

class stack
{
    private:
        node *top;
    public:
      stack();
      void push(int);
      int peek();
      void pop();
      ~stack();
};
    stack::stack()
    {   
        top = nullptr;
    }
    void stack::push(int value)
    {
        node *n = new node;
        n->value = value;
        n->next = top;
        top = n;
    }
    int stack::peek()
    {
        if(top != nullptr)
        return top->value;
        throw runtime_error("Stack is empty");
    }
    void stack::pop()
    {
        if(top != nullptr)
        {
            node *temp=top;
            top = top->next;
            delete temp;
        }
    }
    stack::~stack()
    {
        while (top != nullptr)
        {
            pop();
        }
        
    }

    int main()
{
        
        
    return 0;
}