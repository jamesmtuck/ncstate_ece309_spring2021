#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern "C" {
  void some_other_function();
}

void some_other_function()
{
  std::cout << "do something";
}

class Custard; // forward declaration
std::ostream& operator<< (std::ostream& o, Custard &c);

class Custard { // Class for Frozen Custard (ice cream)!
  string kind;
  int scoops;
public:
  Custard(string a_kind="vanilla", int a_scoops=1){
    kind = a_kind;
    scoops = a_scoops;
    //cout << "Enjoy your " << scoops << " scoops of " << kind << " custard!" << endl;
  }
  Custard(int a_scoops) { 
    scoops = a_scoops;
    kind = "chocolate"; 
  }
  ~Custard() {
    //cout << "Please recycle your cup!" << endl;
  }
  string getKind() const {
    return kind;
  }
  int& getScoops() {
    return scoops;
  }
};

std::ostream& operator+ (std::ostream& o, Custard &c)
{
  o << c.getScoops() << " scoops " << c.getKind() << " custard.";
  return o;
}

Custard mini("Vanilla with cookie dough",4); // global variable

int main()
{
  Custard c;
  ofstream myfile("custard.txt");

  (std::cout + c) << std::endl;

  (myfile + c) << std::endl;
  
  // CODE SNIPPET RUNS HERE

  return 0;
}
