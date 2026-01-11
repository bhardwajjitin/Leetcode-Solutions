class Solution {
    private:
    long long solve(vector<long long>&pre_sum,long long damage,int req,int index){
        int low=0;
        int high=index-1;
        long long ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pre_sum[mid]+damage>=req){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        vector<long long>dam_arr(n),pre_sum(n);
        for(int i=0;i<n;i++){
            hp-=damage[i];
            dam_arr[i]=hp;
            pre_sum[i]=i>0?pre_sum[i-1]+damage[i]:damage[i];
        }
        long long ans=0;
        for(long long i=n-1;i>=0;i--){
            long long getindex=solve(pre_sum,dam_arr[i],requirement[i],i);
            if(dam_arr[i]>=requirement[i]){
                if(getindex!=-1){
                    ans+=i-getindex+1;
                }
                else{
                    ans+=1;
                }
            }
            else{
                if(getindex!=-1){
                    ans+=i-getindex;
                }
            }
        }
        return ans;
    }
};