#include <iostream>
#include <vector>

using namespace std;

vector <int> chk;
int N;
long long total=0;

int main(){

    freopen("input.txt","r",stdin);

    cin>>N;

    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        chk.push_back(a);
    }

    int first_d, second_d;
    cin>>first_d>>second_d;

    for(int i=0;i<N;i++){
        int a = chk[i];
        if(a-first_d<=0){
            total++;
            continue;
        }else{
            total++;
            total+=((a-first_d)/second_d);
            if((a-first_d)%second_d==0) continue;
            total++;
        }
    }

    cout<<total;

    return 0;
}