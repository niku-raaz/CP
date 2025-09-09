#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a.begin(),a.end());
\
    long long can=0;

    for(int i=0;i<n;i++){

        if(a[i]>can+1){
            // we cant make can+1
            cout<<can+1;
            return 0;
        }else{
            can+=a[i];
        }

    }

    cout<<can+1;



    

   
 return 0;
}