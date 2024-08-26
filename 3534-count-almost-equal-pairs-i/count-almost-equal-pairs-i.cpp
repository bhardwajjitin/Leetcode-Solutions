class Solution {
    private:
    bool solve(int i,int j,vector<int>&nums){
        string first=to_string(nums[i]);
        string second=to_string(nums[j]);
        
        while(first.length()<second.length()){
          first="0"+first;
        }
        while(second.length()<first.length()){
          second="0"+second;
        }
        int n=first.size();
        int diff=0;
        int firstdiff=-1;
        int seconddiff=-1;
        for(int k=0;k<n;k++){
            if(first[k]!=second[k]){
                diff++;
            if(diff==1){
                firstdiff=k;
            }
            else if(diff==2){
                seconddiff=k;
            }
            else return false;
            }
        }
        if(diff==2){
        swap(first[firstdiff],first[seconddiff]);
        return first==second; 
        }
        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j] || solve(i,j,nums))
                   cnt++;
            }
        }
        return cnt;
    }
};