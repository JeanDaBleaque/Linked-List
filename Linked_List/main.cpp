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
    List<int>::Node *ptr = newList.getHead();
    //cout << ptr->value << endl;
    newList.remove(ptr);
    newList.printAll();
    return 0;
}
