class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>first(26,27);
        vector<int>last(26,27);
        int cnt=0;
        unordered_map<char,int>umap;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
           if(ch>='a' && ch<='z'){
            umap[ch]++;
            last[ch-'a']=i;
            }
        }
        for(int i=word.size()-1;i>=0;i--){
            char ch=word[i];
           if(ch>='A' && ch<='Z'){
            first[ch-'A']=i;
            }
        }
        set<char>st;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='A' && ch<='Z' && umap.find(ch+32)!=umap.end() && st.find(ch)==st.end()){
                if(first[ch-'A']>last[ch+32-'a']){
                    st.insert(ch);
                    cnt++;
                }   
            }
        }
        return cnt;
    }
};