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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) {
            return head;
        }

        ListNode *ptr = head, *ptr1 = head -> next, *ptr2 = ptr1;
        while(ptr -> next && ptr1 -> next) {
            ListNode *tmp = ptr -> next -> next;
            ptr -> next = tmp;
            ListNode *tmp1 = ptr1 -> next -> next;
            ptr1 -> next = tmp1;
            ptr = tmp;
            ptr1 = tmp1;
        }
        
        ptr -> next = ptr2;
        return head;
    }
};