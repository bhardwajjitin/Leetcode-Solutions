class Solution {
public:
    int minChanges(string s) {
        int minop=0;
        int cntzero=0;
        int cntone=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                cntone++;
            }
            else{
                cntzero++;
            }
            if(i%2!=0){
              minop+=min(cntzero,cntone);
              cntzero=0;
              cntone=0;
            }
            i++;
        }
        return minop;
    }
};