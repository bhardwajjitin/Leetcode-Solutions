class Solution {
public:
    int minimumPushes(string word) {
        vector<int>occur(26,0);
        for(auto it:word){
            occur[it-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            pq.push({occur[i],'a'+i});
        }
        int start=1;
        int temp=8;
        int answer=0;
        while(!pq.empty()){
            auto it=pq.top();
            if(it.first!=0){
                answer+=it.first*start;
                temp--;
                if(temp==0){
                    temp=8;
                    start++;
                }
            }
            pq.pop();
        }
        return answer;
    }
};