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
    void deleteNode(ListNode* node) {
        while(node) {
            if (!node -> next -> next) {
                node -> val = node -> next -> val;
                node -> next = NULL;
                node = node -> next;
                continue;
            }
            if (node && node -> next) {
                node -> val = node -> next -> val;
            }
            node = node -> next;
        }
    }
};