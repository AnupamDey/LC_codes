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
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        stringstream ss1(version1),ss2(version2);
        while(ss1.good()) {
            string sub;
            getline(ss1,sub,'.');
            v1.push_back(stoi(sub));
        }
        while(ss2.good()) {
            string sub;
            getline(ss2,sub,'.');
            v2.push_back(stoi(sub));
        }
        v1.size() < v2.size() ? v1.resize(v2.size()) : v2.resize(v1.size());
        for(int i=0;i<v1.size();++i) {
            if(v1[i]<v2[i]) return -1;
            else if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  Solution* s = new Solution();
  
  test_case {
    string str,str2;
    cin>>str>>str2;
    str.erase(remove(str.begin(),str.end(),'"'),str.end());
    str2.erase(remove(str2.begin(),str2.end(),'"'),str2.end());
    cout<<s->compareVersion(str,str2)<<endl;
  }

  return 0;
}
