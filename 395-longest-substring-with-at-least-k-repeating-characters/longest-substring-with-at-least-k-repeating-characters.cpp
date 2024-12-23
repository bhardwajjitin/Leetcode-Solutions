class Solution {
public:
    int longestSubstring(string s, int k) {
        for(int size=s.size();size>=1;size--){
            int i=0;
            int j=0;
            unordered_map<char,int>umap;
            while(j<s.size()){
                umap[s[j]]++;
                if(j-i+1<size)j++;
                else if(j-i+1==size){
                    bool flag=true;
                    for(auto it:umap){
                        if(it.second<k){
                            flag=false;
                            break;
                        }
                    }
                    if(flag)return size;
                    umap[s[i]]--;
                    if(umap[s[i]]==0){
                        umap.erase(s[i]);
                    }
                    i++;
                    j++;
                }
            }
        }
        return 0;
    }
};