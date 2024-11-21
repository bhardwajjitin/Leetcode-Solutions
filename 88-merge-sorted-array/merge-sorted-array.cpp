class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
        }
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int k=m-1;
        while(j>=0 && k>=0){
            while(k>=0 && j>=0 && nums2[j]>=nums1[k]){
                nums1[i]=nums2[j];
                i--;
                j--;
            }
            while(j>=0 && k>=0 && nums1[k]>nums2[j]){
                 nums1[i]=nums1[k];
                 i--;
                 nums1[k]=0;
                 k--;
            }
        }
        while(j>=0){
            nums1[i]=nums2[j];
            i--;
            j--;
        }
    }
};