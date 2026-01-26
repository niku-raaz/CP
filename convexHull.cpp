#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Pts pair<int,int>

int sq(int x){
    return x*x;
}

Pts subtract(Pts& a, Pts& b){
    return {a.first-b.first,a.second-b.second};
}
int cross(Pts& p, Pts& a, Pts& b){ // its cross product not Dot
    Pts v1=subtract(a,p);
    Pts v2=subtract(b,p);
    return v1.first*v2.second - v1.second*v2.first; // like determinant
}

int dist2(Pts& a, Pts& b){
    return sq(a.first-b.first) + sq(a.second-b.second);
}

vector<int> convexHull(vector<Pts>& points){
    int n=points.size();
    if(n<=1){
        return {0};
    }
    int start=0;
    // leftmost lowest 
    for(int i=1;i<n;i++){
        if(points[i]<points[start]){
            start=i;
        }
    }

    vector<int> idx;
    // remaining nodes
    for(int i=0;i<n;i++){
        if(i!=start){
            idx.push_back(i);
        }
    }

    // Sort Now on the basis of angle counter Clock wise
    sort(idx.begin(),idx.end(),[&](int a,int b){
        int cr=cross(points[start],points[a],points[b]);
        if(cr==0){
            // they are in same line 
            // so jo closer hoga phle
            return dist2(points[start],points[a])< dist2(points[start],points[b]);
        }
        // if positive then a is earlier than b
        return cr>0 ;
    });

    vector<int> hull;
    hull.push_back(start);

    for(auto i: idx){
        while(hull.size()>=2 && cross(points[hull[hull.size()-2]],points[hull.back()],points[i])<=0 ){
            hull.pop_back();
        }
        hull.push_back(i);
    }
    return hull;
}

int32_t main(){
    int n;
    cin>>n;
    vector<Pts> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    vector<int> hullIdx = convexHull(v);

        cout << hullIdx.size() << "\n";
        for (int i : hullIdx)
            cout << v[i].first << " " << v[i].second << "\n";
    
 return 0;
}