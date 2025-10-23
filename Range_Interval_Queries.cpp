// Write your code here


#include<bits/stdc++.h>
using namespace std;


struct Node{
    vector<int> v;
    Node(){
    }
};

const int mx=4*200001;
Node a[mx];

int arr[200001];

void mergef(int id,int left,int right){
    // I have two sorted array
    // a[left].v
    // a[right].v

    // merge them 
    int sz1=(a[left].v).size();
    int sz2=(a[right].v).size();
    (a[id].v).resize(sz1+sz2);
    merge((a[left].v).begin(),(a[left].v).end(),(a[right].v).begin(),(a[right].v).end(),(a[id].v).begin());
}


void build(int id, int lo, int hi){
    //a[id].v.clear();
    if(lo==hi){
        (a[id].v).push_back(arr[lo]);
        return;
    }
    int mid=(lo+hi)/2;
    build(2*id+1,lo,mid);
    build(2*id+2,mid+1,hi);
    mergef(id,2*id+1,2*id+2);
}

int query(int id,int lo,int hi, int ql,int qr, int x){
    if(lo>qr || hi<ql){
        return 0;
    }
    if(lo>=ql && hi<=qr){
        // binary serach here
        // complete overlap

        // find the mininum index
        // which is >x
        auto it = upper_bound(a[id].v.begin(), a[id].v.end(), x);
        return a[id].v.end() - it;
    
    }
    int mid=(lo+hi)/2;
    int left=query(2*id+1,lo,mid,ql,qr,x);
    int right=query(2*id+2,mid+1,hi,ql,qr,x);
    return left+right;;

}


void solve(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // Merge Sort Tree
    int n,qq;
    cin>>n>>qq;
    //for(int i=0; i<4*n; i++) a[i].v.clear();
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        arr[i]=q;;
    }

    build(0,0,n-1);

    

    while(qq--){
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        l--;
        r--;
        int ans=0;
        x--;
        //y--;
        //cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;

        int ans1=query(0,0,n-1,l,r,x);
        int ans2=query(0,0,n-1,l,r,y);
       // cout<<ans1<<" "<<ans2<<endl;
        cout<<ans1-ans2<<endl;;

    }

   





}


int32_t main(){
    
    int tt=1;
    

    while(tt--){
        solve();
    }

    return 0;
}