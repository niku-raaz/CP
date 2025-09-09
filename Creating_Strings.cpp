#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    string s;
    cin>>s;

    int n=s.size();


    int tot=1;

    for(int i=1;i<=n;i++){
        tot*=i;
    }

    set<string> st;


    do{

        next_permutation(s.begin(),s.end());
        st.insert(s);
        tot--;


    }while(tot);

    cout<<st.size()<<" \n";

    for(auto x: st){
        cout<<x<<"\n";
    }


    
   





    
   
   
 return 0;
}