class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long,long long>umap;
        for(int i=0;i<hours.size();i++){
          int temp=hours[i]%24;
          umap[temp]++;
        }
        long long sum=0;
        for(int i=0;i<=12;i++){
          long long temp=i;
          long long t=24-i;
          if(temp==0 || temp==12){
            sum+=(umap[temp]*(umap[temp]-1))/2;
          }
          else{
            sum+=umap[temp]*umap[t];
          }
        }
        return sum;
    }
};