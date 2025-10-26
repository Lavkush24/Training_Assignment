#include<iostream>
using namespace std;

#define MYSTACK_H
#define S 100
#ifdef MYSTACK_H

/*
----------------------------Stack implementation --------------------------
*/

template <typename T> class Mystack {
    T *arrayStack;
    int top = -1;

    public:
        Mystack() {
            arrayStack = new T[S];
        } 

        bool isEmpty() {
            return top == -1;
        };

        bool isFull() {
            return top == S-1;
        };

        void push(T element) {
            if(isFull()) {
                cout<<"Stack is Full"<<endl;
                return ;
            }

            arrayStack[top+1] = element;
            top++; 
        };

        T pop() {
            if(isEmpty()) {
                cout<<"Stack is Empty"<<endl;
                exit(1);
            }

            T temp = arrayStack[top];
            top--;
            return temp;
        };

        void display() {
            for(int i=0; i<top; i++) {
                cout<<arrayStack[i]<<" ";
            }
            cout<<arrayStack[top]<<endl;
        }

        ~Mystack() {
            delete [] arrayStack;
        }
};

#endif