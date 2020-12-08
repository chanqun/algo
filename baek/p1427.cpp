#include <iostream>

using namespace std;
int N;
int arr[10];
int main(){
    cin>>N;
    while(N!=0){
        int a = N%10;
        arr[a]++;
        N=N/10;
    }
    for(int i=9;i>=0;i--){
        while(arr[i]!=0){
            cout<<i;
            arr[i]--;
        }
    }
    return 0;
}