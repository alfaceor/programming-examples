// CPP program to illustrate  
// concept of Virtual Functions 
#include<iostream> 
using namespace std; 
  
class base 
{ 
public: 
    virtual void print () 
    { cout<< "print base class" <<endl; } 
  
    void show () 
    { cout<< "show base class" <<endl; } 
}; 

class derived:public base
{
public:
    void print ()
    { cout<< "print derived class" <<endl; }

    void show ()
    { cout<< "show derived class" <<endl; }
};

int main()
{
    base *bptr;
    cout << "======== base class bprt" <<endl;
    //bptr->print();
    bptr->show();

    cout << "======== derived class d" <<endl;
    derived d;
    d.print();
    d.show();
    
    cout << "======== base class pointer to derived class d" <<endl;
    bptr = &d;
    bptr->print();
    bptr->show();

    return 0;
}