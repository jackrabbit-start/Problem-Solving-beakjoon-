#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


int arr[50] = {0,};

int main(){
    for(int i = 1 ; i <= 28; i++){
        int a;
        scanf("%d", &a);
        arr[a] = 1;
    }
    for(int i = 1 ; i <= 30; i++){
        if(arr[i] == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}