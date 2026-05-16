/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // reached meeting point 
                slow = head; //  reset the slow's position to start while keeping the fast at meeting point 
                while (slow != fast) {
                    //now both are moving at same speed
                    slow = slow->next; 
                    fast = fast->next;
                }
                return slow;//or fast as both are point the same spot
            }
        }

        return NULL;
    }
};