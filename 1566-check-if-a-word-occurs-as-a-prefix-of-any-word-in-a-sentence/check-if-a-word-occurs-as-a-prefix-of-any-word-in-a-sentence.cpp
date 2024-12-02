class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp = "";
        int k=1;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                bool flag = true;
                if(searchWord.size()<=temp.size()){
                for (int j = 0; j < min(searchWord.size(), temp.size()); j++) {
                    if (searchWord[j] != temp[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return k;
                }
                temp = "";
                k++;
            } else {
                temp += sentence[i];
            }
        }
        if(searchWord.size()<=temp.size()){
        bool flag = true;
        for (int j = 0; j < min(searchWord.size(), temp.size()); j++) {
            if (searchWord[j] != temp[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return k;
        }
        return -1;
    }
};