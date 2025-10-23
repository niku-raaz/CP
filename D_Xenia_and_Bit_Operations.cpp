#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=(1<<18)+5;;
int arr[N];

struct Node{
    int val;
    int ops;
    Node(){
       val=0;
       ops=1;
    }
};

Node a[4*N];

// everythigh is 0 based indexing

// 1 means XOR hua hai
// 0 means OR hua hai
void build(int id,int lo,int hi){
    if(lo==hi){
        a[id].val=arr[lo]; // we are at base
        a[id].ops=1; // xor hua hai
        return ;
    }
    int mid=(lo+hi)/2;
    build(2*id+1,lo,mid);
    build(2*id+2,mid+1,hi);

    bool childops=a[2*id+1].ops; // returns 1 
    if(childops){
        // xor hua tha
        // do OR here
        a[id].ops=0;
        a[id].val=(a[2*id+1].val | a[2*id+2].val);

    }else{
        // or hua tha
        // do XOR here
        a[id].ops=1;
        a[id].val=(a[2*id+1].val ^ a[2*id+2].val);
    }

    

}

int query(int id,int lo,int hi,int ind,int x){
    if(lo>ind || hi<ind){
        // ind is not in this
        // return the whole val;
        return a[id].val;
    }
    if(lo<=ind && hi>=ind && lo==hi){
        // comple
        // at base
        a[id].val=x;
        return x;
    }
    int mid=(lo+hi)/2;

    int left=query(2*id+1,lo,mid,ind,x);
    int right=query(2*id+2,mid+1,hi,ind,x);

    int operation=a[id].ops;
    // this operation needs to be done
    if(operation){
        // 1 means xor to be done
        return  a[id].val=(left ^ right);

    }else{
        return a[id].val=( left | right);
    }


}


   
   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int z,q;
    cin>>z>>q;
    int n=(1<<z);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(0,0,n-1);

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // for(int i=0;i<=6;i++){
    //     cout<<a[i].val<<" "<<a[i].ops<<endl;;
    // }

    while(q--){
        int ind,x;
        cin>>ind>>x;
        ind--;
        cout<<query(0,0,n-1,ind,x)<<"\n";;

        // for(int i=0;i<=6;i++){
        //    cout<<a[i].val<<" "<<a[i].ops<<endl;;
        // }

    }




    
   
   
 return 0;
}