#include <iostream>
#include <string>

using Item = std::string;


class List
{
private:
  class ListNode
  {
  public:
    Item item;
    ListNode *next;
    ListNode(Item a, ListNode *n=nullptr):item(a),next(n) {}
  };
  
  ListNode *head;
  ListNode *tail;

public:

  // declared public inside List
  class iterator {
  private:
    ListNode *node; // private, implementation details hidden
  public: 
    iterator(ListNode *n=nullptr) { node = n; }
    Item& getItem() { return node->item; }
    void next() { node = node->next; }
    bool operator==(const iterator &other) {
      return node == other.node;
    }
    // check if two iterators are not equal
    bool operator != (const iterator &other) {
      return node != other.node;
    }
    iterator& operator++() 
    {
      next();
      return *this;
    }

    friend class List;
  };
  
  iterator begin() { return iterator(head); }  // in List
  iterator end() { return iterator(nullptr); } // in List

  List():head(nullptr),tail(nullptr) {}
  List(const List &other);
  
  void append(Item a);
  bool empty() { return head==nullptr; }
  bool remove(Item &copy);

  void removeAfter(iterator it) ;
  void insertAfter(iterator it, Item item);
};

List::List(const List &other) 
{  // initialize head and tail
   head = nullptr;
   tail = nullptr;
   ListNode *tmp = other.head;
   // loop over other list’s nodes and append them in same order
   while(tmp) { 
      append(tmp->item);
      tmp = tmp->next;
   }
}


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


bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->item; // return copy
      ListNode *tmp = head->next;
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==nullptr) // removed last element 
	tail = nullptr;
      return true;
    }
  return false; // nothing in list
}

void List::removeAfter(List::iterator it) // pseudocode in zyBook 11.4
{
  if (empty() || it.node==tail) return; // defensive action, nothing to do
  else if (it.node==nullptr) // special case to remove head, it’s not after any node
    {
      ListNode *remove = head;               // will remove the head      
      head = head->next;      // advance head 
      if (head==NULL) tail = NULL; // if head is NULL now, list is empty
      delete remove;               // delete removed node
    }
  else // normal case, if not the head, then simply disconnect the node
    {
      ListNode *tmp = it.node;
      ListNode *remove = tmp->next; // next node to be removed
      if (tail == remove) 
	tail = tmp;                 // if removing tail, update tail
      
      tmp->next = remove->next;   // point around node to be removed   
      delete remove;                // delete the removed node
    }
}

void List::insertAfter(List::iterator it, Item item) // pseudocode in zyBook 11.3
{
  if (it.node==NULL) { // special case to insert at the head
    // point new node at current head of list
    ListNode *node = new ListNode(item,head);
    if (head==NULL) { // if head was NULL, tail was also NULL
      tail = node;   // new node is now the tail
      head = node;   // new node is now the head
    } else {
      head = node;   // update head to new node
    }
  }
  else // insert in the middle or at the tail
    {
      ListNode *node = new ListNode(item,it.node->next);
      it.node->next = node;
      if (tail==it.node) tail = node;     
    }
}



int main()
{
  List l;

  l.append("milk");
  l.append("eggs");
  l.append("coffee");
  l.append("bread");

  Item rm;
  int i=1;
  while(l.remove(rm))
    {
      std::cout << i++ << ". " << rm << std::endl;
    }

  l.append("milk");
  l.append("eggs");
  l.append("coffee");
  l.append("bread");

  List::iterator it = l.begin();

  while(it!=l.end()) {
    Item &a = it.getItem();
    std::cout << a << std::endl;
    ++it;
  }
  
  return 0;
}
