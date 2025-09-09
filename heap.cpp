#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
       int capacity; // max len
       int size; // current size
       int *arr; // array for heap

    Heap(int n){
        capacity=n;
        size=0;
        arr= new int[n];
    }

    int par(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    // Functions
    void swap(int * x, int * y) {
       int temp = * x;
       * x = * y;
       * y = temp;
    }

    void insert(int x){
        if(size==capacity){
            cout<<"Overflow \n";
            return;
        }

        arr[size]=x; //adding to the lowest and rightmost of the tree
        int k=size;
        size+=1;

        // Heap Property may be violated
        while(k!=0 && arr[par(k)]>arr[k]){
            swap( & arr[par(k)], & arr[k]);
            k=par(k);
        }

    }


    void heapify(int ind){
        int ri=right(ind);
        int li=left(ind);

        int small=ind; // voilated
        if(li<size && arr[li]<arr[small]){
            small=li;
        }
        if(ri< size && arr[ri]<arr[small]){
            small=ri;
        }

        // small stores index of minimum val

        if(small!=ind){ // violation
            swap( & arr[ind], & arr[small] );
            heapify(small);
        }
    }

    int getMin(){
        return arr[0];
    }

    int extractMin(){
        if(size<=0){
            return INT_MAX;
        }
        if(size==1){
            size--;
            return arr[0];
        }

        int mini=arr[0];

        // copy last node val to root
        // then heapify

        arr[0]=arr[size-1];
        size--;
        heapify(0);
        return mini;

    }

    void decreaseKey(int i, int val){
        arr[i]=val;

        while(i!=0 && arr[par(i)]>arr[i]){ // only to the up
            swap( & arr[par(i)], & arr[i]);
            i=par(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    
};
   
   
int main(){
    Heap h(25);

    for(int i=10;i>=0;i--){
        h.insert(i);
        h.print();
    }

    


    
   
   
 return 0;
}