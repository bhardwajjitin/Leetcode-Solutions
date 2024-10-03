class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>prefixofi;
        int sizeofarray=nums.size();
        long long totalsum = 0;
        for(auto value : nums)totalsum = (totalsum+value)%p;
        cout<<totalsum<<endl;
        totalsum%=p;
        if(totalsum%p==0)return 0;
        vector<int>prefixsum(sizeofarray+1,0);
        prefixofi[0]=-1;
        int answer=INT_MAX;
        for(int index=0;index<sizeofarray;index++){
            prefixsum[index+1]=(prefixsum[index]+nums[index])%p;
            int valuetofind = (prefixsum[index+1]-totalsum+p)%p;
            if(prefixofi.find(valuetofind)!=prefixofi.end()){
                answer=min(answer,index-prefixofi[valuetofind]);

            }
            prefixofi[prefixsum[index+1]%p]=index;
        }
        return answer==INT_MAX or answer == nums.size() ?-1:answer;
    }
};