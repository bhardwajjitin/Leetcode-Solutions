class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int low=k;
        int high=blocks.size();
        int mini=INT_MAX;
        for(int size=low;size<=high;size++){
           int left=0;
           int right=size-1;
           while(right<blocks.size()){
              if(right-left+1<size){
                right++;
              }
              else if(right-left+1==size){
                int cnt=0;
                for(int i=left;i<=right;i++){
                    if(blocks[i]=='W')cnt++;
                }
                mini=min(cnt,mini);
                right++;
                left++;
              }
           }
        }
        return mini;
    }
};