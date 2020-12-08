#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;
int res=0;
int num[28];
vector <int> solution;
int multiple(int x){
    if(x==0){
        return 1;
    }else if(x==1){
        return 16;
    }else{
        return 16*multiple(x-1);
    }
}

void simulation(){
    for(int j=0;j<N/4+1;j++){
        int temp =num[0];
        for(int i=0;i<N-1;i++){
            num[i]=num[i+1];
        }
        num[N-1]=temp;
        int chkNum =0;
        int cnt=N/4-1;
        for(int i=0;i<N;i++){
            chkNum+=num[i]*multiple(cnt);
            cnt--;
            if(cnt==-1){
                cnt=N/4-1;
                solution.push_back(chkNum);
                chkNum=0;
            }
        }
    }
    sort(solution.begin(),solution.end());
    solution.erase(unique(solution.begin(),solution.end()),solution.end());
}

void solve(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        char a;
        cin>>a;
        if(a>60)    num[i] = a-55;
        else    num[i] = a-48;
    }
    simulation();
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>T;
    for(int i=1;i<=T;i++){
        solution.clear();
        solve();
        res=solution[solution.size()-K];
        cout<<"#"<<i<<" "<<res<<"\n";
    }
    return 0;
}