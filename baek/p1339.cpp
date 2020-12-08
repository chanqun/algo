#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N;
int alphabet[26];
vector <string> number;

bool compare(int a, int b){
    if(a>b) return true;
    return false;
}

void calculate(){
    for(int i=0;i<N;i++){
        string now = number[i];
        int len = now.length();
        int pow = 1;

        for(int j=len-1;j>=0;j--){
            int tempNum = now[j] - 'A';
            alphabet[tempNum] = alphabet[tempNum] + pow;
            pow = pow *10;
        }
    }
    sort(alphabet, alphabet+26,compare);

    int result = 0;
    int number = 9;
    for(int i=0;i<26;i++){
        if(alphabet[i]==0) break;
        result = result + (alphabet[i]*number);
        number--;
    }
    cout<<result<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);
    
    cin>>N;
    for(int i=0;i<N;i++){
        string temp; 
        cin>>temp;
        number.push_back(temp);
    }

    calculate();

    return 0;
}