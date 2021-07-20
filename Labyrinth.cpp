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
int src_i, src_j ,  dst_i, dst_j;
int dis[1001][1001];
int vis[1001][1001];
int matrix[1001][1001];
pii parent[1001][1001];
 
int r[]= {1,-1,0,0};
int c[]= {0,0,1,-1};
 
bool bfs(){
  if(src_i==dst_i && dst_j==src_j)
  {
    dis[src_i][src_j]=0;
    return true;
  }
  
  dis[src_i][src_j]=0;
  queue<pii> q;
  q.push({src_i,src_j});
  vis[src_i][src_j]=1;
 
  while(!q.empty()){
    int i= q.front().ff;
    int j= q.front().ss;
    q.pop();
    int distance= dis[i][j];
 
    rep(k,0,4){
      int x= i + r[k];
      int y= j+ c[k];
 
      if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || !matrix[x][y]) 
        continue;
 
      vis[x][y]=1;
      dis[x][y]= distance+1;
      parent[x][y]=make_pair(i,j);
      q.push({x,y});
 
      if(x==dst_i && y==dst_j)
        return true;
    }
  }
 
  return false;
}
 
 
void init(){
  cin>>n>>m;
  rep(i,0,n){
    rep(j,0,m){
      dis[i][j]=-1;
      char x;
      cin>>x;
 
      if(x=='#')
        continue;
 
      matrix[i][j]=1;
      if(x=='A')
        src_i=i, src_j=j;
      if(x=='B')
        dst_i=i, dst_j=j;
    }
  }
 
}
void printPath(){
  string s="";
 
  int i= dst_i , j= dst_j;
  while(i!=src_i || j!=src_j){
    int x=parent[i][j].ff, y= parent[i][j].ss;
    int I= i-x, J= j-y;
    if(I==1)
      s+='D';
    else if(I==-1)
      s+='U';
    else if(J==1)
      s+='R';
    else if(J==-1)
      s+='L';
 
    i=x,j=y;
  }
 
  reverse(s.begin(),s.end());
  cout<<dis[dst_i][dst_j]<<"\n";
  cout<<s<<endl;
}
void solution(){
   init();
   bool result= bfs();
 
   if(!result){
    cout<<"NO\n";
    return;
   }
 
   cout<<"YES\n";
   printPath();
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
