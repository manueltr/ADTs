#ifndef TWO_STACKS_IN_ONE_ARRAY_H
#define TWO_STACKS_IN_ONE_ARRAY_H

#include <iostream>
using namespace std;

class TwoStacksInOneArray {

    private:
    int* stacksArray;
    int size;
    int stackOnePosition;
    int stackTwoPosition;

    public:
        //default size 10
        TwoStacksInOneArray(int size = 10) {

            stacksArray = new int[size];
            this->size = size;
            stackOnePosition = -1;
            stackTwoPosition = size;
        }

        //stack one push
        void push1(int k) {

            if(!IsFull()) {
                stackOnePosition++;
                stacksArray[stackOnePosition] = k;
            }
            else
                cout << "Error: Stack overflow" << endl;
        }

        //stack two push
        void push2(int k) {

            if(!IsFull()) {
                stackTwoPosition--;
                stacksArray[stackTwoPosition] = k;
                
            }
            else
                cout << "Error: Stack overflow" << endl;
        }

        //stack one pop
        int pop1() {
            if(stackOnePosition == -1) {
                cout << "stack 1 is empty" << endl;
                return 0;
            }
            else 
            {
                int temp = stacksArray[stackOnePosition];
                stackOnePosition--;
                return temp;
            }
        }

        int pop2() {
            if(stackTwoPosition == size) {
                cout << "stack 2 is empty" << endl;
                return 0;
            }
            else
            {
                int temp = stacksArray[stackTwoPosition];
                stackTwoPosition++;
                return temp;
            }
        }

        int top1() {

            if(stackOnePosition == -1) {
                cout << "stack 1 is empty" << endl;
                return 0;
            }
            else {
                return stacksArray[stackOnePosition];
            }
        }

        int top2() {

            if(stackTwoPosition == size) {
                cout << "stack 2 is empty" << endl;
                return 0;
            }
            else {
                return stacksArray[stackTwoPosition];
            }
        }

        int size1() { return stackOnePosition+1; }

        int size2() { return abs(stackTwoPosition - size); }


        bool IsFull() {
            if(stackOnePosition - stackTwoPosition == -1)
                return true;
            else
                return false; 
        }

        int position() { return stackTwoPosition; }

        ~TwoStacksInOneArray() {
            delete stacksArray;
        }


};


#endif