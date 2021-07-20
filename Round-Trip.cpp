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
int parent[100001];
int vis[1000001];
int cycle_start,cycle_end;
 
 
 
bool dfs(int node, int par){
  vis[node]=1;
  parent[node]=par;
 
  trav(child, adj[node]){
    if(child==par)
      continue;
    if(vis[child]){
      cycle_end= child;
      cycle_start= node;
      return true;
    }
    else{
      if(dfs(child,node))
        return true;
    }
  }
  return false;
}
void print_cycle(){
 
  vi answer;
  answer.pb(cycle_end);
  int current= cycle_start;
 
 
  while(current!=cycle_end)
    answer.pb(current),current= parent[current];
  
  answer.pb(cycle_end);
 
  cout<<answer.size()<<"\n";
 
  rep(i,0,answer.size())
    cout<<answer[i]<<" ";
 
}
void solution(){
 
int n, m;
cin>>n>>m;
 
int x,y;
rep(i,0,m)
  cin>>x>>y,adj[x].pb(y),adj[y].pb(x);
 
rep(i,1,n+1){
  if(!vis[i] && dfs(i,-1))
  {
    print_cycle();
    return;
  }
}
 
cout<<"IMPOSSIBLE";
 
 
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
