#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;

    vector<array<int,3>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0];
        v[i][2]=i;
    }

    sort(v.begin(),v.end());


    // 2 4 4
    // 1 2 4

    int ans[n];

    set<array<int,2>> s;//{end time,room}

    // 1 1 1 1 1
    // 1 1 1 1 1

    // 1 

    for(int i=0;i<n;i++){

        int starttime=v[i][1];
        int endtime=v[i][0];
        int ind=v[i][2];

        auto it= s.lower_bound({starttime});

        if(it!=s.begin()){
            --it;
            // this it is my 
            ans[ind]=(*it)[1];

            s.erase(it);


        }else{
            // kuchh nhi kr skte

            ans[ind]=s.size();


        }

        s.insert({endtime,ans[ind]});


       


    }

    cout<<s.size()<<endl;

    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    

    
   
   
 return 0;
}