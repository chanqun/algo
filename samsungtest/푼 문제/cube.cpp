#include <iostream>

using namespace std;

int T, N;
char cube[6][3][3];

void cubeset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cube[0][i][j]='w';
            cube[1][i][j]='r';
            cube[2][i][j]='y';
            cube[3][i][j]='g';
            cube[4][i][j]='b';
            cube[5][i][j]='o';
        }
    }
}
void pri(int a){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<cube[a][i][j];
        }
        cout<<"\n";
    }
}

void rotateO(int a, char b){
    if(b=='+'){
        char temp = cube[a][0][0];
        cube[a][0][0]=cube[a][2][0];
        cube[a][2][0]=cube[a][2][2];
        cube[a][2][2]=cube[a][0][2];
        cube[a][0][2]=temp;
        temp = cube[a][0][1];
        cube[a][0][1]=cube[a][1][0];
        cube[a][1][0]=cube[a][2][1];
        cube[a][2][1]=cube[a][1][2];
        cube[a][1][2]=temp;
    }else{
        char temp = cube[a][0][0];
        cube[a][0][0]=cube[a][0][2];
        cube[a][0][2]=cube[a][2][2];
        cube[a][2][2]=cube[a][2][0];
        cube[a][2][0]=temp;
        temp = cube[a][0][1];
        cube[a][0][1]=cube[a][1][2];
        cube[a][1][2]=cube[a][2][1];
        cube[a][2][1]=cube[a][1][0];
        cube[a][1][0]=temp;
    }
}

void rotateL(char b){
    if(b=='-'){
        char temp1=cube[0][0][0];
        char temp2=cube[0][1][0];
        char temp3=cube[0][2][0];
        cube[0][0][0]=cube[1][0][0];
        cube[0][1][0]=cube[1][1][0];
        cube[0][2][0]=cube[1][2][0];        
        cube[1][0][0]=cube[2][0][0];
        cube[1][1][0]=cube[2][1][0];
        cube[1][2][0]=cube[2][2][0];
        cube[2][0][0]=cube[5][2][2];
        cube[2][1][0]=cube[5][1][2];
        cube[2][2][0]=cube[5][0][2];
        cube[5][2][2]=temp1;
        cube[5][1][2]=temp2;
        cube[5][0][2]=temp3;
    }else{
        char temp1=cube[0][0][0];
        char temp2=cube[0][1][0];
        char temp3=cube[0][2][0];
        cube[0][0][0]=cube[5][2][2];
        cube[0][1][0]=cube[5][1][2];
        cube[0][2][0]=cube[5][0][2];        
        cube[5][2][2]=cube[2][0][0];
        cube[5][1][2]=cube[2][1][0];
        cube[5][0][2]=cube[2][2][0];
        cube[2][0][0]=cube[1][0][0];
        cube[2][1][0]=cube[1][1][0];
        cube[2][2][0]=cube[1][2][0];
        cube[1][0][0]=temp1;
        cube[1][1][0]=temp2;
        cube[1][2][0]=temp3;
    }
}

void rotateR(char b){
    if(b=='+'){
        char temp1=cube[0][0][2];
        char temp2=cube[0][1][2];
        char temp3=cube[0][2][2];
        cube[0][0][2]=cube[1][0][2];
        cube[0][1][2]=cube[1][1][2];
        cube[0][2][2]=cube[1][2][2];        
        cube[1][0][2]=cube[2][0][2];
        cube[1][1][2]=cube[2][1][2];
        cube[1][2][2]=cube[2][2][2];
        cube[2][0][2]=cube[5][2][0];
        cube[2][1][2]=cube[5][1][0];
        cube[2][2][2]=cube[5][0][0];
        cube[5][2][0]=temp1;
        cube[5][1][0]=temp2;
        cube[5][0][0]=temp3;
    }else{
        char temp1=cube[0][0][2];
        char temp2=cube[0][1][2];
        char temp3=cube[0][2][2];
        cube[0][0][2]=cube[5][2][0];
        cube[0][1][2]=cube[5][1][0];
        cube[0][2][2]=cube[5][0][0];        
        cube[5][2][0]=cube[2][0][2];
        cube[5][1][0]=cube[2][1][2];
        cube[5][0][0]=cube[2][2][2];
        cube[2][0][2]=cube[1][0][2];
        cube[2][1][2]=cube[1][1][2];
        cube[2][2][2]=cube[1][2][2];
        cube[1][0][2]=temp1;
        cube[1][1][2]=temp2;
        cube[1][2][2]=temp3;
    }
}

void rotateU(char b){
    if(b=='+'){
        char temp1=cube[3][0][0];
        char temp2=cube[3][0][1];
        char temp3=cube[3][0][2];
        cube[3][0][0]=cube[1][0][0];
        cube[3][0][1]=cube[1][0][1];
        cube[3][0][2]=cube[1][0][2];        
        cube[1][0][0]=cube[4][0][0];
        cube[1][0][1]=cube[4][0][1];
        cube[1][0][2]=cube[4][0][2];
        cube[4][0][0]=cube[5][0][0];
        cube[4][0][1]=cube[5][0][1];
        cube[4][0][2]=cube[5][0][2];
        cube[5][0][0]=temp1;
        cube[5][0][1]=temp2;
        cube[5][0][2]=temp3;
    }else{
        char temp1=cube[3][0][0];
        char temp2=cube[3][0][1];
        char temp3=cube[3][0][2];
        cube[3][0][0]=cube[5][0][0];
        cube[3][0][1]=cube[5][0][1];
        cube[3][0][2]=cube[5][0][2];        
        cube[5][0][0]=cube[4][0][0];
        cube[5][0][1]=cube[4][0][1];
        cube[5][0][2]=cube[4][0][2];
        cube[4][0][0]=cube[1][0][0];
        cube[4][0][1]=cube[1][0][1];
        cube[4][0][2]=cube[1][0][2];
        cube[1][0][0]=temp1;
        cube[1][0][1]=temp2;
        cube[1][0][2]=temp3;
    }
}

void rotateD(char b){
    if(b=='-'){
        char temp1=cube[3][2][0];
        char temp2=cube[3][2][1];
        char temp3=cube[3][2][2];
        cube[3][2][0]=cube[1][2][0];
        cube[3][2][1]=cube[1][2][1];
        cube[3][2][2]=cube[1][2][2];        
        cube[1][2][0]=cube[4][2][0];
        cube[1][2][1]=cube[4][2][1];
        cube[1][2][2]=cube[4][2][2];
        cube[4][2][0]=cube[5][2][0];
        cube[4][2][1]=cube[5][2][1];
        cube[4][2][2]=cube[5][2][2];
        cube[5][2][0]=temp1;
        cube[5][2][1]=temp2;
        cube[5][2][2]=temp3;
    }else{
        char temp1=cube[3][2][0];
        char temp2=cube[3][2][1];
        char temp3=cube[3][2][2];
        cube[3][2][0]=cube[5][2][0];
        cube[3][2][1]=cube[5][2][1];
        cube[3][2][2]=cube[5][2][2];        
        cube[5][2][0]=cube[4][2][0];
        cube[5][2][1]=cube[4][2][1];
        cube[5][2][2]=cube[4][2][2];
        cube[4][2][0]=cube[1][2][0];
        cube[4][2][1]=cube[1][2][1];
        cube[4][2][2]=cube[1][2][2];
        cube[1][2][0]=temp1;
        cube[1][2][1]=temp2;
        cube[1][2][2]=temp3;
    }
}
void rotateF(char b){
    if(b=='-'){
        char temp1=cube[0][2][0];
        char temp2=cube[0][2][1];
        char temp3=cube[0][2][2];
        cube[0][2][0]=cube[4][0][0];
        cube[0][2][1]=cube[4][1][0];
        cube[0][2][2]=cube[4][2][0];        
        cube[4][0][0]=cube[2][0][2];
        cube[4][1][0]=cube[2][0][1];
        cube[4][2][0]=cube[2][0][0];
        cube[2][0][2]=cube[3][2][2];
        cube[2][0][1]=cube[3][1][2];
        cube[2][0][0]=cube[3][0][2];
        cube[3][2][2]=temp1;
        cube[3][1][2]=temp2;
        cube[3][0][2]=temp3;
    }else{
        char temp1=cube[0][2][0];
        char temp2=cube[0][2][1];
        char temp3=cube[0][2][2];
        cube[0][2][0]=cube[3][2][2];
        cube[0][2][1]=cube[3][1][2];
        cube[0][2][2]=cube[3][0][2];
        cube[3][2][2]=cube[2][0][2];
        cube[3][1][2]=cube[2][0][1];
        cube[3][0][2]=cube[2][0][0];
        cube[2][0][2]=cube[4][0][0];
        cube[2][0][1]=cube[4][1][0];
        cube[2][0][0]=cube[4][2][0];
        cube[4][0][0]=temp1;
        cube[4][1][0]=temp2;
        cube[4][2][0]=temp3;
    }
}
void rotateB(char b){
    if(b=='+'){
        char temp1=cube[0][0][0];
        char temp2=cube[0][0][1];
        char temp3=cube[0][0][2];
        cube[0][0][0]=cube[4][0][2];
        cube[0][0][1]=cube[4][1][2];
        cube[0][0][2]=cube[4][2][2];        
        cube[4][0][2]=cube[2][2][2];
        cube[4][1][2]=cube[2][2][1];
        cube[4][2][2]=cube[2][2][0];
        cube[2][2][2]=cube[3][2][0];
        cube[2][2][1]=cube[3][1][0];
        cube[2][2][0]=cube[3][0][0];
        cube[3][2][0]=temp1;
        cube[3][1][0]=temp2;
        cube[3][0][0]=temp3;
    }else{
        char temp1=cube[0][0][0];
        char temp2=cube[0][0][1];
        char temp3=cube[0][0][2];
        cube[0][0][0]=cube[3][2][0];
        cube[0][0][1]=cube[3][1][0];
        cube[0][0][2]=cube[3][0][0];
        cube[3][2][0]=cube[2][2][2];
        cube[3][1][0]=cube[2][2][1];
        cube[3][0][0]=cube[2][2][0];
        cube[2][2][2]=cube[4][0][2];
        cube[2][2][1]=cube[4][1][2];
        cube[2][2][0]=cube[4][2][2];
        cube[4][0][2]=temp1;
        cube[4][1][2]=temp2;
        cube[4][2][2]=temp3;
    }
}
void rotate(char a, char b){
    if(a=='L'){
        rotateO(3,b);
        rotateL(b);
    }else if(a=='R'){
        rotateO(4,b);
        rotateR(b);
    }else if(a=='U'){
        rotateO(0,b);
        rotateU(b);
    }else if(a=='D'){
        rotateO(2,b);
        rotateD(b);
    }else if(a=='F'){
        rotateO(1,b);
        rotateF(b);
    }else if(a=='B'){
        rotateO(5,b);
        rotateB(b);
    }
}

int main(){

    freopen("input.txt","r",stdin);
    
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        cubeset();
        for(int i=0;i<N;i++){
            char a,b;
            cin>>a>>b;
            rotate(a,b);
        }
        pri(0);
    }

    return 0;
}