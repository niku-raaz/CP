#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    int mn;
    int count;
    Node(){
       count=1;
       mn=1e18;
    }
};
const int N=100002;
int arr[N];
Node a[4*N+1];

// everything is 0 based indexing

void build(int id,int lo,int hi){
    if(lo==hi){
        a[id].mn=arr[lo];
        a[id].count=1;
        return;
    }
    int mid=(lo+hi)/2;
    int left=2*id+1;
    int right=2*id+2;
    build(left,lo,mid);
    build(right,mid+1,hi);

    // 
    if(a[left].mn==a[right].mn){
        a[id].mn=a[left].mn;
        a[id].count=(a[left].count+a[right].count);
    }else{
        if(a[left].mn>a[right].mn){
            a[id].mn=a[right].mn;
            a[id].count=a[right].count;
        }else{
            a[id].mn=a[left].mn;
            a[id].count=a[left].count;

        }
    }
}


pair<int,int> query(int id,int lo,int hi,int lq,int rq){
    if(lo>rq || hi<lq){
        return {1e18,1};
    }
    if(lo>=lq && hi<=rq){
        // complete overlap;
        return {a[id].mn,a[id].count};
    }

    int mid=(lo+hi)/2;
    int lc=2*id+1;
    int rc=2*id+2;
    pair<int,int> left=query(lc,lo,mid,lq,rq);
    pair<int,int> right=query(rc,mid+1,hi,lq,rq);

    if(left.first==right.first){
        return {left.first, (left.second+right.second)};
    }else{
        if(left.first<right.first){
            return left;
        }else{
            return right;
        }
    }

}

void update(int id,int lo,int hi,int ind,int x){

    if(ind<lo || ind>hi){
        return;
    }

    if(lo==hi){
        //==ind
        a[id].mn=x;
        a[id].count=1;
        return;
    }
    int mid=(lo+hi)/2;
    int left=2*id+1;
    int right=2*id+2;
    update(left,lo,mid,ind,x);
    update(right,mid+1,hi,ind,x);

    // 
    if(a[left].mn==a[right].mn){
        a[id].mn=a[left].mn;
        a[id].count=(a[left].count+a[right].count);
    }else{
        if(a[left].mn>a[right].mn){
            a[id].mn=a[right].mn;
            a[id].count=a[right].count;
        }else{
            a[id].mn=a[left].mn;
            a[id].count=a[left].count;

        }
    }


}
   
   
int32_t main(){

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(0,0,n-1);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int ind,x;
            cin>>ind;
            cin>>x;
            update(0,0,n-1,ind,x);

        }else{
            int l,r;
            cin>>l>>r;
            r--;
            pair<int,int> ans=query(0,0,n-1,l,r);
            cout<<ans.first<<" "<<ans.second<<endl;;

        }
    }
    
   
   
 return 0;
}