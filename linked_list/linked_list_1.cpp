#include<iostream>
using namespace std;

#include"MyList.h"


/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* revHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return revHead;
}


/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/

Node* middleNode(Node* head) {
    Node*slow = head,*fast = head;

    while(fast != NULL) {
        if(fast->next == NULL) {
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

