class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>precompute(values.size());
        for(int i=0;i<values.size();i++){
            int temp=values[i]+i;
            precompute[i]=temp;
        }
        priority_queue<pair<int,int>>pq;
        for(int j=1;j<values.size();j++){
            int res=values[j]-j;
            pq.push({res,j});
        }
        int maxi=INT_MIN;
        for(int i=0;i<values.size()-1;i++){
            int val=precompute[i];
            while(!pq.empty() && pq.top().second<=i){
                pq.pop();
            }
            int smallest=pq.top().first;
            int res1=val+smallest;
            maxi=max(maxi,res1);
        }
        return maxi;
    }
};