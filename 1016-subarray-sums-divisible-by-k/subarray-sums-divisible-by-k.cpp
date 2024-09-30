class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // vector<int>pre(nums.size());
        // unordered_map<int,int>umap;
        // umap[0]++;
        // pre[0]=nums[0];
        // umap[pre[0]%k]++;
        // for(int i=1;i<nums.size();i++){
        //     pre[i]=pre[i-1]+nums[i];
        //     umap[pre[i]%k]++;

        // }
        // int cnt=0;
        // for(auto it:umap){
        //         cnt+=(it.second*(it.second-1))/2;
        // }
        // return cnt;

        vector<int>prefixSum(nums.size(),0);
        unordered_map<int,int>modCount;
        int ans = 0;
        prefixSum[0] += nums[0];
        modCount[0]++;
        ans += modCount[(nums[0])%k]++;

        for(int index = 1 ; index < nums.size() ; index++){
            prefixSum[index] = prefixSum[index-1]+nums[index];
            int currentModResult = (prefixSum[index])%k;
            int subtractingRemainder = currentModResult;
            int addingKMinusRemainder = -(k-currentModResult);
            if(currentModResult < 0){
                addingKMinusRemainder = (k+currentModResult);
            }
            ans += modCount[subtractingRemainder];
            ans += modCount[addingKMinusRemainder];
            modCount[currentModResult]++;
        }
        return ans;
    }
};