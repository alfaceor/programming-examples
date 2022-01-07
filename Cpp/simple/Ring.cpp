#include "Ring.h"

Ring::Ring(int const N){
  this->N = N;
  k = 1.0;
  alpha = 0.0;
}

Ring::~Ring(){

}

string Ring::getParams(){
  return "Hello World";
}
