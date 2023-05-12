#include <iostream>
using namespace std;
int count=0;

int swap(int *a, int x, int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}

void heapify(int *a, int n, int i){
    int l=2*i, largest=i;
    int r=2*i+1;
    if(l<=n && a[l]>a[largest]) {largest=l;}
    if(r<=n && a[r]>a[largest]) {largest=r;}
    if(largest!=i){
        count++;
        swap(a, i, largest);
        heapify(a,n, largest);
    }
}

void buildMaxHeap(int *a, int n){
    for(int i=n/2; i>=0; i--){
        heapify(a,n,i);
    }
}

void heapsort(int *a, int n){
    buildMaxHeap(a,n);
    for(int i=n; i>0; i--){
        swap(a,0,i);
        heapify(a,i-1, 0);
    }
}

int main(){
    int n=5;
    int a[]= {5,4,3,2,1};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    heapsort(a,n-1);
    cout<<"\nSorted array: ";
    for(int i: a) cout<<i <<" ";
    cout<<"\ncount: "<<count;
}