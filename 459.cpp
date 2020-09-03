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
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps(n,0);
        int i = 0,j = 1;
        while(j < n) {
            if(s[i] == s[j]) lps[j++] = ++i;
            else if(i > 0) i = lps[i-1];
            else if(i == 0) j++;
            else i = 0;
        }
        int pat_len = (n - lps[n-1]);
        
        return (lps[n-1] > 0) && (n % pat_len == 0);
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution* s = new Solution();
  test_case {
    string str;
    cin>>str;
   cout<<s->repeatedSubstringPattern(str)<<"\n";
  }
  
  return 0;
}
