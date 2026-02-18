#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file   
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update   
#include <ext/pb_ds/detail/standard_policies.hpp>   
   
using namespace __gnu_pbds;  
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;   
    
void myerase(ordered_set &t, int v){   
    int rank = t.order_of_key(v);//Number of elements that are less than v in t   
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t   
    t.erase(it);  
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
class SGTree {
    vector<int> seg;
public:
  SGTree(int n) {
       seg.resize(4 * n + 1);
   }
   void build(int ind, int low, int high, int arr[]) {
      if (low == high) {
           seg[ind] = arr[low];
           return;
       }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
    // no overlap
    // l r low high or low high l r
    if (r < low || high < l) return INT_MAX;

    // complete overlap
    // [l low high r]
    if (low >= l && high <= r) return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(left, right);
   }
   void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
       seg[ind] = val;
       return;
    }

    int mid = (low + high) >> 1;
    if (i <= mid) update(2 * ind + 1, low, mid, i, val);
    else update(2 * ind + 2, mid + 1, high, i, val);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
class dsu {
    vector<int> rank, parent, size; 
public: 
    dsu(int n) {
       rank.resize(n+1, 0); 
       parent.resize(n+1);
       size.resize(n+1); 
       for(int i = 0;i<=n;i++) {
           parent[i] = i; 
           size[i] = 1; 
       }
   }
   int findUPar(int node) {
       if(node == parent[node])
            return node; 
         return parent[node] = findUPar(parent[node]); 
   }

   void unionByRank(int u, int v) {
       int ulp_u = findUPar(u); 
       int ulp_v = findUPar(v); 
       if(ulp_u == ulp_v) return; 
       if(rank[ulp_u] < rank[ulp_v]) {
          parent[ulp_u] = ulp_v; 
       }
       else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
       }
       else {
           parent[ulp_v] = ulp_u; 
           rank[ulp_u]++; 
       }
   }
   void unionBySize(int u, int v) {
         int ulp_u = findUPar(u); 
    int ulp_v = findUPar(v); 
    if(ulp_u == ulp_v) return; 
    if(size[ulp_u] < size[ulp_v]) {
       parent[ulp_u] = ulp_v; 
       size[ulp_v] += size[ulp_u]; 
    }
    else {
       parent[ulp_v] = ulp_u;
       size[ulp_u] += size[ulp_v]; 
    }
   }
};
class Node{
    public:
    Node* child[26];
    int cntPrefix=0;
    int cntEndswith=0;
    bool containsKey(char ch){
        int idx=ch-'a';
        return (child[idx]!=NULL);
    }

    void putKey(char ch){
        int idx=ch-'a';
        child[idx]=new Node();
    }
    Node* getKey(char ch){
        int idx=ch-'a';
        return child[idx];
    }
    void increaseEnd(){
        cntEndswith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndswith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }

};

class Trie{
    
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                // need to create this key
                node->putKey(word[i]);
            }
            node=node->getKey(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWords(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntEndswith;
    }
    int countPrefix(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void eraseWord(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
                node->reducePrefix();
            }else{
                return ;
            }
        }
        node->deleteEnd();

    }

};
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
            pal[i]=max(0,min(r-i,pal[l+r-i]));
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
vector<int> computeLPSArray(string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    // length of the previous longest prefix suffix
    int len = 0;  
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { 
                // fall back in the pattern
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int N=1000002;
int power1[1000002];
int power2[1000002];
int p1=31;
int p2=53;
int mod1=1e9+7;
int mod2=1e9+9;
int inv1[1000002];
int inv2[1000002];
void pre() {
    power1[0] = 1;
    power2[0] = 1;
    for (int i = 1; i < N; i++) {
        power1[i] = (power1[i - 1] * p1) % mod1;
        power2[i] = (power2[i - 1] * p2) % mod2;
    }

    // Compute inverse of last power
    inv1[N - 1] = binpow(power1[N - 1], mod1 - 2, mod1);
    inv2[N - 1] = binpow(power2[N - 1], mod2 - 2, mod2);

    // Fill backwards in O(N)
    for (int i = N - 2; i >= 0; i--) {
        inv1[i] = (inv1[i + 1] * p1) % mod1;
        inv2[i] = (inv2[i + 1] * p2) % mod2;
    }
}

class Hash{
    string s;
    int n;
    vector<int> pfx,pfx2;
    public:
    Hash(string& str){
        s=str;
        n=s.size();
        pfx.resize(n);
        pfx2.resize(n);
        build();
    }
    void build(){
        // pfx[i] = summation ((s[i]-'a+1)*p^i)
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=((s[i]-'a'+1)*power1[i]);
            sum%=mod1;
            pfx[i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=(s[i]-'a'+1)*power2[i];
            sum%=mod2;
            pfx2[i]=sum;
        }
    }

    int getVal1(int l,int r){
        if(l==0){
            return pfx[r];
        }
        int res=pfx[r]-pfx[l-1]+mod1;
        res%=mod1;
        res*=inv1[l];
        res%=mod1;
        return res;
    }
    int getVal2(int l,int r){
        if(l==0){
            return pfx2[r];
        }
        int res=pfx2[r]-pfx2[l-1]+mod2;
        res%=mod2;
        res*=inv2[l];
        res%=mod2;
        return res;
    }
};

   
