/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* list1) {
       ListNode* curr = list1;
       ListNode* nxt = NULL;
       ListNode* prv = NULL;
       while(curr != NULL) {
          nxt = curr->next;
          curr->next = prv;
          prv = curr;
          curr = nxt;
       }
       return prv; 
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* l1 = head;

        // Merge
        while(l2) {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2; 
        }
    }
};
