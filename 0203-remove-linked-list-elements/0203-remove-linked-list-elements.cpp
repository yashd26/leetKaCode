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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        
        ListNode *ptr = head;
        while(ptr && ptr -> val == val) {
            ptr = ptr -> next;
            head = head -> next;
        }
        
        while(ptr && ptr -> next) {
            if (ptr -> next -> val == val) {
                ptr -> next = ptr -> next -> next;
                continue;
            }
            ptr = ptr -> next;
        }
        
        return head;
    }
};