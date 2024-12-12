class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       priority_queue<int>pq(gifts.begin(),gifts.end());
       while(k--){
        int top=pq.top();
        pq.pop();
        pq.push(floor(sqrt(top)));
       }
       long long sum=0;
       while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
       }
       return sum;
    }
};