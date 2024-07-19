class Solution {
  int numberOfSubstrings(String s) {
    List<int>lastseen=[-1,-1,-1];
    int cnt=0;
    for(int i=0;i<s.length;i++){
      int ind = s.codeUnitAt(i) - 'a'.codeUnitAt(0);
      lastseen[ind]=i;
      if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
        cnt=cnt+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
      }
    }
    return cnt;
  }
}