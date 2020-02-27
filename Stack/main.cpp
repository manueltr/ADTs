#include "List.h"
#include "TwoStacksInOneArray.h"
#include <iostream>
#include <vector>
using namespace std;


// Question 3 working algorithms

bool detect_cycle1(List<int>::iterator start, List<int>::iterator end)
{
    vector<List<int>::iterator> check;
    List<int>::iterator current = start;

    while(current != end)
    {
        for(List<int>::iterator temp: check)
            if(current == temp)
                return true;
            
            check.push_back(current);

            current++;
    }
    return false;

}

bool detect_cycle2(List<int>::iterator start, List<int>::iterator end) {
    List<int>::iterator slow_itr = start;
    List<int>::iterator fast_itr = start;

    do
    {
        slow_itr++;
        fast_itr++;
        fast_itr++;

        if(slow_itr == fast_itr)
            return true;

    } while(slow_itr != fast_itr && fast_itr != end && fast_itr+1 != end) ;

    return false;
}

int main() {



    // Question 1 testing

    cout << "question 1 \n" << endl;
    List<int> test;

    for(int i = 1; i <= 6; i++)
        test.push_back(i);

    // const_iterator operator+ test
    List<int>::const_iterator temp = test.begin();
    cout << *(temp+5) << endl;
    cout << endl;

    for(List<int>::iterator itr = test.begin(); itr != test.end(); itr++)
        cout << *itr << endl;

    cout << "-=-=-=-==--=-=-=" << endl;


    // Reverse_iterator test
    for(List<int>::reverse_iterator itr = test.rbegin(); itr != test.rend(); itr++)
        cout << *itr << endl;
    
    cout << endl;
    
    // Question 2 testing
    cout << "question 2 \n" << endl;

    
    // of size 8, default parameter of 10, can be change to whatever size;
    TwoStacksInOneArray myStack(8);

    myStack.push1(1);
    myStack.push1(2);
    myStack.push1(3);
    myStack.push1(4);
    myStack.push1(5);
    myStack.push2(88);
    myStack.push2(89);
    myStack.push2(90);

    // pushing should give error
    cout << "testing stack overflow" << endl;
    myStack.push1(1);
    cout << endl;

    // testing top1 and top2;
    cout << "top of stack1 = " << myStack.top1() << "      top of stack 2 = " << myStack.top2() << endl;


    // using pop remove and print all elements of stacks;
    cout << "popping stack 1" << endl;
    int tempSize = myStack.size1();
    for(int i = 0; i < tempSize; i++) {
        cout << myStack.pop1() << "  size after popping = " << myStack.size1() << endl;
    }
    cout << endl;


    cout << "popping stack 2" << endl;
    tempSize = myStack.size2();
    for(int i = 0; i < tempSize; i++)
        cout << myStack.pop2() << "  size after popping = " << myStack.size2() << endl;
    cout << endl;


    // if we pop it should throw an empty error, will return 0, same for top()
    cout << "testing empty error" << endl;
    myStack.pop1();
    myStack.top2();



    // testing question 3
    cout << endl;
    cout << "question 3 \n" << endl;

    //create list
    List<int> testLoop;
    testLoop.push_back(1);
    testLoop.push_back(2);
    testLoop.push_back(3);
    testLoop.push_back(4);
    testLoop.push_back(5);
    testLoop.push_back(6);
    cout << endl;
    cout << "testing detect loop- when no loop preset:     (no loop = 0 loop = 1)" << endl;

    // check if there is loop
    cout << detect_cycle1(testLoop.begin(),testLoop.end()) << endl;
    cout << detect_cycle2(testLoop.begin(),testLoop.end()) << endl;

    cout << endl;
    cout << "-=-=-=-=-=--=-=-=-=--=-=-" << endl;
    cout << endl;

    // getting an itr to set loop to
    List<int>::iterator itr = testLoop.begin();
    for(int i = 0; i < 2; i++)
        itr++;
    // will set tail->prev->next to itr
    // function in "List.h" line 398
    testLoop.createLoop(itr);

    cout << "testing detect loop- loop is present:" << endl;
    cout << detect_cycle1(testLoop.begin(),testLoop.end()) << endl;
    cout << detect_cycle2(testLoop.begin(),testLoop.end()) << endl;

    // itr = testLoop.begin();
    
    
    // for(int i = 0; i < 100; i++) {
    //     cout << *itr << endl;
    //     itr++;
    // }

    






    return 0;
}