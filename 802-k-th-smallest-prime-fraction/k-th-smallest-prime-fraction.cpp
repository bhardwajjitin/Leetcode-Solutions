class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<arr.size();i++){
          for(int j=i+1;j<arr.size();j++){
            double temp=(double)arr[i]/(double)arr[j];
            pq.push({temp,{arr[i],arr[j]}});
          }
        }
        while(k-1!=0 && !pq.empty()){
          pq.pop();
          k--;
        }
        int first=pq.top().second.first;
        int second=pq.top().second.second;
        return {first,second};
    }
};