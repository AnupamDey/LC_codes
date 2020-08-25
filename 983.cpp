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
private:
    int _min(int a,int b,int c) {
        return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,INF);
        dp[0] = 0;
        vector<bool> isVis(366,false);
        for(auto& i : days) isVis[i] = true;
        for(int i=1;i<366;++i) {
            if(!isVis[i]) {
                dp[i] = dp[i-1];
                continue;
            }
            int one_day_pass_cost = dp[i-1] + costs[0];
            int seven_day_pass_cost = dp[max(i-7,0)] + costs[1];
            int thirty_day_pass_cost = dp[max(i-30,0)] + costs[2];
            dp[i] = _min(one_day_pass_cost,seven_day_pass_cost,thirty_day_pass_cost);
        }
        return dp[365];
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution* s = new Solution();
  string str,str1;
  test_case {
    vi arr,arr1;
    cin>>str>>str1;
    str.erase(remove(str.begin(),str.end(),'['),str.end());
    str.erase(remove(str.begin(),str.end(),']'),str.end());
    str1.erase(remove(str1.begin(),str1.end(),'['),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),']'),str1.end());
    stringstream ss(str);
    stringstream ss1(str1);
    for(int t;ss >> t;) {
	    arr.pb(t);
	    if(ss.peek() == ',') {
		    ss.ignore();
	    }
    }
    for(int t;ss1 >> t;) {
	    arr1.pb(t);
	    if(ss1.peek() == ',') {
		    ss1.ignore();
	    }
    }
    cout<<s->mincostTickets(arr,arr1)<<endl;
  }
  
  return 0;
}
