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
    ListNode*solve(ListNode*head,int len,int k){
        if(len<k)return head;
        ListNode*curr=head;
        ListNode*forward;
        ListNode*prev=NULL;
        int cnt=0;
        while(cnt<k && curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            cnt++;
        }
        if(forward!=NULL){
        head->next=solve(forward,len-k,k);
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode*l1=head;
        while(l1!=NULL){
            len++;
            l1=l1->next;
        }
        if(len<k)return head;
        return solve(head,len,k);
    }
};