class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int ans=0;
      for(int i=0;i<32;i++){
        int count=0;
        int bit=1<<i;
        for(auto it:nums){
            if(bit&it)count++;
          }
          if(count%3!=0){
            ans|=bit;
          }
      }
      return ans;
    }
};