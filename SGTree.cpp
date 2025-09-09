#include<bits/stdc++.h>
using namespace std;
#define int long long
   

class SGTree{
    private:
        vector<int> v;
    public:
        SGTree(int n){
            v.resize(4*n+1,1e9);
        }

        //0 based indexing 

        void build(int ind,int lo, int hi,vector<int>& a){
            if(lo==hi){
               v[ind]=a[lo];
               return ;
            }
            int mid=(lo+hi)/2;
            int left=2*ind+1;
            int right=2*ind+2;
            build(left,lo,mid,a);
            build(right,mid+1,hi,a);

            v[ind]=min(v[left],v[right]);
            return;
        }

        void printV(){
            for(int i=0;i<v.size();i++){
               cout<<v[i]<<" ";
            }
            cout<<endl;
        }

        int query(int l,int r,int lo, int hi){

            // com
            

        }

};
   
int32_t main(){
    int n=8;

    vector<int> a={1,2,3,4,5,6,7,8};

    SGTree seg(n);

    seg.build(0,0,n-1,a);
    seg.printV();


    
   
   
 return 0;
}