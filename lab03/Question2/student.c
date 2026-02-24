// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {

      struct ListNode* one = NULL;
      struct ListNode* returning = NULL;
      struct ListNode* prior = NULL;

      for(struct ListNode* leader = head; leader != NULL; leader = leader->next) {
            if(one == NULL) {
                  one = leader;
                  continue;
            } else {
                  one->next = leader->next;

                  if(returning == NULL) {
                        returning = leader;
                  }

                  if(prior == NULL) {
                        prior = one;
                  } else {
                        prior->next = leader;
                        prior = one;
                  }

                  leader->next = one;
                  leader = one;
                  one = NULL;
            }

      }

      if(returning == NULL) {
            return head;
      }
      return returning;
}