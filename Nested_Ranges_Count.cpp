#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set2;

int main(){

    int n;cin>>n;
    

    vector<pair<int,pair<int,int>>> v(n);

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,{b,i}};
    }

    vector<int> f1(n,0),f2(n,0);

    sort(v.begin(),v.end(),[&](pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
        if(a.first!=b.first){
            return a.first<b.first;
        }else{
            return a.second.first>=b.second.first;
        }

    });

    // 1 2 3 4
    // 6 4 6 8

    // 2 0 0 0    how many other ranges it contains
    // 0 1 1 0    how many other ranges it is contained in


    // order_of_key(x) => the number of items in a set that are strictly smaller than our item
    
    ordered_set X;
    X.insert(v[n-1].second.first);

    for(int i=n-2;i>=0;i--){

        f1[v[i].second.second]=X.order_of_key(v[i].second.first+1);
        X.insert(v[i].second.first);
    }

    // for(auto x: X){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    ordered_set2 Y;
    Y.insert(v[0].second.first);

    for(int i=1;i<n;i++){

        f2[v[i].second.second]=Y.order_of_key(v[i].second.first-1);

        Y.insert(v[i].second.first);


    }



    for(int i=0;i<n;i++){
        cout<<f1[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<f2[i]<<" ";
    }

    



    
   
   
 return 0;
}