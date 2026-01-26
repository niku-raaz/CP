#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){


    // Fix L
    // get tow window
    // l+a
    //l+b
    // find mx pfxSum in this range
    // then get the mx with index


    int n,a,b;
    cin>>n>>a>>b;

    set<pair<int,int>> s;

    vector<int> v(n);
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i){
            p[i]=p[i-1]+v[i];
        }else{
            p[i]=v[i];
        }
    }

    int left=0+a-1;
    int right=0+b-1;

    for(int i=left;i<=right;i++){
        s.insert({-p[i],i});
    }

    int ans=-1e15;

    for(int l=0;l<n;l++){
        // now my l is fixed
        // left right is alredy calc.
        // get the max 
        if(s.empty()){
            break;
        }
        auto it=*s.begin();
        int sum=it.first;
        sum*=-1;
        int ind=it.second;

        // so the best option is ind
        int r=ind;

        int res=p[ind];
        if(l){
            res-=p[l-1];
        }

        ans=max(ans,res);


        // update left and right
        // slide by 1

        // remove left
        // add right+1
        if(left<n){
            // 
            s.erase({-p[left],left});
            left++;
        }
        // add right+1
        if(right+1<n){
            s.insert({-p[right+1],right+1});
            right++;
        }


    }

    cout<<ans;



    
    
   
   
 return 0;
}