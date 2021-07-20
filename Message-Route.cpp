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
int dis[100001];
int parent[100001];
int n,m;
 
int bfs(int node,int destination){
  vis[node]=1;
  queue<int> q;
  q.push(node);
 
  while(!q.empty()){
    int current= q.front();
    q.pop();
    int distance = dis[current];
    trav(child, adj[current]){
      if(!vis[child])
      {
        dis[child]=distance + 1;
        vis[child]=1;
        parent[child]=current;
        q.push(child);
 
        if(child==destination)
          return dis[child];
 
      }
    }
  }
 
  return -1;
}
 
 
void printParents(){
  vi p;
  int current=n;
  while(current!=1){
    p.pb(current);
    current= parent[current];
  }
  p.pb(1);
  reverse(p.begin(),p.end());
 
  cout<<p.size()<<"\n";
  rep(i,0,p.size())
    cout<<p[i]<<" ";
}
 
 
void solution(){
 
  
  cin>>n>>m;
 
  int x,y;
 
  rep(i,0,m)
  cin>>x>>y, adj[x].pb(y), adj[y].pb(x);
 
  int result = bfs(1,n);
  if(result==-1){
    cout<<"IMPOSSIBLE";
    return;
  }
 
  printParents();
 
 
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
