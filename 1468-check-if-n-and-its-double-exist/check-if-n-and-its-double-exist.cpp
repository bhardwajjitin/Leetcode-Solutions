class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>umap;
        for(auto it:arr){
            umap[it]++;
        }
        for(auto it:arr){
            if(umap.find(2*it)!=umap.end()){
                if(it==2*it && umap[it]>1){
                   return true;
                }
                else if(it!=2*it){
                    return true;
                }
            }
        }
        return false;
    }
};