class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size=derived.size();
        
        if(size==1){
            return !derived[0];
        }
        vector<int>arr1(size),arr2(size);
        arr1[0]=0;
        arr2[0]=1;
        for(int i=1;i<=derived.size();i++){
            int val=derived[i-1];
            int first=arr1[i-1];
            int second=arr2[i-1];
            if(i==derived.size()){
                if(arr1[i%derived.size()]!=first^val && arr2[i%derived.size()]!=second^val){
                    return false;
                }
            }
            arr1[i%derived.size()]=first^val;
            arr2[i%derived.size()]=second^val;
        }
        return true;
    }
};