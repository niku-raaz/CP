#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    string s;
    cin>>s;

    vector<int> v;

    int ct=1;

    s='#'+s;

    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            v.push_back(ct);
            ct=1;
        }else{
            ct++;
        }

    }

    if(ct){
        v.push_back(ct);

    }

    cout<<*max_element(v.begin(),v.end());
    



    
   
   
 return 0;
}