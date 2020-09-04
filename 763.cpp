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
const int CHARS = 26;
public:
    vector<int> partitionLabels(string S) {
        vector<int> map(CHARS,0);
        vector<int> res;
        int n = S.length();
        int beg = 0,end = -1,i = 0;
        for(int i=0;i<n;++i) {
            map[S[i]-'a'] = i;
        }
        while(i < n) {
            end = max(end,map[S[i]-'a']);
            if(i == end) {
                res.push_back(i - beg + 1);
                beg = i + 1;
            }
            ++i;
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
    vi arr;
    string str;
    cin>>str;
    
    arr = s->partitionLabels(str);
    
    for(auto& x : arr) {
	    cout<<x<<"\t";
    }
    cout<<"\n";
  }
  
  return 0;
}
