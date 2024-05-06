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
  private:
  ListNode*reverse(ListNode*head){
    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*forward;
    while(curr!=NULL){
      forward=curr->next;
      curr->next=prev;
      prev=curr;
      curr=forward;
    }
    return prev;
  }
public:
    ListNode* removeNodes(ListNode* head) {
      if(head==NULL || head->next==NULL)return head;
      ListNode*temp=reverse(head);
      ListNode*newHead=NULL;
      ListNode*res;
      int maxi=0;
      while(temp!=NULL){
          if(temp->val>=maxi){
            maxi=temp->val;
            if(newHead==NULL){
              newHead=temp;
              res=newHead;
            }
            else{
                res->next=temp;
                res=res->next;
            }
          }
          temp=temp->next;
      }
      res->next=NULL;
      newHead=reverse(newHead);
      return newHead;
    }
};