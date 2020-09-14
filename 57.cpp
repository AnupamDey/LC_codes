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
    vector<vector<int>> _insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> res;
        int n = intervals.size();
        
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = intervals[i]; 
            }
            else if(intervals[i][1] >= newInterval[0]) {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        res.push_back(newInterval); 
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution* s = new Solution();
  int row,col;
  string str;

  test_case {
    cout << "Case #" << t  << ": "<<"\n";
    cin>>row>>col;
    vi arr;
    vvi grid(row,vi(col,0));
    vvi res;
    for(int r=0;r<row;++r) {
     for(int c=0;c<col;++c) {
        cin>>grid[r][c];
     }
    }
    cin>>str;
    str.erase(remove(str.begin(),str.end(),'['),str.end());
    str.erase(remove(str.begin(),str.end(),']'),str.end());
    stringstream ss(str);

    for(int t;ss >> t;) {
      arr.pb(t);
      if(ss.peek() == ',') {
        ss.ignore();
      }
    }

    res = s->_insert(grid,arr);

    for(int r=0;r<(int)res.size();++r) {
      for(int c=0;c<(int)res[0].size();++c) {
        cout<<res[r][c]<<"\t";
      }
      cout<<"\n";
    }
  }

  return 0;
}
