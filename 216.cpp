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
#define test_case int T; cin>>T; fo1(i,T)

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
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path(k);
        int i = 0;
        int sum = 0;
        
        while(i!=-1){
            ++sum;
            ++path[i];
            if(path[i]>9 || sum > n || (i!=k-1 && sum+path[i] >= n) ){
                sum -= path[i];
                i--;
            }else if(i == k-1){
                if(sum == n) res.push_back(path);
            }else if(sum+path[i] < n){
                path[i+1] = path[i];
                sum += path[i];
                i++;
            }
        }
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution* s = new Solution();
  test_case {
    int k,n;
    cin>>k>>n;
    vvi grid;
    grid = s->combinationSum3(k,n);
    for(int i=0;i<(int)grid.size();++i) {
      for(int j=0;j<(int)grid[0].size();++j) {
        printf("%d\t",grid[i][j]);
      }
      printf("\n");
    }
  }
  	
  return 0;
}
