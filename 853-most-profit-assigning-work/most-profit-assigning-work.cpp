class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        for(int i=0;i<worker.size();i++){
          int maxi=INT_MIN;
          for(int j=0;j<diff.size();j++){
            if(diff[j]<=worker[i]){
              maxi=max(maxi,profit[j]);
            }
          }
          if(maxi!=INT_MIN)
          ans+=maxi;
        }
        return ans;
    }
};