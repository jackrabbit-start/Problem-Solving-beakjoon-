#include <bits/stdc++.h>
using namespace std;
int N, K;

int arr[1003][1003];


int probabilit(int times, int choose){
    if(times == N){
        return choose == K;
    }
    if(arr[times][choose] != -1) return arr[times][choose];
    arr[times][choose] = (probabilit(times+1, choose) + probabilit(times+1, choose+1))%10007;
    return arr[times][choose];
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0 ; i <= 1001; i++){
        memset(arr[i],-1,sizeof(int)*1002);
    }
    cout << probabilit(0,0);
    return 0;
}
//https://shoark7.github.io/programming/algorithm/3-ways-to-get-binomial-coefficients