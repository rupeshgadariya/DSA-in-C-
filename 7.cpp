/*1. Define a class CDLL to implement Circular Doubly linked list data structure with
   member variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified
   node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in
    the linked list.*/
#include<iostream>
using namespace std;

 class node
 {
    public:
        int value;
        node *next, *prev;
 };
 class CDL
 {
    private:
        node *last;
    public:
        CDL();
        void insert_first(int);
        void insert_last(int);
        node* search(int);
        void insert_specified(node*,int);
        void delete_first();
        void delete_last();
        void delete_specified(node*);
        ~CDL();
 };
    CDL::CDL()
    {
        last = nullptr;
    }
    void CDL::insert_first(int value)
    {
        node *n = new node;
        if(last != nullptr )
        {
            n->value = value;
            n->next = last->next;
            n->prev = last;
            last->next->prev = n;
            last->next = n;
        }
        else
        {
            n->value = value;
            n->next = n;
            n->prev = n;
            last = n;
        }
    }
    void CDL::insert_last(int value)
    {
        node *n = new node;
        if (last != nullptr)
        {
            n->value = value;
            n->next = last->next;
            n->prev = last;
            last->next->prev = n;
            last->next = n;
            last = n;
        }
        else
         {
            n->value = value;
            n->next = n;
            n->prev = n;
            last = n;
         }
        
    }
    node* CDL::search(int value)
    {
        if (last != nullptr)
        {
            if(last->value == value)
             return last;

            node *temp = last->next;
            while (temp != last)
            {
                if(temp->value == value )
                    return temp;
                temp = temp->next;
            }
            return nullptr;
        }
        return nullptr;
    }
    void CDL::insert_specified(node *ptr, int value)
    {
        if (last != nullptr)
        {
           if(last == ptr)
           {
              insert_last(value);
           }
           else
           {
              node *temp = last->next;
              while (temp != last)
              {
                    if(temp == ptr)
                    {
                        node *n = new node;
                        n->value = value; 
                        n->next = temp->next;
                        n->prev = temp;
                        temp->next->prev = n;
                        temp->next = n;
                        break;
                    }
                   temp = temp->next;
              }
           }  
        }
    }
    void CDL::delete_first()
    {
        if (last != nullptr)
        {
            if (last == last->next)
            {
                delete last;
                last = nullptr;
            }
            else
            {
                node *temp = last->next;
                temp->next->prev = last;
                last->next = temp->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
            }
            
        }
        
    }      
    void CDL::delete_last()
    {
        if(last != nullptr)
        {
            if(last == last->next)
            {
                delete last;
                last = nullptr;
            }
            else
            {
                node *temp = last;
                last->prev->next = last->next;
                last->next->prev = last->prev;
                last = last->prev;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
            }
        }
    }
    void CDL::delete_specified(node *ptr)
    {
        if (last != nullptr)
        {
            if(last == ptr)
             delete_last();
            else if (last->next == ptr)
              delete_first();
            else 
            {
                node *temp = last->next;
                while (temp != last)
                {
                    if(temp == ptr)
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp->next = nullptr;
                        temp->prev = nullptr;
                        delete temp;
                    }
                    temp = temp->next;
                }
                
            }
        }
        
    }
    CDL::~CDL()
    {
        while (last != nullptr)
        {
            delete_first();
        }
        
    }

    int main()
{
        
        
    return 0;
}