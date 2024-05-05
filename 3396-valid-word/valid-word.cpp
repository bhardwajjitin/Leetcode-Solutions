class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        bool fldig=false,flvow=false,flcon=false,flup=false,fllow=false;
        for(int i=0;i<word.size();i++){
          if(word[i]=='$' || word[i]=='#' || word[i]=='@')return false;
            if(word[i]>='0' && word[i]<='9'){
                fldig=true;
            }
            else if(word[i]>='A' && word[i]<='Z'){
                flup=true;
                if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U'){
                    flvow=true;
                }
                else{
                    flcon=true;
                }
            }
            else if(word[i]>='a' && word[i]<='z'){
                fllow=true;
                 if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                    flvow=true;
                }
                else{
                    flcon=true;
                }
            }
        }
        return (fldig || flup || fllow) && (flvow &&flcon);
    }
};