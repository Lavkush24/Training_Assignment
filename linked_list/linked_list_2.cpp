#include<iostream>
using namespace std;
#include<string>

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




/*
Given the head of a linked list, rotate the list to the right by k places.
*/

void removeLastMakeHead(Node**head) {
    Node *temp = *head;
    Node *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = *head;
    *head = temp;
}


int lengthOfList(Node* head) {
    int c = 0;
    Node *temp = head;
    while(temp!= NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

Node* rotateRight(Node* head, int k) {


    if(head == NULL || head->next == NULL) {
        return head;
    }

    k = k % lengthOfList(head);
    
    while(k > 0) {
        removeLastMakeHead(&head);
        k--;
    }
    return head;
}


/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/
Node* deleteDuplicates(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
        
    Node* curr = head->next;
    Node* prev = head;

    while(curr != NULL) {
        if(prev->val == curr->val) {
            prev->next = curr->next;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}