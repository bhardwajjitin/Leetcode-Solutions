class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.size()==1)return true;
        char firstchar=sentence[0];
        char lastchar;
        bool flag=false;
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(flag){
               if(lastchar!=sentence[i])return false;
               flag=false;
            }
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }
            else{
                lastchar=temp[temp.size()-1];
                temp="";
                flag=true;
            }
        }
         lastchar=temp[temp.size()-1];
        if(lastchar!=firstchar)return false;
        return true;
    }
};