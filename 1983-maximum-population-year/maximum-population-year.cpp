class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       vector<int>arr(101,0);
       int ans;
       int maxi=INT_MIN;
       for(int i=0;i<logs.size();i++){
        int first=logs[i][0]-1950;
        int last=logs[i][1]-1950;
        for(int year=first;year<last;year++){
            arr[year]+=1;
        }
       }
       for(int i=0;i<arr.size();i++){
        if(maxi<arr[i]){
            maxi=arr[i];
            ans=i+1950;
        }
       }
       return ans;
    }
};