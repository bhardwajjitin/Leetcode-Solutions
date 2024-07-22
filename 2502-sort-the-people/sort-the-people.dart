class Pair<L,R>{
     L left;
     R right;
     Pair(this.left,this.right);
}
class Solution {
  List<String> sortPeople(List<String> names, List<int> heights) {
    List<Pair<int,String>>res=[];
    List<String>ans=[];
    for(var i=0;i<names.length;i++){
      res.add(Pair(heights[i],names[i]));
    }
    res.sort((a,b)=>b.left.compareTo(a.left));
    res.forEach((it){
      ans.add(it.right);
    });
    return ans;
  }
}