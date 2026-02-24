// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    struct ListNode* follower = head;

    int counter = 0;
    for(struct ListNode* leader = head->next; leader != NULL; leader = leader->next) {
        counter++;
        if(counter == 2) {
            follower = follower->next;
            counter = 0;
        }
    }
    if(counter == 1) {
        return follower->next->val;
    }
    return follower->val;
}