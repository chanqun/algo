#include <iostream>
#include <queue>

using namespace std;

int n;

int solution(int n){
    int answer = 0;
    int q1[6]={0,};
    int chk=0;
    q1[5]=1;
    
    while(chk<n){

        int num = 0;
        for(int i=1;i<=4;i++){
            num += q1[i];
        }
        answer += q1[0];
        for(int i=0;i<5;i++){
            q1[i]=q1[i+1];
        }
        q1[5]=num;
        chk++;
    }

    for(int i=0;i<6;i++){
        answer += q1[i];
    }

    return answer;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);

    cin >> n;
    int sol = solution(n);
    cout<< sol;
    return 0;
}