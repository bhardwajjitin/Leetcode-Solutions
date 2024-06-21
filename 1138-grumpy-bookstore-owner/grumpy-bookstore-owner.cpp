class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int minutes) {
      int n=grumpy.size();
      vector<int>with(n),without(n);
      with[0]=cust[0];
      if(grumpy[0]==0)
      without[0]=cust[0];

      for(int i=1;i<n;i++){
          if(grumpy[i]==0){
            without[i]=without[i-1]+cust[i];
          }
          else{
            without[i]=without[i-1];
          }
          with[i]=with[i-1]+cust[i];
      }
      int i=0;
      int j=minutes-1;
      int maxi=INT_MIN;
      while(j<n){
        int temp;
        if(i-1>=0)
        temp=with[j]-with[i-1]+without[n-1]-without[j]+without[i-1];
        else
        temp=with[j]+without[n-1]-without[j];
        maxi=max(maxi,temp);

        i++;
        j++;
      }
      return maxi;
    }
};