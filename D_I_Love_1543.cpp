
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;

   
   
vector<int> printSpiral(vector<vector<int>> mat) {
 
  // Define ans array to store the result.
  vector<int> ans;
 
  int n = mat.size(); // no. of nows
  int m = mat[0].size(); // no. of columns
  
  // Initialize the pointers reqd for traversal.
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
  return ans;
}
   
   
void solve(){
    take(n); take(m);

    vector<vector<int>> mat(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;

            mat[i][j]=c-'0';
        }
    }

    vector<int> pura=printSpiral(mat);

    int size=2*(n+m-2);

    int tot=min(n/2,m/2);

    int start=0;
    int end=0;

    int ans=0;

    for(int xxt=1;xxt<=tot;xxt++){

        if(n<=0 || m<=0){
            break;
        }

        size=2*(n+m-2);
        n-=2;
        m-=2;

        end=start+size;

        vector<int> tmp;

        for(int i=start;i<end;i++){
            tmp.pb(pura[i]);
        }

       // int z=0;
       int z=tmp.size();

        for(int i=0;i<tmp.size();i++){
            if(tmp[i%z]==1 && tmp[(i+1)%z]==5 && tmp[(i+2)%z]==4 && tmp[(i+3)%z]==3){
              //  z++;
              ans++;
            }


        }

        start=end;







    }

    cout<<ans;pl;











        
}
   
   
   
int32_t main(){

    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           
             solve(); };        
   return 0;
   }