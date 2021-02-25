#include <iostream>

class ECE309 {
public:
  double getGrade(){
    return 90;
  }
};

ECE309 global; // global 

int main()
{
  ECE309 e; //local instance of ECE309

  ECE309 *ptr = new ECE309; // heap variable

  ECE309 &ref = *(new ECE309); 
  
  double d = ptr->getGrade(); // (*ptr).getGrade();

  std::cout << "My grade is " << d << std::endl;

  std::cout << ref.getGrade() << std::endl;
  
  delete ptr;
  
  return 0;
}
