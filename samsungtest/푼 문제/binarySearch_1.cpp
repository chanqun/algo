#include <iostream>

using namespace std;

int num[10] = {1,3,5,7,8,10,11,14,15,17};

int binarySearch(int first, int last, int target){
    int mid = (first + last)/2;
    if(first>last) return 0;

    if(num[mid]==target) return 1;
    else if(num[mid]>target) binarySearch(first, mid-1, target);
    else binarySearch(mid+1, last, target);
}

int main(){

    int first = 0;
    int last  = 9;

    int find_number;
    cin>>find_number;
    
    int solution = binarySearch(first, last, find_number);
    cout<<solution;
    
    return 0;
}