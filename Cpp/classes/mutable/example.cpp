#include <iostream>
class A
{
  public:
    A() : x(4), y(5) { };
    mutable int x;
    int y;
    void print();
    void print() const;
    ~A();
};

A::~A(){
}
void A::print(){
  std::cout << x << " " << y <<std::endl;
};


void A::print() const{
  std::cout << x << " " << y << " for a const instance" <<std::endl;
};


int main()
{
  const A var2;
  //A var2;
  var2.x = 345;
  // var2.y = 2345;
  var2.print();
  return 0;
}

