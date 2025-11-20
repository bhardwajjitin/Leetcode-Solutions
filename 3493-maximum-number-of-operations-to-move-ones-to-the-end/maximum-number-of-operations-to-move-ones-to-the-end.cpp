class Solution {
public:
    int maxOperations(string s) {
        int sum=0;
        int cnt_one=0;
        int flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt_one++;
                flag=false;
            }
            else{
                if(flag==false){
                sum+=cnt_one;
                }
                flag=true;
            }
        }
        return sum;
    }
};