#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    multiset<int> s;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.insert(x);
    }

    for(int i=0;i<m;i++){
        int x;cin>>x;

        // <=x chahiye
        // x-1 ka lower bound

        auto lo=s.lower_bound(x);
        // >=x
        int val=*lo;
        if(val==x){
            cout<<val<<endl;
            s.erase(lo);
        }else{
            // val> x;
            if(lo==s.begin()){
                cout<<-1<<endl;
                continue;
            }
            lo--;
            val=*lo;

            cout<<val<<endl;
            s.erase(s.find(val));
        }

        

    }

    
   
   
 return 0;
}