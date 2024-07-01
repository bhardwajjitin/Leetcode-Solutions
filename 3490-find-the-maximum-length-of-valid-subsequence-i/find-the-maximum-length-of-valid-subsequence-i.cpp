class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int>res;
        for(auto it:nums){
          res.push_back(it%2);
        }
        int evenodd=0;
        int eveneven=0;
        int oddodd=0;
        int oddeven=0;
        for(auto it:res){
          if(it==1)oddodd++;
          if(it==0)eveneven++;  
        }
        bool flag=false;
        for(auto it:res){
          if(it==1){
            if(!flag)
            oddeven++;
            flag=true;
          }
          else{
            if(flag)
            oddeven++;
            flag=false;
          }
        }
        flag=false;
        for(auto it:res){
          if(it==0){
            if(!flag)
            evenodd++;
            flag=true;
          }
          else{
            if(flag==true){
              evenodd++;
            } 
            flag=false;
          }
        }
        cout<<oddeven<<" "<<evenodd<<" "<<oddodd<<" "<<eveneven<<endl;
        return max({oddeven,evenodd,oddodd,eveneven});
    }
};