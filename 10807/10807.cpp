#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int arr[300];
int N;
int v;
int ans;

int main(){
    ans = 0;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &v);
    for(int i = 0 ; i < N ; i++){
        if(arr[i] == v){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}