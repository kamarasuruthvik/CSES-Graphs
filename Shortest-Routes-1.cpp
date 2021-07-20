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
 
 
int n, m;
int vis[100001];
ll dis[100001];
const ll INF= 2e+18;
vector<pii> adj[100001];
 
 
void disjakstra(int src){
  dis[src]=0;
  priority_queue<pair<ll, int>,vector<pair<ll, int>> , greater<pair<ll, int>>> q;
  q.push({0,src});
 
  while(!q.empty()){
 
    int node= q.top().ss;
    ll distance= q.top().ff;
 
    q.pop();
    if(vis[node])
      continue;
    vis[node]=1;
    trav(e, adj[node]){
      int child= e.ff;
      ll len= e.ss;
     
      if(dis[child]>=(len + distance)){
        dis[child]=len+ distance;
        q.push({dis[child], child});
      }
    }
 
  }
}
void init(){
  cin>>n>>m;
  int x,y,c;
  rep(i,0,m){
    cin>>x>>y>>c;
    adj[x].push_back({y,c});
 
  }
 
  rep(i,0,100001){
    dis[i]=INF;
  }
  
 
}
 
void printDistance(){
  rep(i,1, n+1)
    cout<<dis[i]<<" ";
}
void solution(){
 
  init();
  
  disjakstra(1);
 
  printDistance();
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
