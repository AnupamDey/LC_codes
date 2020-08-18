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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if (n > m) { // to ensure m<=n
      nums1.swap(nums2);
      swap(n,m);
    }
    int N = (n + m);
    int imax = n ,imin = 0,mid,i,j;
    while(imin <= imax) {
      i = (imin + imax)/2;
      j = ((n + m + 1)/2) - i;
      if(j < 0) {
        imax = i - 1;
        continue;
      }
      if(i < n && j > 0 && nums2[j-1] > nums1[i]) imin = i + 1;
      else if(i > 0 && j < m && nums1[i-1] > nums2[j]) imax = i - 1;
      else {
        if(i == 0) mid = nums2[j-1];
        else if(j == 0) mid = nums1[i-1];
        else mid = max(nums1[i-1],nums2[j-1]);
        break;
      }
    }
    if(N & 1) return (double)mid;
    if(i == n) return ((mid + nums2[j])/2.0);
    if(j == m) return ((mid + nums1[i])/2.0);
    return ((mid + min(nums1[i],nums2[j]))/2.0);

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
  vi arr1,arr2;
    // vvi grid(row);
  string str1,str2;
  test_case {
    cin>>str1>>str2;
    //str = str.substr(1,str.length()-1);
    str1.erase(remove(str1.begin(),str1.end(),'['),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),']'),str1.end());
    str2.erase(remove(str2.begin(),str2.end(),'['),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),']'),str2.end());
    // str.erase(remove(str.begin(),str.end(),'"'),str.end());
    stringstream ss1(str1);
    stringstream ss2(str2);

    for(int t1;ss1 >> t1;) {
      arr1.pb(t1);
      if(ss1.peek() == ',') {
        ss1.ignore();
      }
    }
    for(int t2;ss2 >> t2;) {
      arr2.pb(t2);
      if(ss2.peek() == ',') {
        ss2.ignore();
      }
    }
    // for(auto& i : arr1) {
	  //   cout<<i<<"\t";
    // }
    // for(auto& i : arr2) {
	  //   cout<<i<<"\t";
    // }
    cout<<s->findMedianSortedArrays(arr1,arr2)<<"\n";
  }
  // }
   /*
   while(ss.good()) {
	string sub;
	getline(ss,sub,',');
	arr.push_back(sub);
  // }
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
  // }
  */
  /*
  for(auto& i : arr) {
	cout<<i<<"\t";
  // }
  */
  //cout<<s->function()<<endl;

	
  return 0;
}
