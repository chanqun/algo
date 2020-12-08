#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int num[100000];

void binarySearch(int chk){
    int start=0;
    int end=N-1;
    int mid;
    while(end>=start){
        mid=(start+end)/2;
        if(num[mid]==chk){
            cout<<1<<"\n";
            return;
        }else if(num[mid]>chk){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout<<0<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N);
    cin>>M;
    for(int i=0;i<M;i++){
        int chk;
        cin>>chk;
        binarySearch(chk);
    }
    return 0;
}