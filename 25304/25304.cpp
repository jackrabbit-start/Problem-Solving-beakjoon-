#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int X;
int N;
int a, b;
int total;

int main(){
    total = 0;
    scanf("%d", &X);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d", &a, &b);
        total += (a*b);
    }

    if(total == X) printf("Yes\n");
    else printf("No\n");
    return 0;
}