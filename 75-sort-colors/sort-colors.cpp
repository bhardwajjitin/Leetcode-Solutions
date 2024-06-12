class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntzero=0,cntone=0,cnttwo=0;
        for(auto it:nums){
          if(it==0)cntzero++;
          if(it==1)cntone++;
          if(it==2)cnttwo++;
        }
        int i=0;
        while(cntzero!=0){
          nums[i]=0;
          i++;
          cntzero--;
        }
         while(cntone!=0){
          nums[i]=1;
          i++;
          cntone--;
        }
         while(cnttwo!=0){
          nums[i]=2;
          i++;
          cnttwo--;
        }
    }
};