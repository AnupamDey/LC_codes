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
	string largestTimeFromDigits(vector<int>& A) {
		string res = "";
		sort(A.begin(),A.end());
		do
		{
			if((A[0]==2 && A[1]<=3 || A[0]<2) && A[2]<=5)
			{
				string str = to_string(A[0])+to_string(A[1])+":"
					+to_string(A[2])+to_string(A[3]);
				if(str > res) res = str;
			}       
		}while(next_permutation(A.begin(),A.end()));
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
    cout<<s->largestTimeFromDigits(arr)<<"\n";
  }
  
  return 0;
}
