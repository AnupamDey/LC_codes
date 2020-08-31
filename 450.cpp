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
public:
    void preorder(TreeNode* root) {
      if(root) {
        cout<<root->val<<"\t";
        preorder(root->left);
        preorder(root->right);
      }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(key < root->val) root->left = deleteNode(root->left,key);
        else if(key > root->val) root->right = deleteNode(root->right,key);
        else {
            if(!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            if(!root->left || !root->right) {
                TreeNode* del = root->right ? root->right : root->left;
                delete(root);
                return del;
            }
            if(root->left && root->right) {
                TreeNode* del = root->right;
                while(del->left) del = del->left;
                root->val = del->val;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  Solution* s = new Solution();
  int key;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  key = 3;

	s->deleteNode(root,key);
  s->preorder(root);
	
  return 0;
}
