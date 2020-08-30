//Problem:

#include <bits/stdc++.h>

using namespace std;

#define MAXX 100001
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
vector<int> parent;
private:
    int getParent(int x) {
        return (parent[x] == -1) ? x : parent[x] = getParent(parent[x]);
    }
    bool unionF(int a,int b) {
        int p1 = getParent(a);
        int p2 = getParent(b);
        return (p1 == p2) ? false : parent[p2] = p1;
        return true;
    }
public:
    int largestComponentSize(vector<int>& A) {
        unordered_map<int,int> m;
        parent.assign(MAXX,-1);
        int res = 0;
        for(int& e : A) {
            for(int i=2;i*i<=e;++i) {
                if(e % i == 0) {
                    unionF(i,e);
                    unionF(e,e/i);
                }
            }
        }
        for(int& e : A) {
            res = max(res,++m[getParent(e)]);
        }
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution* s = new Solution();
  string str;
  test_case {
    vi arr;
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
    cout<<s->largestComponentSize(arr)<<endl;
  }
  
  
  /*
  for(auto& x : arr) {
	cout<<x<<"\t";
  }
  */
	
	
  return 0;
}
