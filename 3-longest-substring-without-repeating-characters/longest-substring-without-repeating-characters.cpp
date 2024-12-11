class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int i=0;
        int j=0;
        int length=0;
        while(j<s.size()){
            while(i<j && umap[s[j]]!=0){
                umap[s[i]]--;
                if(umap[s[i]]==0){
                    umap.erase(umap[s[i]]);
                }
                i++;
            }
            length=max(length,j-i+1);
            umap[s[j++]]++;
        }
        return length;
    }
};