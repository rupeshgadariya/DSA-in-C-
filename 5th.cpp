#include<iostream>
using namespace std;
 class node
     {
        public:
            int value;
            node *pre, *next;          
     };
class DLL
{
   private:
      node *start;
     
    public:
        DLL()
       {
          start = nullptr;
       }
        void insert_first(int);
        void insert_last(int);
        node* search(int);
        void insert_specified(node*, int);
        void delete_first();
        void delete_last();
        void delete_specified(node*);
        ~DLL()
        {
            while (start != nullptr)
            {
                delete_first();
            }
            
        }

};
    void DLL::insert_first(int value)
    {
        node *n = new node;

        n->pre = nullptr;
        n->value = value;
        n->next = start;
        
        if(start != nullptr)
         start->pre = n;
        start = n;
    }

    void DLL::insert_last(int value)
    {
        node *n = new node;
        n->next = nullptr;
        n->value = value;

        if(start != nullptr)
        {
            node *temp = start;
            while (temp != nullptr)
            {
                if(temp->next == nullptr)
                {
                    n->pre = temp;
                    temp->next = n;
                    break;
                }
                temp = temp->next;
            }
        }
        else
        {
          n->pre = nullptr;
          start = n;
        }
            
    }

    node* DLL::search(int value)
    {
        node *temp = start;
        if (temp != nullptr)
        {
            while (temp != nullptr)
            {
                if (temp->value == value)
                {
                   return temp; 
                }
                
                temp = temp->next;
            }
            return nullptr;
        }
        else
          return nullptr;
        
    }

    void DLL::insert_specified(node *ptr, int value)
    {
        node *temp = start;
        if (ptr != nullptr)
        {
            while (temp != nullptr)
            {
                if (temp == ptr)
                  break;
                temp = temp->next;
            }
        }

        if(temp == nullptr)
         cout<<"Does'n match specified node\n";
        else
        {
            node *n = new node;
            n->pre = temp;
            n->value = value;
            n->next = temp->next;

            temp->next = n;
            if(n->next != nullptr)
             n->next->pre = n;
            
        }
    }
            
    void DLL::delete_first()
    {
        if (start != nullptr)
        {
            if(start->next == nullptr)
            {
                 delete start;
                 start = nullptr;
            }
            else
            {
                start = start->next;
                delete start->pre;
                start->pre = nullptr;
            }
        }
    }   

    void DLL::delete_last()
    {
        node *temp = start;
        if (start != nullptr && start->next != nullptr)
        { 
            while (temp != nullptr)
            {
                if(temp->next == nullptr)
                {
                   
                    temp->pre->next = nullptr;
                    delete temp;
                    break;
                }
                temp = temp->next;
            }
        }
        else if(start != nullptr)
           delete_first();
    }   

    void DLL::delete_specified(node *ptr)
    {
        node *temp = start;
        
        if (ptr != nullptr)
            while (temp != nullptr)
            {
                if(temp == ptr) 
                    break;
                temp = temp->next;
            }
        if (temp == nullptr)
         cout<<"Does'n match specified node\n";

        if(start == ptr)
          delete_first();
        else if (temp != nullptr)
        {
            if (temp->pre != nullptr)
             temp->pre->next = temp->next;
            
            if (temp->next != nullptr)
             temp->next->pre = temp->pre;
            
             delete temp;
        }
    }
            
        

    int main()
{
         
   
    return 0;
}