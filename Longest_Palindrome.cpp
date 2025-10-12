#include<bits/stdc++.h>
using namespace std;
#define int long long

class Man{
    vector<int> p;
    string t;
    int n;
    public:
    Man(string s){

        t="#";
        for(auto x: s){
            t+=x;
            t+='#';
        }
        n=t.size();
        build(t);
    }

    void build(string s){
        p.assign(n,1);
        int l=1;
        int r=1;

        for(int i=1;i<n;i++){
            p[i]=max(0LL,min(r-i,p[l+r-i]));

            while(i-p[i]>=0 && i+p[i]<n && s[i-p[i]]==s[i+p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                r=i+p[i];
                l=i-p[i];
            }
        }
    }

    string getLargest(){
        string ans="";


        int mx=2;
        for(int i=1;i<n;i++){
            mx=max(mx,p[i]);
        }

        int mid=0;
        int len=0;

        for(int i=1;i<n;i++){
            if(p[i]==mx){
                mid=i;
                len=p[i];
                break;
            }
        }

        for(int i=mid-len+1;i<mid+len;i++){
            if(t[i]!='#'){
                ans+=t[i];
            }
        }

        return ans;


    }

};
   
   
int32_t main(){

    string s;
    cin>>s;

    Man M(s);
    cout<<M.getLargest();

    
   
   
 return 0;
}