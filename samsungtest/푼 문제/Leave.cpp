#include <iostream>

using namespace std;

int N;
int chkList[25][2];
int solution=0;
int count[30]={0,};
int count2[30]={0,};

bool isOk(){
    for(int i=1;i<=N;i++){
        if(count[i]>1) return false;
    }
    if(count[N+1]>=1) return false;
    return true;
}

void solve(int chk){

    if(isOk()){
        int temp=0;
        for(int i=1;i<=N;i++){
            if(count2[i]==1){
                temp+=chkList[i][1];
            }
        }
        if(temp>solution){
            solution=temp;
        }
    }

    for(int i=1;i<=N;i++){
        if(i>chk){
            count2[i]=1;
            for(int j=0;j<chkList[i][0];j++){
                count[i+j]++;
            }
            solve(i);
            count2[i]=0;
            for(int j=0;j<chkList[i][0];j++){
                count[i+j]--;
            }
        }
    }  
}

int main(){
    
    freopen("input.txt","r",stdin);

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>chkList[i][0]>>chkList[i][1];
    }

    solve(0);
    cout<<solution;
    return 0;
}