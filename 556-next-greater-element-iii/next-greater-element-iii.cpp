class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>ans;
        int temp=n;
        while(temp!=0){
          int r=temp%10;
          ans.push_back(r);
          temp/=10;
        }
        reverse(ans.begin(),ans.end());
        next_permutation(ans.begin(),ans.end());
        long long  sum=0;
        for(int i=0;i<ans.size();i++){
          sum=sum*10+ans[i];
        }
        if(sum>INT_MAX || sum<=n)return -1;
        return sum;
    }
};