class Solution {
 void merge(List<int> nums, int low, int high, int mid) {
    int len1 = mid - low + 1;
    int len2 = high - mid;
    List<int> first = List.filled(len1, 0);
    List<int> second = List.filled(len2, 0);
    for (int i = 0; i < len1; i++) {
      first[i] = nums[low + i];
    }
    for (int j = 0; j < len2; j++) {
      second[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < len1 && j < len2) {
      if (first[i] <= second[j]) {
        nums[k] = first[i];
        i++;
      } else {
        nums[k] = second[j];
        j++;
      }
      k++;
    }
    while (i < len1) {
      nums[k] = first[i];
      i++;
      k++;
    }
    while (j < len2) {
      nums[k] = second[j];
      j++;
      k++;
    }
  }
  void solve(List<int>nums,int low,int high){
    if(low<high){
    int mid=(low+high) ~/ 2;
    solve(nums,low,mid);
    solve(nums,mid+1,high);
    merge(nums,low,high,mid);
    }
  }
  List<int> sortArray(List<int> nums) {
    int low=0;
    int high=nums.length-1;
    solve(nums,low,high);
    return nums;
  }
}