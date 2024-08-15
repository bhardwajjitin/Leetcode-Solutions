class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnta=0;
        int cntb=0;
        int cntc=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                cnta++;
            }
            else if(bills[i]==10){
                if(cnta==0)return false;
                cnta--;
                cntb++;
            }
            else{
                if(cnta==0)return false;
                cntc++;
                if(cntb>=1){
                    cntb--;
                    cnta--;
                }
                else if(cntb==0 && cnta>=3){
                    cnta-=3;
                }
                else if(cntb==0 && cnta<3)return false;
            }
        }
        return true;
    }
};