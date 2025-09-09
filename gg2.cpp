#include<bits/stdc++.h>
using namespace std;
   
int findX(int a,int b, int c){

    int x=0;

    for(int i=31;i>=0;i--){
        if((c>>i)&1){
            // 1 hai
            if(((a>>i)&1)==1 && ((b>>i)&1)==1){
                
            }else{
                x+=(1<<i);
            }
        }else{

            // o hai

            if(((a>>i)&1)==1 && ((b>>i)&1)==1){
                return -1;
            }






        }
    }

    return x;





}
   
int main(){
    
    int a,b,c;
    cin>>a>>b>>c;
    cout<<findX(a,b,c);
    
   
   
 return 0;
}