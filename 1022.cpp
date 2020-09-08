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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int res = 0;
    void dfs(TreeNode* root,int data) {
        if(!root) return;
        data = data << 1 | root->val;
        if(!root->left && !root->right) res += data;
        dfs(root->left,data);
        dfs(root->right,data);
    } 
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  Solution* s = new Solution();
  
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  cout<<s->sumRootToLeaf(root)<<endl;
	
  return 0;
}
