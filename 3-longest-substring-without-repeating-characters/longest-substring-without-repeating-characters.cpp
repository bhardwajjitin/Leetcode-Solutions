class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int i=0,j=0,size=0;
        while(j<s.size()){
            while(i<j && umap.find(s[j])!=umap.end()){
                umap[s[i]]--;
                if(umap[s[i]]==0){
                    umap.erase(s[i]);
                }
                i++;
            }
            size=max(size,j-i+1);
            umap[s[j]]++;
            j++;
        }
        return size;
    }
};