class DisjointSet{
    private:
    vector<int>par,rank,size;
    public:
    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
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
        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    int check(){
        int cnt=0;
        for(int i=1;i<par.size();i++){
            if(par[i]==i)cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n),bob(n);
        int cnt=0;
          for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];
           if(type==3){
            if(alice.findUPar(u)==alice.findUPar(v) && bob.findUPar(u)==bob.findUPar(v)){
              cnt++;
            }
            alice.unionbySize(u,v);
            bob.unionbySize(u,v);
           }
        }
        for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];
            if(type==1){
                 if(alice.findUPar(u)!=alice.findUPar(v)){
                    alice.unionbySize(u,v);
                }
                else{
                    cnt++;
                }
            }
            if(type==2){
                 if(bob.findUPar(u)!=bob.findUPar(v)){
                    bob.unionbySize(u,v);
                }
                else{
                    cnt++;
                }
            }
        }
       if(alice.check()>1 || bob.check()>1){
        return -1;
       }  
        return cnt;
    }
};