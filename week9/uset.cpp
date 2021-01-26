#include <unordered_set>
#include <iostream>
int main() {
  using namespace std;
  unordered_set<string> s;
  s.insert("milk"); // insert an item, O(log n)
  s.insert("eggs");
  s.insert("flour");

  auto it = s.find("flour"); // O(log n) search time
  if (it!=s.end()) 
     s.erase(it);  // if we find it, remove it!
  
  return 0;
}
