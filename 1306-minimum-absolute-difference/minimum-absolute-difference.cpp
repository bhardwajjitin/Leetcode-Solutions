class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
          mini=min(mini,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>>res;
        for(int i=1;i<arr.size();i++){
          if(abs(arr[i]-arr[i-1])==mini){
            res.push_back({arr[i-1],arr[i]});
          }
        }
        return res;
    }
};