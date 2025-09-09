#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;

    queue<int> q;

    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while(!q.empty()){

        if(q.size()==1){
            cout<<q.front();
            q.pop();
            return 0;
        }
        int x=q.front();
        q.pop();
        q.push(x);
        x=q.front();
        cout<<x<<" ";
        q.pop();
    }

    
   
   
 return 0;
}