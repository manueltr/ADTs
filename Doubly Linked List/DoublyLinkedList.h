#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T>
class List {
    private:

        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(T data, Node* n = nullptr, Node* p = nullptr) : data(data), next(n), prev(p) {}
        };

        Node* head;
        Node* tail;
        int len;


    public:
        List() {
            head = nullptr;
            tail = nullptr;
            len = 0;
        }

        void push_back(T data) {

            if(head == nullptr) {
                head = new Node(data);
                tail = head;
            }
            else {
                tail->next = new Node(data);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }


        T pop() {

            if(head == nullptr) {
                return NULL;
            }
            else if(head == tail) {
                T data = tail->data;
                delete tail;
                tail = nullptr;
                head = nullptr;
                return data;
            }
            else {
                T data = tail->data;
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
                return data;
            }
        }

        int size() {
            return len;
        }
   
        void clear() {
            Node* current = head;
            while(current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
            tail = head;
            
        }

        void print() {
            Node* current = head;
            while(current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        ~List(){
            clear();
        }
};

#endif