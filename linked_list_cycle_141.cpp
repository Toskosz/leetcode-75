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
    bool hasCycle(ListNode *head) {
        ListNode* tartaruga = head;
        ListNode* coelho = head;

        while(coelho != NULL && coelho->next != NULL){
            tartaruga = tartaruga->next;
            coelho = coelho->next->next;
            if (coelho == tartaruga) {
                return true;
            }
        }
        return false;
    }
};
