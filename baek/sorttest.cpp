#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
    int value;
    void toString(){
        cout<<x<<" "<<y<<" "<<value;
    }
};

bool compare(const point & p1,const point & p2){
    if(p2.y>p1.y){
        return false;
    }else{
        if(p2.value>p1.value){
            return false;
        }
        return true;
    }
}
vector <point> s;

int main(){

    point p1[5];
    p1[0]={0,0,1};
    p1[1]={0,1,3};
    p1[2]={0,2,4};
    p1[3]={3,0,5};
    p1[4]={4,0,2};
    s.push_back({0,0,1});
    s.push_back({0,1,3});
    s.push_back({0,2,4});
    s.push_back({3,0,5});
    s.push_back({4,0,2});

    sort(p1,p1+5,compare);

    for(int i=0;i<5;i++){
        p1[i].toString();
        cout<<"\n";
    }

    sort(s.begin(),s.end(),compare);
    for(int i=0;i<s.size();i++){
        s[i].toString();
        cout<<"\n";
    }
    return 0;
}