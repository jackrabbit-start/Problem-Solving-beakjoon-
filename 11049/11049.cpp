#include <bits/stdc++.h>
using namespace std;
int N;
int arr[505][2];
int DP[505][505]= {0,};

int solve(int a, int b){
    if(a == b) return DP[a][b] = 0;
    if(DP[a][b] != -1) return DP[a][b];
    if(a+1 == b){
        return DP[a][b] = arr[a][0] * arr[a][1] * arr[b][1];
    }
    int tmp = INT32_MAX;
    for(int i = a; i < b; i++){
        tmp = min(tmp ,(solve(a,i) + solve(i+1,b) + (arr[a][0] * arr[i][1] * arr[b][1])));
    }
    DP[a][b] = tmp;
    return DP[a][b];
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i][0] >> arr[i][1];
        for(int j = 1 ; j <= N ; j++){
            DP[i][j] = -1;
        }
    }

    cout << solve(1,N);
    return 0;
}