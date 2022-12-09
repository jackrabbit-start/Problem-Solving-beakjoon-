#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int T, k, n;

int arr[20][20]= {0,};

int main(){
    for(int i = 0 ; i < 20; i++){
        arr[0][i] = i;
    }
    for(int i = 1 ; i < 20; i++){
        for(int j = 1 ; j < 20; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    scanf("%d",&T);
    for(int i = 0 ; i < T; i++){
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", arr[k][n]);
        
    }
    return 0;
}