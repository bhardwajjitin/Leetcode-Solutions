class Solution {
public:
    int countPairs(vector<int>& deli) {
        map<long long,long long>umap,occur;
        for(auto it:deli){
            umap[it]++;
        }
        long long ans=0;
        for(auto it:umap){
            long long val=it.first;
            for(int j=0;j<=21;j++){
                long long power=pow(2,j);
                if(umap.find(power-val)!=umap.end() && occur.find(power-val)==occur.end()){
                    if(power-val==val){
                    long long res=(it.second)*(it.second-1)/2;
                    ans+=res%1000000007;
                    }
                    else{
                    long long res=(it.second)*(umap[power-val]);
                    ans+=res%1000000007;
                    }
                }
            }
            occur[val]++;
        }
        return ans;
    }
};