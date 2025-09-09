#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();

        set<int> st;

        for(int i=0;i<n-3;i++){

            if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){

                st.insert(i);
            }
        }

        int q; cin>>q;

        while(q--){
            int ind;cin>>ind;
            ind--;
            char x; cin>>x;

            s[ind]=x;

            for(int i=max(0,ind-3);(i<=ind) && (i+3<n);i++){

                if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){

                     st.insert(i);
                }else{

                    // 
                    if(st.count(i)){
                        st.erase(i);
                    }
                }




            }

            if(st.size()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }








        }





    }
    
   
   
 return 0;
}