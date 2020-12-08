#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alphabet[16];

void printPW(int index, int cnt, int mo, int ja, string s){
    if(cnt==L){
        if(mo>=1 && ja >=2){
            cout<<s<<endl;
        }
        return;
    }
    //index가 끝나는 경우
    if(index==C) return;
    if(alphabet[index]=='a'||alphabet[index]=='e'||alphabet[index]=='i'||alphabet[index]=='o'||alphabet[index]=='u'){
        //모음일 경우
        printPW(index+1,cnt+1,mo+1,ja,s+alphabet[index]);
    }else{
        //자음일 경우
        printPW(index+1,cnt+1,mo,ja+1,s+alphabet[index]);
    }
    //알파벳 선택 X
    printPW(index+1,cnt,mo,ja,s);
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>alphabet[i];
    }
    sort(alphabet,alphabet+C);

    printPW(0,0,0,0,"");
    return 0;
}