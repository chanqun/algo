#include <iostream>

using namespace std;

int arr[101];
int N;
int res=0;

int main(){

    freopen("input.txt","r",stdin);

    cin>>N;

    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        if(arr[temp]==0){
            arr[temp]=1;
        }else{
            res++;
        }
    }
    
    cout<<res;

    return 0;
}