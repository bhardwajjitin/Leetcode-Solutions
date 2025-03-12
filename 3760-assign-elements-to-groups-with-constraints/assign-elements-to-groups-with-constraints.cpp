class Solution {
    private:
    int solve(int number,unordered_map<int,int>&umap){
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(number);i++){
            if(number%i==0){
                int first=i;
                int second=number/i;
                if(umap.find(first)!=umap.end()){
                ans=min(ans,umap[first]);
                }
                if(umap.find(second)!=umap.end()){
                ans=min(ans,umap[second]);
                }
            }
        }
        return ans;
    }
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int,int>umap;
        vector<int>arr(groups.size());
        for(int i=0;i<elements.size();i++){
            if(umap.find(elements[i])==umap.end())
               umap[elements[i]]=i;
        }
        for(int i=0;i<groups.size();i++){
            int number=groups[i];
            int get=solve(number,umap);
            arr[i]=get==INT_MAX?-1:get;
        }
        return arr;
    }
};