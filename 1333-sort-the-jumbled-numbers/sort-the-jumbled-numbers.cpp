class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int j=0;j<nums.size();j++){
          int temp=nums[j];
          int newnumber=0;
          int i=0;
          if(nums[j]==0){
            pq.push({mapping[0],j});
          }
          else{
          while(temp){
             int r=temp%10;
             newnumber+=pow(10,i)*mapping[r];
             i++;
             temp/=10;
          }
          pq.push({newnumber,j});
          }
        }
        vector<int>res;
        while(!pq.empty()){
          res.push_back(nums[pq.top().second]);
          pq.pop();
        }
        return res;
    }
};