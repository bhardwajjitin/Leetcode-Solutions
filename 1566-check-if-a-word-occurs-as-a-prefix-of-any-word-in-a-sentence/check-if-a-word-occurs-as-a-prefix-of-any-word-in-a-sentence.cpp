class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
      string temp="";
      int cnt=0;
        for(int i=0;i<sentence.size();i++){
          if(sentence[i]!=' '){
            temp+=sentence[i];
          }
          else{
            cnt++;
            if(temp.starts_with(searchWord)){
              return cnt;
            }
            temp="";
          }
        }
        if(temp.starts_with(searchWord)){
            cnt++;
            return cnt;
        }
        return -1;
    }
};