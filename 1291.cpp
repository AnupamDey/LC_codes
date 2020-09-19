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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> list;
        string dig = "123456789";
        int n = dig.length();
        for(int i=0;i<n;++i) {
            for(int j=i;j<n;++j) {
                string str = dig.substr(i,j-i+1);
                int d = atoi(str.c_str());
                if(d >= low && d <= high) list.push_back(d);
            }
        }
        sort(list.begin(),list.end());
        return list;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  Solution* s = new Solution();
  int low,high;
  test_case {
    cout << "Case #" << t  << ": "<<"\n";
    cin>>low>>high;
    vi arr;
    arr = s->sequentialDigits(low,high);
    for(auto& x : arr) {
      cout<<x<<"\t";
    }
    cout<<"\n";
  }

  return 0;
}
