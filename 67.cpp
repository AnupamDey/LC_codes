#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()) b.insert(b.begin(), a.length() - b.length(),'0');
        else if(b.length() > a.length()) a.insert(a.begin(), b.length() - a.length(),'0');
        int n = a.length();
        string res(n,'0');
        bool sum = false,c_in = false;
        for(int i=n-1;i>=0;--i) {
            bool al = a[i] - '0' == 1;
            bool bl = b[i] - '0' == 1;
            sum = al ^ bl ^ c_in;
            c_in = (al & bl) || c_in & (al ^ bl);
            if(sum) res[i] = '1';
        }
        if(c_in) res.insert(0,"1");
        return res;
    }
};

int main() {
	// #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("err.txt","w",stderr);
    //     freopen("out.txt","w",stdout);
	// #endif
	Solution *s = new Solution();
	string a,b;
	cin>>a>>b;
	cout<<s->addBinary(a,b)<<endl;
	return 0;
}