
// CPP program to illustrate 
// Implementation of pop() function 
#include <iostream> 
#include <queue> 
using namespace std; 
  
int main() 
{ 
    // Empty Queue 
    queue<int> myqueue; 
    myqueue.push(0); 
    myqueue.push(1); 
    myqueue.push(2); 
    myqueue.push(7); 
    // queue becomes 0, 1, 2 
  
    myqueue.pop(); 
    myqueue.pop(); 
    // queue becomes 2 
  
    // Printing content of queue 
    while (!myqueue.empty()) { 
        auto xfront = myqueue.front();
        cout << ' ' << xfront <<endl; 
        myqueue.pop(); 
    } 
    return 0;
} 


