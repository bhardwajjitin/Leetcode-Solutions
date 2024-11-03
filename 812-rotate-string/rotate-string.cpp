class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        int k=0;
        while(k<s.size()){
            char first=s[0];
            s.erase(s.begin()+0);
            s.push_back(first);
            if(s==goal)return true;
            k++;
        }
        return false;
    }
};