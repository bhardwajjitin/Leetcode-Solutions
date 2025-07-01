class Solution {
private:
    int solve(vector<long long>&arr,int value){
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=value){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    void insert_at_index(vector<long long>&arr,long long value){
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>value){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        arr.insert(arr.begin()+low,value);
        return;
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<long long>arr;
        int answer=0;
        arr.push_back((long long)nums[nums.size()-1]*2);
        for(int index=nums.size()-2;index>=0;index--){
            long long value=(long long)nums[index]*2;
            int getindex=solve(arr,nums[index]);
            if(getindex!=-1){
                answer+=getindex;
            }
            insert_at_index(arr,value);
        }
        return answer;
    }
};