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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return NULL;
        }
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        
        for(int i = 0; i < n; ++i) {
            ptr1 = ptr1 -> next;
        }
        while(ptr1 && ptr1 -> next) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        if (!ptr1 && ptr2 == head) {
            return head -> next;
        }
        ptr2 -> next = ptr2 -> next -> next;
        return head;
    }
};