#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;


int main() {

    List<int> doubleLinked;
    doubleLinked.push_back(1);
    doubleLinked.push_back(2);
    doubleLinked.push_back(3);

    // doubleLinked.print();
    // cout << doubleLinked.pop() << endl;
    // doubleLinked.print();
    // cout << doubleLinked.pop() << endl;
    // doubleLinked.print();
    // cout << doubleLinked.pop() << endl;
    // doubleLinked.print();

    doubleLinked.clear();
    doubleLinked.print();
    doubleLinked.push_back(10);
    doubleLinked.print();

}