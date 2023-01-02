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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr = new ListNode(1);
        
        if (!list1 && !list2) {
            return NULL;
        }
        else if(!list1) {
            return list2;
        }
        else if(!list2) {
            return list1;
        }
        else {
            ListNode *ptr1 = ptr;
            while(ptr1 && list1 && list2) {
                if (list1 -> val <= list2 -> val) {
                    ptr1 -> next = list1;
                    ptr1 = list1;
                    list1 = list1 -> next;
                }
                else {
                    ptr1 -> next = list2;
                    ptr1 = list2;
                    list2 = list2 -> next;
                }
            }
            if (list1) {
                while(ptr1 && list1) {
                    ptr1 -> next = list1;
                    ptr1 = list1;
                    list1 = list1 -> next;   
                }
            }
            else if(list2) {
                while(ptr1 && list2) {
                    ptr1 -> next = list2;
                    ptr1 = list2;
                    list2 = list2 -> next;   
                }
            }
        }
        
        return ptr -> next;
    }
};