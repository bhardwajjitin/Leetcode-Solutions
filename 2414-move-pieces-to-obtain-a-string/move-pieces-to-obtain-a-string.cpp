class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        for(int i=0;i<n;i++){
            char tar=target[i];
            char star=start[i];
            if(tar==star)continue;
            else if(tar=='_' && star=='R'){
                 int j=i;
                 while(j<n){
                    if(start[j]=='_'){
                        swap(start[j],start[i]);
                        break;
                    }
                    else if(start[j]=='L'){
                        return false;
                    }
                    j++;
                 }
                 if(start[i]!=target[i])return false;
            }
            else if(tar=='L' && star=='_'){
                 int j=i;
                 while(j<n){
                    if(start[j]=='L'){
                        swap(start[j],start[i]);
                        break;
                    }
                    else if(start[j]=='R'){
                        return false;
                    }
                    j++;
                 }
                 if(start[i]!=target[i])return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};