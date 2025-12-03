#include<iostream>
using namespace std;

struct node
{
   int value;
   node *next;
};
  
 class SLL
 {
    private:
        node *start;
    public:
        SLL(){  start = nullptr;    }
        ~SLL();
        void insert_Start(int);
        void insert_End(int);
        bool search(int);
        void insert_specific(node*, int);
        void delete_first();
        void delete_last();
 };
    void SLL::insert_Start(int value)
    {
        node *n = new node;
        n->value = value;
        n->next = start;

        start = n;
    }

    void SLL::insert_End(int value)
    {
        node *n = new node;
        n->value = value;
        n->next = nullptr;

        if(start!=nullptr)
        {   
             node *p = start;
            while (p!=nullptr)
            {
               if (p->next==nullptr)
                { 
                  p->next = n;
                  break;
                }
               p = p->next;
            }
        }
        else 
        {
            start = n;
        }

    }
        
    bool SLL::search(int value)
    {
        node *p = start;
        while (p!=nullptr)
        {
            if(p->value == value )      return true;

            p = p->next;
        }
            return false;
    }

    void SLL::insert_specific(node *ptr, int value)
    {  
        if(ptr != nullptr)
        {
            node *p = start;
          while(p != nullptr)
           {
                if(p == ptr)
                {
                   node *temp = new node;
                   p->next = temp;
                   temp->value = value; 
                   temp->next = p->next;
                   break;
                }
              p = p->next;
           }
        }
    }

    void SLL::delete_first()
    {
        node *p = start;
        if(p!=nullptr)
        {
          start = start->next;
          delete p;
        }
    }

    void SLL::delete_last()
    {
        if(start!=nullptr && start->next==nullptr)
        {
            node *p = start;
            start = nullptr;
            delete p;
        }
        else if (start != nullptr)
        {
            node *p = start, *temp = nullptr;
            while (p != nullptr )
            {
               if (p->next == nullptr)
               {
                  temp->next = nullptr;
                  delete p;
                  break;
               }
                 
               temp = p;
               p = p->next;
            }
        }
    }

    SLL::~SLL()
    {
        while (start != nullptr)
        {
            delete_first();
        }
    }

    int main()
{
        
        
    return 0;
}