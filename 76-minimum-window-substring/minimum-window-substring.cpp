class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int>umap;
        for(int i=0;i<t.size();i++){
            umap[t[i]]++;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int maxi=INT_MAX;
        int index=-1;
        while(r<s.size()){
            if(umap[s[r]]>0)cnt++;
            umap[s[r]]--;
            
            while(cnt==t.size()){
                if(r-l+1<maxi){
                    maxi=r-l+1;
                    index=l;
                }
                umap[s[l]]++;
                if(umap[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        if(index==-1)return "";
        return s.substr(index,maxi);
    }
};