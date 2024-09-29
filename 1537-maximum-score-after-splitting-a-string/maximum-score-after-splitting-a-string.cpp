class Solution {
public:
    int maxScore(string s) {
        vector<int>arr(s.size(),0);
        arr[0]=s[0]-'0';
        for(int i=1;i<s.size();i++){
            arr[i]=arr[i-1]+s[i]-'0';
        }
        int maxi=0;
        for(int i=0;i<s.size()-1;i++){
            int zeroes=i+1-arr[i];
            int ones=arr[s.size()-1]-arr[i];
            int sum=zeroes+ones;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};