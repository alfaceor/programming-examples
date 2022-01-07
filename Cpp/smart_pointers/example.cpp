#include <iostream>
#include <list>

int main(int argc, char* argv[]){
  std::list<int> event_list(4,7);
  for (int event : event_list){
    std::cout<< event << std::endl;
  }
  return 0;
}
