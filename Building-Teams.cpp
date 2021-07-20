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
int color[100001];
bool flag=true;
void dfs(int root, int colour){
 
  vis[root]=1;
  color[root]=colour;
 
  trav(child, adj[root])
  {
    if(!vis[child]){
      dfs(child,colour^1);
    }
    else{
      if(color[child]==colour)
        flag=false;
    }
  }
}
 
void solution(){
 
  int n,m;
  cin>>n>>m;
  rep(i,0,m){
    int x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
 
  rep(i,1,n+1){
    if(!vis[i])
    {
      dfs(i,0);
    }
  }
  if(!flag){
    cout<<"IMPOSSIBLE";
    return;
  }
 
  rep(i,1,n+1){
    cout<<color[i]+1<<" ";
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
  cout<<"\n";
  }
  return 0;
}
