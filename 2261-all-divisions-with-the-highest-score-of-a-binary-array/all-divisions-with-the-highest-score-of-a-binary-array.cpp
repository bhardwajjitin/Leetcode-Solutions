class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        int cntzero=nums[0]==0?1:0;
        left[0]=cntzero;
        int cntone=nums[nums.size()-1]==1?1:0;
        right[n]=cntone;
        for(int i=1;i<=n;i++){
            if(nums[i-1]==0){
                left[i]=1+left[i-1];
            }
            else{
                left[i]=left[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                right[i]=1+right[i+1];
            }
            else{
                right[i]=right[i+1];
            }
        }
        vector<int>res;
        int maxi=-1;
        for(int i=0;i<=n;i++){
            int temp=left[i]+right[i];
            maxi=max(maxi,temp);
        }
        for(int i=0;i<=n;i++){
            int temp=left[i]+right[i];
            if(temp==maxi){
                res.push_back(i);
            }
        }
        return res;
    }
};