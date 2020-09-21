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
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> list(1001);
        for(auto& i : trips) {
            list[i[1]] += i[0];
            list[i[2]] -= i[0];
        }
        for(auto v : list) {
            if((capacity -= v) < 0) return false;
        }
        return true;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  
  Solution* s = new Solution();
  test_case {
    cout << "Case #" << t  << ": "<<"\n";
    int row,col,capacity;
    cin>>row>>col;
    vvi grid(row,vi(col,0));
     
    for(int i=0;i<row;++i) {
      for(int j=0;j<col;++j) {
          cin>>grid[i][j];
      }
    }
    cin>>capacity;
    cout<<(s->carPooling(grid,capacity) ? "true" : "false")<<endl;
   
  }

  return 0;
}
