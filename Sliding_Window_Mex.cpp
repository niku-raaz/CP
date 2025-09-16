#include<bits/stdc++.h>
using namespace std;
#define int long long

class Mex{
    
    vector<int> f;
    set<int> s; // tells me which is not present
    int mex;
    int k;
    public:

    Mex(int a[],int k){
        f.resize(k+1);

        for(int i=0;i<=k;i++){
            s.insert(i);
            f[i]=0;
        }
        this->k=k;
        for(int i=0;i<k;i++){
            if(a[i]<=k){
              f[a[i]]++;
            }
            if(s.count(a[i])){
                s.erase(a[i]);
            }
        }
        mex=*s.begin();
    }

    void calc(){
        mex=*s.begin();
    }

    void add(int x){
        if(x<=k){
           f[x]++;
           if(f[x]==1 && x<=k){
              s.erase(x); // ab presnt hogya
           }
        }
    }

    void del(int x){
        if(x<=k){
           f[x]--;
           if(f[x]==0 && x<=k){
            if(x<=k){
                s.insert(x); // not prent now
            }
            mex=min(mex,x);
           }
        }
        
    }

    void update(int x,int y){
        if(x==y){
            return;
        }
        add(x);
        del(y);
        // recalcultion condtion
        if(x==mex){
            calc();
        }
    }
    void res(){
        cout<<mex<<" ";
    }


};
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // map for f[x];
    // int mex ;
    Mex M(a,k);

    for(int i=k;i<n;i++){
        M.res();
        M.update(a[i],a[i-k]);
    }
    M.res();


    
   
   
 return 0;
}