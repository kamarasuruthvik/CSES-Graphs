#include <bits/stdc++.h>
using namespace std;
//to set precision use fixed,setprecision(number_of_points_after_decimal)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pb push_back
#define debugvector(h) for(auto &l:h)cout<<l<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long double ld;
 
vi adj[100001];
int vis[100001];
 
 
void dfs(int node){
  vis[node]=1;
 
  trav(child,adj[node]){
    if(!vis[child])
      dfs(child);
  }
}
 
void solution(){
 
int n, m; 
cin>>n>>m;
 
rep(i,0,m){
  int x,y;
  cin>>x>>y;
  adj[x].pb(y),adj[y].pb(x);
}
 
 
vi comp;
 
rep(i,1,n+1){
 
  if(!vis[i]){
    dfs(i);
    comp.pb(i);
  }
 
}
 
int s=comp.size();
 
 
cout<<s-1<<"\n";
 
rep(i,0,s-1){
  cout<<comp[i]<<" "<<comp[i+1]<<"\n";
}
 
}
 
 
 
int main() {
    #ifdef axel
    // for getting input from input.txt
    freopen("D:/Competiitve/input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("D:/Competiitve/output.txt", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t=1;
  //cin>>t;
  while(t--){
  solution();
 
  }
  return 0;
}
