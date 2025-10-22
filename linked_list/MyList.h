#include<iostream>
using namespace std;

#ifndef MyList_H
#define MyList_H

/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/

class Node {
    public: 
        int val;
        Node* next;

        Node(int v) {
            val = v;
            next = NULL;
        }
};

class MyList {
public:
    Node *head;

    MyList() {
        head = NULL;
    }
    
    int get(int index) {
        Node *temp = head;

        if(head == NULL) {
            return -1;
        }

        if(index == 0) {
            return temp->val;
        }

        while(temp != NULL && index > 0) {
            temp = temp->next;
            index--;
        }

        if(temp == NULL) {return -1;}

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *n = new Node(val);

        if(head == NULL) {
            head = n; 
            return ;
        }

        n->next = head;
        head = n;
    }
    
    void addAtTail(int val) {
        Node *temp = head;
        Node *n = new Node(val);

        if(head == NULL) {
            head = n;
            return ;
        }

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = n;
    }
    
    void addAtIndex(int index, int val) {
        Node *temp = head;
        Node *prev = NULL;
        Node *n = new Node(val);

        if(index == 0) {
            addAtHead(val);
            return;
        }

        while(temp != NULL && index > 0) {
            prev = temp;
            temp = temp->next;
            index--;
        }

        if(index > 0) { return ;}
        prev->next = n;
        n->next = temp;
    }
    
    void deleteAtIndex(int index) {
        Node *temp = head,*prev=NULL;

        if(head == NULL) {
            return ;
        }

        if(index == 0)  {
            head = head->next;
            delete temp;
            return ;
        }

        while(temp != NULL && index > 0) {
            prev = temp;
            temp = temp->next;
            index--;
        }

        if(temp == NULL) {
            return ;
        }
        prev->next = temp->next;
        delete temp;
    }
};


/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
*/

void deleteNode(Node* node) {
    Node *temp = node;
    while(node->next != NULL) {
        node->val = node->next->val;
        temp = node;
        node = node->next;
    }
    temp->next = NULL;
}



/*
Search an element in a Linked List (Iterative and Recursive)
*/
Node* searchRecursive(Node *head,int key) {
    if(head == NULL) {
        return NULL;
    }

    if(head->val == key) {
        return head;
    }

    searchRecursive(head->next,key);
}



Node* search(Node *head,int key) {
    Node *temp = head;

    while(temp != NULL) {
        if(temp->val == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/*
Given head of a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.
*/

int getCount(Node* head) {
    int length = 0;
    Node *temp = head;
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}


int getCountRecursive(Node *head) {
    if(head == NULL) {
        return 0;
    }

    return getCountRecursive(head->next) + 1;
}


#endif