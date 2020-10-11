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
    string removeDuplicateLetters(string s) {
        vector<int> dict(128,0);
        vector<bool> vis(128,false);
        for(auto& i : s) dict[i]++;
        string res = "";
        for(char& c : s) {
            dict[c]--;
            if(vis[c]) continue; 
            while(!res.empty() && dict[res.back()] && res.back() > c) {
                vis[res.back()] = false;
                res.pop_back();
            }
            
            res += c;
            vis[c] = true;
        }
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  
  Solution* s = new Solution();
  string str;
  test_case {
    cout << "Case #" << t  << ": "<<"\n";
    cin>>str;
    cout<<s->removeDuplicateLetters(str)<<endl;
  }

  return 0;
}
