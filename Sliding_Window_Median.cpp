#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define show(v) for(auto x: v){cout<<x<<" ";} cout<<endl;

void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

int main(){
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // do it for u man

    ordered_set X;

    int mid=(k-1)/2;

    for(int i=0;i<k;i++){
        X.insert(a[i]);
    }

    vector<int> ans;

    int num=*X.find_by_order(mid);
   // cout<<num;
   int i=0;
   int j=k;
   ans.push_back(num);


   while(j<n){

        // first update X
        myerase(X,a[i]);
        X.insert(a[j]);
        


        num=*X.find_by_order(mid);
        ans.push_back(num);
        i++;
        j++;

   }

   for(auto x: ans){
    cout<<x<<" ";
   }





    


    


    



    
   
   
 return 0;
}