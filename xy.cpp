#include<bits/stdc++.h>
using namespace std;

int maxCommStr( string& s1,string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a table to store lengths of longest
    // common suffixes of substrings.
    vector<vector<int>> LCSuf(m + 1, vector<int>(n + 1, 0));

    // Build LCSuf[m+1][n+1] in bottom-up fashion.    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
                res = max(res, LCSuf[i][j]);
            } else {
                LCSuf[i][j] = 0;
            }
        }
    }
    return res;
}
   
   
int main(){

    int n;cin>>n;

    string s;cin>>s;
    string q;cin>>q;

    int ans=0;
    // create x

    // len 1= 1/x;
    // len 2  2/ x
    // len 3  3 / x
    //len 4    4/ x

    int x=maxCommStr(s,q);

    cout<<x;








    
   
   
 return 0;
}