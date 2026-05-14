class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>umap;
        int size=INT_MIN,i=0,j=0;
        while(j<fruits.size()){
            umap[fruits[j]]++;
            while(i<j && umap.size()>2){
                umap[fruits[i]]--;
                if(umap[fruits[i]]==0){
                    umap.erase(fruits[i]);
                }
                i++;
            }
            size=max(size,j-i+1);
            j++;
        }
        return size;
    }
};