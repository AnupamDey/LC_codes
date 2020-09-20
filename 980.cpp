//Problem:

#include <bits/stdc++.h>

using namespace std;

#define MAXX 1001
#define INFF 0x3f3f3f3f
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fo(i,n) for (int i = 0; i < n; ++i) 
#define rfo(i,n) for (int i = n; i >= 0; --i)
#define fo1(i,n) for (int i = 1; i <= n; ++i)
#define test_case int T; cin>>T; fo1(t,T)

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef unsigned long long ull;
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<set<int> > vsi;
typedef map<int,string> mis; 
typedef map<string,int> msi;
typedef map<int,vector<int>> mivi;


class Solution {
private:
    int dfs(vector<vector<int>>& grid,int r,int c) {
        int R = grid.size();
        int C = grid[0].size(),res = 0;
        if(r < 0 || r >= R || c < 0 || c >= grid[r].size() || grid[r][c] == -1) return 0;
        if(grid[r][c] == 2) {
            for(vector<int>& v : grid) {
                for(int& i : v) {
                    if(i == 0) return 0;
                }
            }
            return 1;
        }
        auto buff = grid[r][c];
        grid[r][c] = -1;
        res += dfs(grid,r+1,c);
        res += dfs(grid,r,c+1);
        res += dfs(grid,r-1,c);
        res += dfs(grid,r,c-1);
        
        grid[r][c] = buff;
        
        return res;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size(),res = 0;
        for(int i=0;i<R;++i) {
            for(int j=0;j<C;++j) {
                if(grid[i][j] == 1) res = dfs(grid,i,j);
            }
        }
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  Solution* s = new Solution();
  test_case {
    cout << "Case #" << t  << ": "<<"\n";
    int row,col;
    cin>>row>>col;
    vvi grid(row,vi(col,0));
     
    for(int i=0;i<row;++i) {
      for(int j=0;j<col;++j) {
          cin>>grid[i][j];
      }
    }
    cout<<s->uniquePathsIII(grid)<<endl;
    
  }

  return 0;
}
