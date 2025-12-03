/*  1. Define a class CLL to implement Circular linked list data structure with member
   variable last pointer of type node.
2. In question 1, define a constructor to initialise last pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified
    node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in
     the linked list..
    */
#include<iostream>
using namespace std;

 struct node
 {
    int value;
    node *next;
 };

 class CLL
 {
    private:
        node *last;
    public:
        CLL(){  last = nullptr; }
        void insert_first(int);
        void insert_last(int);
        node* search(int );
        void insert_specified(node*, int );
        void delete_first();
        void delete_last();
        void delete_specified(node*);
        ~CLL()  {  while (last != nullptr)  delete_first();   }
          
 };
    void CLL::insert_first(int value)
    {
        node *n = new node;
        n->value = value;

        if(last == nullptr )
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
        }
    }
    void CLL::insert_last(int value)
    {
        node *n = new node;
        n->value = value;

        if(last == nullptr)
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
            last = n;
        }

    }
    node* CLL::search(int value)
    {
      if(last != nullptr)
       {
            node *start = last->next;
            if (last->value == value ) return last;
            while (start != last)
            {
                if(start->value == value)  return start;

                start = start->next;
            }
            return nullptr;
      }    
        return nullptr;
    }
    void CLL::insert_specified(node *ptr, int value)
    {
        if(last != nullptr)
        {
            node *temp = last->next;
            if(last == ptr ) insert_last(value);
            else
            {
                while (temp != last)
                {
                    if(temp == ptr)
                    {
                        node *n = new node;
                        n->value = value;
                        n->next = temp->next;
                        temp->next = n;
                        break;
                    }
                    temp = temp->next;
                }
            }  
        }
        else 
          cout<<"Error! not match \n";
    }
    void CLL::delete_first()
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
            node *temp = last->next;
            last->next = temp->next;
            temp->next = nullptr;
            delete temp;
            }
        }
    }
    void CLL::delete_last()
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
                while (temp->next != last)
                {
                    temp = temp->next;
                }

                temp->next = last->next;
                last->next = nullptr;
                delete last;
                last = temp;
           }
        }
    }
    void CLL::delete_specified(node *ptr)
    {
        if(last != nullptr)
        {  
             node *temp = last->next;
            if(ptr == last->next) delete_first();
            else if(last == ptr) delete_last();
            else
            {
                while (temp->next != last)
                {
                    if(temp->next == ptr)
                    {
                        node *x = temp->next;
                        temp->next = x->next;
                        x->next = nullptr;
                        delete x;

                    }
                    temp = temp->next;
                }
            }
        }
    }      
        

    int main()
{
        
        
    return 0;
}