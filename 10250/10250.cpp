#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int Tcase;

int H, W, N;

int main(){
    scanf("%d", &Tcase);
    for(int i = 0 ; i < Tcase ; i++){
        int ans = 0;
        scanf("%d %d %d", &H, &W, &N);
        if((N%H) == 0) {
            ans += (H*100);
            ans += N/H;
        }
        else {
            ans += (N%H) *100;
            ans += ( N / H ) + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}