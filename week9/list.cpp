#include <string>
#include <list>
using namespace std;
using iterator = list<string>::iterator;
int main() {
  list<string> l; // declare a list for holding strings
  l.push_back("eggs");
  l.push_back("milk");

  // use an iterator to insert into the middle
  list<string>::iterator it = l.begin(); // it points to “eggs”

  it++; // now it points to “milk”

  l.insert(it, "flour"); // insert flour before “milk”, cost O(1)

  return 0;
}
