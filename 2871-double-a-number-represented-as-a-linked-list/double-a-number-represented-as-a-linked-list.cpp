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
    ListNode*forward;
    ListNode*curr=head;
    ListNode*prev=NULL;
    while(curr!=NULL){
      forward=curr->next;
      curr->next=prev;
      prev=curr;
      curr=forward;
    }
    return prev;
  }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode*newHead=reverse(head);
        ListNode*temp=newHead;
        int carry=0;
        ListNode*prev;
        while(temp!=NULL){
          int sum=2*temp->val;
          temp->val=sum%10+carry;
          carry=sum/10;
          prev=temp;
          temp=temp->next;
        }
        if(carry>0){
          ListNode*res=new ListNode(carry);
          prev->next=res;
        }
        return reverse(newHead);
    }
};