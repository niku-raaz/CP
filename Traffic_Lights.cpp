#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int l=0;
    int r=x;
    int l2=0;
    int r2=x;
    int ans=x;
    set<int> s;
    s.insert(0);
    s.insert(x);

    for(int i=0;i<n;i++){

        auto upit=s.upper_bound(a[i]);
        int up=*upit;
        int down=*(--upit);

        if(l==down && up==r){
            // this was the answer

            int len1=a[i]-down; // 4
            int len2=up-a[i];   // 1

            if(len2>len1){
                l=a[i];
                
                ans=max(len2,(r2-l2));

            }else if(len1>len2){
                r=a[i];
                
                ans=max(len1,(r2-l2));

            }else{
                // both are equal

                l2=a[i]; // r2 is same
                r=a[i];  // l is same

                ans=max(len1,(r2-l2)); // ==len2

                


            }


        }else if(down==l2 && up==r2){
            // this was the answer

            int len1=a[i]-down;
            int len2=up-a[i];

            if(len2>len1){
                
                l2=a[i];
                ans=max(len2,r-l);

            }else if(len1>len2){
                
                r2=a[i];
                ans=max(len1,r-l);

            }else{
                // both are equal

                l2=a[i]; // r2 is same
                r=a[i];  // l is same

                ans=max(len1,(r-l)); // ==len2

                


            }



        }

        s.insert(a[i]);
       // cout<<ans<<" ";
        cout<<l<<" "<<r<<"  "<<l2<<" "<<r2<<endl;



    }
    
   
   
 return 0;
}