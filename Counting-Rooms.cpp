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
int n,m;
int matrix[1000][1000];
int vis[1000][1000];
 
 
void find_connected(int i,int j){
  if(i<0 || j<0 || i>=n ||j>=m || vis[i][j]==1 || matrix[i][j]==0 )
    return;
 
  vis[i][j]=1;
 
  find_connected(i-1,j);
  find_connected(i+1,j);
  find_connected(i,j+1);
  find_connected(i,j-1);
  
 
}
 
void solution(){
  
  cin>>n>>m;
 
  rep(i,0,n){
    rep(j,0,m){
      char x;
      cin>>x;
      if(x=='.')
      matrix[i][j]=1;
    }
  }
 
  int rooms=0;
  rep(i,0,n){
    rep(j,0,m){
      if(matrix[i][j]==1 && vis[i][j]!=1){
        find_connected(i,j);
        rooms++;
      }
    }
  }
 
  cout<<rooms;
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
