#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[13]={0,};
vector <int> op;
bool chk[20]={false,};
int operate[13]={0,};
int max_solution=-1000000000;
int min_solution=1000000000;

void counting(){
    int now = 0;
    now+=arr[1];

    for(int i=0;i<op.size();i++){
        if(operate[i]==1){
            now+=arr[i+2];
        }else if(operate[i]==2){
            now-=arr[i+2];
        }else if(operate[i]==3){
            now*=arr[i+2];
        }else if(operate[i]==4){
            now/=arr[i+2];
        }
    }
    if(now>max_solution){
        max_solution=now;
    }
    if(now<min_solution){
        min_solution=now;
    }
}

void solve(int cnt){

    if(cnt>=op.size()){
        counting();
    }
    else{
        for(int i=0;i<op.size();i++){
            if(!chk[i]){
                chk[i]=true;
                operate[cnt]=op[i];
                solve(cnt+1);
                chk[i]=false;
                operate[cnt]=0;
            }
            
        }
    }
}

int main(){
    
    freopen("input.txt","r",stdin);
    
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=4;i++){
        int temp;
        cin>>temp;
        for(int j=1;j<=temp;j++){
            op.push_back(i);
        }
    }
    
    solve(0);
    cout<<max_solution<<"\n";
    cout<<min_solution;
    return 0;
}