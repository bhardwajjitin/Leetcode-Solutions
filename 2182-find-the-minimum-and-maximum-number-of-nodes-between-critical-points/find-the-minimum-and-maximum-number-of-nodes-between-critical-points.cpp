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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*temp=head->next;
        ListNode*prev=head;
        int cnt=2;
        int first=-1;
        int last=-1;
        int mini=INT_MAX;
        int maxi=-1;
        while(temp->next!=NULL){
          if((prev->val < temp->val && temp->next->val<temp->val) || (prev->val > temp->val && temp->next->val > temp->val)){
              if(first!=-1){
                maxi=max(maxi,cnt-first);
              }
              if(last!=-1){
                mini=min(mini,cnt-last);
              }
              if(first==-1){
                first=cnt;
              }
              last=cnt;
          }
          cnt++;
          temp=temp->next;
          prev=prev->next;
        }
        if(mini==INT_MAX)mini=-1;
        return {mini,maxi};
    }
};