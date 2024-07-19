class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>arr(26,0);
        int maxf=0;
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<s.size()){
          arr[s[r]-'A']++;
          maxf=max(maxf,arr[s[r]-'A']);
          while((r-l+1)-maxf>k){
            arr[s[l]-'A']--;
            maxf=0;
            for(int i=0;i<26;i++){
              maxf=max(maxf,arr[i]);
            }
            l++;
          }
          if((r-l+1)-maxf<=k){
            maxlen=max(maxlen,(r-l+1));
          }
          r++;
        }
        return maxlen;
    }
};