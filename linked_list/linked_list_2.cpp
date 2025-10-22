#include<iostream>
using namespace std;

#include"MyList.h"


/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node *sum = NULL;
    Node *end = sum;
    int carry = 0;

    int add = l1->val + l2->val + carry;

    carry = add / 10;
    Node *n = new Node(add%10);
    sum = n;
    end = sum;
    l1 = l1->next;
    l2 = l2->next;
    
    while(l1 != NULL && l2 != NULL) {
        int add = l1->val + l2->val + carry;

        carry = add / 10;
        Node *n = new Node(add%10);
        end->next = n;
        end = n;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL) {
        int add = l1->val + carry;
        carry = add / 10;
        Node *n = new Node(add%10);
        end->next = n;
        end = n;
        l1 = l1->next;
    }

    while(l2 != NULL) {
        int add = l2->val + carry;
        carry = add / 10;
        Node *n = new Node(add%10);
        end->next = n;
        end = n;
        l2 = l2->next;
    }

    if(carry != 0) {
        Node *n = new Node(carry);
        end->next = n;
        end = n;
    }

    return sum;
}
