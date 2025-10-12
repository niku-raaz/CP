 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
   
   
   
//#include <ext/pb_ds/assoc_container.hpp> // Common file   
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update   
//#include <ext/pb_ds/detail/standard_policies.hpp>   
   
//using namespace __gnu_pbds;  
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;   
    
//void myerase(ordered_set &t, int v){   
//     int rank = t.order_of_key(v);//Number of elements that are less than v in t   
//     ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t   
//     t.erase(it);  
//}   
   
   
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)
   
   
bool isPrime(int n){
      if(n<=1){
      return false;
      }
   for(int i = 2;i*i<=n;i++){
     if(n%i==0){
     return false;
       }
    }
  return true;
    }
   
   
   
bool sbs(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
   }
   
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1;
   while (b > 0) {
        if (b & 1)
          res = res * a % m;
        a = a * a % m;
        b >>= 1;
   }
  return res;
}  

// write mancher




class Man{
    public:
    string s;
    int n;
    vector<int> pal;
    

    Man(string str){
        s="#";
        for(auto x: str){
            s+=x;
            s+='#';
        }
        n=s.size();
        pal.assign(n,1);
        build();
    }

    void build(){
        // s pe kro everyting
        int l=0;
        int r=-1;

        for(int i=1;i<n;i++){
            pal[i]=max(0LL,min(r-i,pal[l+r-i]));
            while( i-pal[i]>=0 && i+pal[i]<n &&  s[i-pal[i]]==s[i+pal[i]]){
                pal[i]++;
            }
            if(i+pal[i]-1>r){
                r=i+pal[i]-1;
                l=i-pal[i]+1;
            }
        }
    }
};






void solve(){

    string s;cin>>s;
    Man M(s);
    
    //py;
   
    int n=s.size();
    vector<int> mat(n,0);

    int lo=0;
    int hi=n-1;

    while(lo<=hi){
        if(s[lo]==s[hi]){
            mat[lo]=1;
            mat[hi]=1;
            lo++;
            hi--;
        }else{
            break;
        }
    }

    int ans=1;

//     show(mat);

//    cout<<M.s<<endl;
//     show(M.pal);pl;

    for(int i=0;i<M.pal.size();i++){

        int x=M.pal[i]-1;
        int left=i-x+1;
        int right=i+x-1;
        if(left>right){
           // cout<<"skip";pl;
            continue;
        }
        int len=(right-left+1)/2;
        len++;
        
        // left to right is palindrome
        // upadte
        // left  // 
        // right
        //cout<<M.s[i]<<" "<<x<<" "<<i<<" "<<left<<" "<<right<<" "<<len<<" ";pl;

        // i go x, left, right, len

        int real_left=left/2;
        int mirror_left=n-1-real_left;
        int real_right=right/2;
        int mirror_right=n-1-real_right;
        int res=len;
        bool good=0;

        if(real_right==n-1 || real_left==0){
            good=1;
        }

        if(real_left-1 >=0 && mat[real_left-1] && mirror_left+1>real_right){
            res=max(res,len+2*real_left);
            good=1;
        }

        if(real_right+1<n && mat[real_right+1] && mirror_right-1<real_left){
            res=max(res,len+2*(n-real_right-1));
            good=1;
        }
        if(good==0){
            continue;
        }

        ans=max(ans,res);
        
    }

    //cout<<ans;pl;

    // lets create answer

    for(int i=0;i<M.pal.size();i++){

        int x=M.pal[i]-1;
        int left=i-x+1;
        int right=i+x-1;
        if(left>right){
           // cout<<"skip";pl;
            continue;
        }
        int len=(right-left+1)/2;
        len++;

        int real_left=left/2;
        int mirror_left=n-1-real_left;
        int real_right=right/2;
        int mirror_right=n-1-real_right;
        int res=len;
        bool good=0;
        if(real_right==n-1 || real_left==0){
            good=1;
        }
        

        if(real_left-1 >=0 && mat[real_left-1] && mirror_left+1>real_right){
            res=max(res,len+2*real_left);
            good=1;
        }

        if(real_right+1<n && mat[real_right+1] && mirror_right-1<real_left){
            res=max(res,len+2*(n-real_right-1));
            good=1;
        }
        if(good==0){
            continue;
        }

        if(res==ans){

            // create answer and break;

            // from real_left to real_right

            string mid="";

            for(int j=real_left;j<=real_right;j++){
                mid+=s[j];
            }

            // now add prefix
            // or suffix

            string pref="";
            string suff="";

            if(real_left-1 >=0 && mat[real_left-1] && mirror_left+1>real_right){

                // pre is from 0 to real_left-1

                for(int j=0;j<=real_left-1;j++){
                    pref+=s[j];
                }
            
            }

            if(real_right+1<n && mat[real_right+1] && mirror_right-1<real_left){
                // suff is prom real_right+1 to n-1

                for(int j=real_right+1;j<n;j++){
                    suff+=s[j];
                }
            }

            if(pref.size()>suff.size()){
                cout<<pref<<mid;
                reverse(pref.begin(),pref.end());
                cout<<pref;

            }else{
                mid+=suff;
                reverse(suff.begin(),suff.end());
                cout<<suff<<mid;
                
            }

            pl;

            return;


            break;
        }
        
    }


    

}
   
   
   
int32_t main(){
        raaz

       // pre();
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }