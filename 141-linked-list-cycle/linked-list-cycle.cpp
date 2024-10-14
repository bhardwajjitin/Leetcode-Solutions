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
        if(head==NULL || head->next==NULL)return false;
        ListNode*slow=head;
        ListNode*fast=head->next;
        if(head->next==head)return true;
        while(fast!=NULL){
            if(fast->next!=NULL){
                fast=fast->next;
            }
            fast=fast->next;
            slow=slow->next;
            if(slow==fast)return true;
        }
        return false;
    }
};