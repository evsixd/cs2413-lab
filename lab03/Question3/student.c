// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    struct ListNode* leader = head;
    struct ListNode* follower = head;

    while(1) {
        if(leader == NULL || leader->next == NULL || leader->next->next == NULL) {
            return false;
        }
        leader = leader->next->next;
        follower = follower->next;

        if(leader == follower) {
            return true;
        }
    }
    return false;
}