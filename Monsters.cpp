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
 
int n,m ;
int r,c; 
int result_x, result_y;
int matrix[1001][1001];
int monsterDistance[1001][1001];
int vis[1001][1001];
vector<pii> monsterPosition;
int dis[1001][1001];
pii parent[1001][1001];
 
vi x = {1,-1,0,0};
vi y = {0,0,1,-1};
 
 
void makeMonsterDistance(){
  
  queue<pii> q;
  int monsterVis[n][m];
  
 
  rep(i,0,n){
    rep(j,0,m){
      monsterVis[i][j]=0;
    }
  }
 
  trav(child , monsterPosition){
    q.push(child);
    int i= child.ff, j= child.ss;
    monsterVis[i][j]=1;
    monsterDistance[i][j]=0;
  }
 
 
 
  while(!q.empty()){
    pii current=q.front();
    int i= current.ff , j= current.ss;
    q.pop();
    int distance= monsterDistance[i][j];
    
    rep(k,0,4){
      int row= i + x[k];
      int col = j + y[k];
      
      if(row<0 || row>=n || col<0 || col>=m || monsterVis[row][col] || matrix[row][col]==0)
        continue;
      else{
        monsterVis[row][col]= 1; 
        monsterDistance[row][col]= distance + 1; 
        q.push(make_pair(row, col));
      }
    }
  }
}
 
 
 
void init(){
  rep(i,0,1001){
    rep(j,0, 1001){
      dis[i][j]=-1;
      monsterDistance[i][j]=INT_MAX;
    }
  }
 
 
  
  cin>>n>>m;
  rep(i,0,n){
    rep(j,0, m){
      char temp; 
      cin>>temp; 
      if(temp=='.' || temp=='A' || temp=='M'){
        matrix[i][j]=1;
        if(temp=='A')
          r=i, c=j;
        if(temp=='M')
          monsterPosition.pb(make_pair(i,j));
      }
    }
  }
 
 
 
  makeMonsterDistance();
 
}
 
bool bfs(){
 
  if(r==0 || r==n-1 || c==0 || c==m-1){
    result_x=r, result_y= c;
    return true;
  }
 
 
  vis[r][c]=1;
  queue<pii> q;
  q.push(make_pair(r,c));
  dis[r][c]=0;
 
  while(!q.empty()){
 
    pii current= q.front();
    q.pop();
    int i= current.ff, j = current.ss;
    int distance= dis[i][j];
 
    rep(k,0,4){
      int row= i + x[k];
      int col = j + y[k];
      
      if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || matrix[row][col]==0 || monsterDistance[row][col]<=(distance+1))
        continue;
      else{
        vis[row][col]=1;
        q.push(make_pair(row, col));
        parent[row][col]= make_pair(i,j);
        dis[row][col]=distance+1;
 
        if(row==0 || row==n-1 || col==0 || col==m-1){
          result_x=row, result_y= col;
          return true;
        }
      }
 
    }
  }
 
  return false;
}
 
 
void printResult(){
  int i= result_x, j= result_y; 
  string s;
  while(i!=r || j!=c){
    int par_i= parent[i][j].ff, par_j= parent[i][j].ss; 
    
    int I= i-par_i , J= j-par_j;  
    if(I==1)
      s+="D";
    else if(I==-1)
      s+="U";
    else if(J==1)
      s+="R";
    else if(J==-1)
      s+="L";
 
    i= par_i, j= par_j ;
  }
  cout<<s.size()<<endl;
  reverse(s.begin(),s.end());
  if(s.size()!=0)
  cout<<s;
 
}
void solution(){
 
  init();
 
  bool result = bfs();
  if(!result){
    cout<<"NO\n";
    return; 
  }
  cout<<"YES\n";
  printResult();
 
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
