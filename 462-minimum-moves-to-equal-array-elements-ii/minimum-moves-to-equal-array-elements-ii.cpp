class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int midEle = nums[nums.size()/2] , midEle2 = nums[ceil(nums.size()/2.0)-1];
        int ans1 = 0 , ans2 = 0;
        cout<<midEle<<" "<<midEle2<<endl;
        for(int i = 0 ; i < nums.size();i++){
          ans1 += abs(nums[i]-midEle);
          ans2 += abs(nums[i]-midEle2);
        }
        
        return min(ans1,ans2);
    }
};