#include <iostream>
#include <algorithm>

class AlignmentData{
  public:
    AlignmentData();
    ~AlignmentData();
    int score;
    //bool operator<(AlignmentData const & a, AlignmentData const & b);
};

AlignmentData::AlignmentData(){
}
AlignmentData::~AlignmentData(){
}

bool operator<(AlignmentData const & a, AlignmentData const & b){
  return a.score < b.score;
}

bool operator>(AlignmentData const & a, AlignmentData const & b){
  return a.score > b.score;
}

int main(){
  AlignmentData a1, a2;
  a2.score = 10;
  a1.score = 50;
  if (a1 > a2)
    std::cout<< a1.score<< "> " << a2.score <<std::endl;

  return 0;
}
