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

public:
	vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int l = 0,r = (n - 1);
        if(n <= 1) return A;
        while(true) {
            while(l < n && !(A[l] % 2)) l++;
            while(r && (A[r] % 2)) r--;
            if(l >= r) break;
            swap(A[l++],A[r--]);
        }
        return A;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /*
  #ifndef ONLINE_JUDGE
	  freopen("in.txt", "r", stdin);
	  // freopen("err.txt", "w", stderr);
	  freopen("out.txt", "w", stdout);
  #endif
  */
  // Solution s;
  Solution* s = new Solution();
  // int row,col;
  // cin>>row>>col;
  string str;
  test_case {
    vi arr,out;
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
    
    out = s->sortArrayByParity(arr);
    for(auto& x : out) {
	    cout<<x<<"\t";
    }
    cout<<endl;
  }
  
  // vvi grid(row);
  
  
  //str = str.substr(1,str.length()-1);
  
  // str.erase(remove(str.begin(),str.end(),'"'),str.end());
 

/*
  for(int t;ss >> t;) {
	arr.pb(t);
	if(ss.peek() == ',') {
		ss.ignore();
	}
  }
*/
   /*
   while(ss.good()) {
	string sub;
	getline(ss,sub,',');
	arr.push_back(sub);
  }
  */
  
  //int row = grid.size();
  //int col = grid[0].size();
  // for(int i=0;i<row;++i) {
  //   for(int j=0;j<col;++j) {
  //       printf("%d\t",grid[i][j]);
  //   }
  //   printf("\n");
  // }
  /*
  for(int i=0;i<row;++i) {
     for(int j=0;j<col;++j) {
         scanf("%d",&grid[i][j]);
     }
  }
  */
  /*
  for(auto& x : arr) {
	cout<<x<<"\t";
  }
  */
  //cout<<s->function()<<endl;

	
  return 0;
}
