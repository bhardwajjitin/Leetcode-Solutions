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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*newHead=new ListNode();
        ListNode*temp=head->next;
        int sum=0;
        ListNode*res=newHead;
        while(temp!=NULL){
          if(temp->val==0){
            res->val=sum;
            sum=0;
            if(temp->next!=NULL){
            ListNode*temp1=new ListNode();
            res->next=temp1;
            res=res->next;
            }
          }
          else{
            sum+=temp->val;
          }
          temp=temp->next;
        }
        return newHead;
    }
};