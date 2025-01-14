class Solution{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>count;
        set<int>st;
        for(int i=0;i<A.size();i++){
            st.insert(B[i]);
            int t=0;
            for(int j=0;j<=i;j++){
                if(st.find(A[j])!=st.end())t++;
            }
            count.push_back(t);
        }
        return count;
    }
};