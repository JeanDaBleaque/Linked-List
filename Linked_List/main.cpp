#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    List<int> newList;
    newList.add(3);
    newList.add(2);
    newList.add(1);
    newList.printAll();
    List<int>::Node *ptr = newList.get(1);
    std::cout << "selected value: " << ptr->value << std::endl;
    newList.remove(1);
    newList.printAll();
    return 0;
}
