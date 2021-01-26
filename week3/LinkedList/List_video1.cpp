#include <iostream>
#include <string>

using Item = std::string;

class ListNode
{
public:
  Item item;
  ListNode *next;
  ListNode(Item a):item(a),next(nullptr) {}
};

class List
{
private:
  ListNode *head;
  ListNode *tail;

public:
  List():head(nullptr),tail(nullptr) {}

  void append(Item a);
};

void List::append(Item a) 
{
  ListNode *node = new ListNode(a);
  if (head==nullptr) { 
    // list is empty, so set head and 
    // tail to be node
    head = node;
    tail = node;
  } else {
    // put new node at end of list
    tail->next = node;
    tail = node;
  }
}

int main()
{
  List l;

  l.append("milk");
  l.append("eggs");
  l.append("bread");

  return 0;
}
