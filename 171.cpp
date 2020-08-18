//Problem:

#include <bits/stdc++.h>
using namespace std;

#define MAXX 1001
#define INF 0x3f3f3f3f
#define pb push_back
#define pob pop_back
#define mp make_pair
#define test_case int T; cin>>T; for(int i=1;i<=T;i++)
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define pii pair<int,int>
#define vvc vector<vector<char> >
#define vsi vector<set<int> >
#define vvi vector<vector<int> >
#define vvs vector<vector<string> >
#define mis map<int,string>
#define msi map<string,int>
#define msvs map<string,vector<string> >
#define mivi map<int,vector<int> >

typedef unsigned long long ull;
typedef long long ll;
typedef long long int lli;


class Solution {
private:

public:
	int titleToNumber(string s) {
    unsigned int res = 0;
    for(const auto& ch : s) {
        res = (26 * res + ch - 'A' + 1);
    }
    return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // #ifndef ONLINE_JUDGE
	//   freopen("in.txt", "r", stdin);
	//   // freopen("err.txt", "w", stderr);
	//   freopen("out.txt", "w", stdout);
  // #endif
  Solution* s = new Solution();
  // int row,col;
  // cin>>row>>col;
  // vi arr;
  // vvi grid(row);
  
  //str = str.substr(1,str.length()-1);
  
  // str.erase(remove(str.begin(),str.end(),']'),str.end());
  // stringstream ss(str);

  /*
  for(int s;ss >> s;) {
	arr.pb(s);
	if(ss.peek() == ',') {
		ss.ignore();
	}
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
  for(int i=0;i<(int)arr.size();++i) {
	printf("%d\t",arr[i]);
  }
  */
  test_case {
    string str;
    cin>>str;
    str.erase(remove(str.begin(),str.end(),'"'),str.end());
    cout<<s->titleToNumber(str)<<endl;
  }

  return 0;
}
