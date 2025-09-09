#include<bits/stdc++.h>
using namespace std;

struct node{
    int ct;
    node(){
        ct=0;
    }
};

int arr[1002][1002];
node a[5];

int build(int id,int x1,int x2,int y1,int y2){

    if(x1>x2 || y1>y2){
        return 0;
    }
    
    if(x1==x2 && y1==y2){
        a[id].ct=arr[x1][y1];
      //  cout<<x1<<" "<<y1<<" "<<id<<" "<<a[id].ct<<endl;
        return arr[x1][y1]; 
    }

    int xmid=(x1+x2)/2;
    int ymid=(y1+y2)/2;

    int ch1=4*id+1;
    int ch2=4*id+2;
    int ch3=4*id+3;
    int ch4=4*id+4;

    int ans=0;

    ans+=build(ch1,x1,xmid,y1,ymid);
    ans+=build(ch2,x1,xmid,ymid+1,y2);
    ans+=build(ch3,xmid+1,x2,y1,ymid);
    ans+=build(ch4,xmid+1,x2,ymid+1,y2);

    a[id].ct=ans;
    return ans;
}

bool areNonOverlapping(int x1, int y1, int x2, int y2,
                       int a1, int b1, int a2, int b2) {
    // If one rectangle is completely to the left of the other
    if (x2 < a1 || a2 < x1) return true;

    // If one rectangle is completely above the other
    if (y2 < b1 || b2 < y1) return true;

    // Otherwise, they overlap
    return false;
}


int query(int id, int x1,int x2,int y1,int y2, int lq1,int rq1,int lq2,int rq2){

    // non overlapping case
    if(areNonOverlapping(x1,y1,x2,y2,lq1,rq1,lq2,rq2)){
        return 0;
    }

    // overlapp

    if(x1>=lq1 && x2<=lq2 && y1>=rq1 && y2<=rq2){
        return a[id].ct;
    }

    int xmid=(x1+x2)/2;
    int ymid=(y1+y2)/2;

    int ch1=4*id+1;
    int ch2=4*id+2;
    int ch3=4*id+3;
    int ch4=4*id+4;
    int ans=0;

    ans+=query(ch1,x1,xmid,y1,ymid,lq1,rq1,lq2,rq2);
    ans+=query(ch2,x1,xmid,ymid+1,y2,lq1,rq1,lq2,rq2);
    ans+=query(ch3,xmid+1,x2,y1,ymid,lq1,rq1,lq2,rq2);
    ans+=query(ch4,xmid+1,x2,ymid+1,y2,lq1,rq1,lq2,rq2);

    return ans;
}

   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;cin>>x;
            if(x=='.'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }
    //build(0,0,n-1,0,n-1);

    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            arr[i][j]+=arr[i][j-1];
        }
    }

    for(int j=0;j<n;j++){
        for(int i=1;i<n;i++){
            arr[i][j]+=arr[i-1][j];
        }
    }





    while(q--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
       // cout<<query(0,0,n-1,0,n-1,x1,y1,x2,y2)<<endl;

       int ans=0;

       ans+=arr[x2][y2];
       int x,y;
       x=x1-1;
       y=y1-1;

       if(x>=0 && y>=0){
        ans+=arr[x][y];
       }

       if(x>=0){
        ans-=arr[x][y2];
       }
       if(y>=0){
        ans-=arr[x2][y];
       }

       cout<<ans<<endl;

    }

 return 0;
}