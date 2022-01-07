// constructing vectors
#include <iostream>
#include <vector>

void printVector(std::vector<int> vec){
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout <<std::endl;
}

void changeVector(std::vector<int> vec){
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
     *it = 100+*it;
  }
  printVector(vec);
}

void changeVecTradPointer(std::vector<int> *vec){
  for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); ++it){
     *it = 500+*it;
  }
  printVector(*vec);
}


void changeVecSharedPointer(shared_ptr<std::vector<int>> sharVec){
  for (std::vector<int>::iterator it = sharVec->begin(); it != sharVec->end(); ++it){
     *it = 500+*it;
  }
  printVector();
}

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  printVector(fifth);
  changeVector(fifth);
  std::cout << "-----------------" <<std::endl;
  printVector(fifth);

  // Traditional pointer
  std::cout << "TRADITIONAL POINTER" << std::endl;
  std::vector<int> *pvec;
  pvec = &fifth;
  printVector(*pvec);
  changeVecTradPointer(pvec);
  printVector(*pvec);

  return 0;
}
