

#include <iostream>
#include <string>

template <typename T>
class Array {
public:
  T array[100];

  Array(T initval) {
    for(int i=0; i<100; i++) array[i] = initval;
  }

  T max() {
    T tmp = array[0];

    for(int i=1; i<100; i++)
      if (array[i] > tmp)
	tmp = array[i];

    return tmp;    
  }
};

int main()
{
  Array<std::string> a("");
  Array<int> i(0);

  a.array[0] = "hello";

  std::cout << a.max() << std::endl;

  return 0;
}
