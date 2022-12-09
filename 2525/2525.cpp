#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int A, B, C;

int main(){
    scanf("%d %d",&A, &B);
    scanf("%d",&C);
    B += C;
    if((B % 60) != B){
        A = A + B/60;
        B = B % 60;
    }
    A = A % 24;
    printf("%d %d\n", A, B);
    return 0;
}