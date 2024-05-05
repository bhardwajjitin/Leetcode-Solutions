class DisjointSet{
  private:
  vector<int>par,rank,size;
  public:
  DisjointSet(int n){
    par.resize(n);
    rank.resize(n,0);
    size.resize(n,1);
    for(int i=0;i<n;i++){
      par[i]=i;
    }
  }
  int findUPar(int node){
    if(node==par[node])return node;
    return findUPar(par[node]);
  }
  void unionbyRank(int u,int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
    
    if(rank[ulp_u]<rank[ulp_v]){
      par[ulp_u]=ulp_v;
      rank[ulp_v]+=rank[ulp_u];
    }
    else{
      par[ulp_v]=ulp_u;
      rank[ulp_u]+=rank[ulp_v];
    }
  }
  void unionbySize(int u,int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
    par[ulp_v]=ulp_u;
    if(size[ulp_u]<size[ulp_v]){
      size[ulp_v]+=size[ulp_u];
    }
    else{
      size[ulp_u]+=size[ulp_v];
    }
  }
  bool check(){
    int cnt=0;
    for(int i=0;i<par.size();i++){
      if(par[i]==i)cnt++;
    }
    if(cnt>1)return false;
    return true;
  }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            int left=leftChild[i];
            int right=rightChild[i];
            if(left!=-1 && ds.findUPar(left)!=ds.findUPar(i) && ds.findUPar(left)!=left)return false;
            if(right!=-1 && ds.findUPar(right)!=ds.findUPar(i) && ds.findUPar(right)!=right)return false;
            if(left!=-1 && ds.findUPar(left)!=ds.findUPar(i)){
              ds.unionbySize(i,left);
            }
            else if(left!=-1 && ds.findUPar(left)==ds.findUPar(i))return false;
            if(right!=-1 && ds.findUPar(right)!=ds.findUPar(i)){
              ds.unionbySize(i,right);
            }
            else if(right!=-1 && ds.findUPar(right)==ds.findUPar(i))return false;
        }
        return ds.check()&&true;
    }
};