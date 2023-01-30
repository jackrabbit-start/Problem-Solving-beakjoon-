#include <bits/stdc++.h>
using namespace std;

int N;
int arr[30][30];
int DP[25][1<<21];


int dfs(int num, int visited){
    if(num == N) return 0;
    if(DP[num][visited] != -1) return DP[num][visited];

    DP[num][visited] = INT_MAX;
    for(int i = 0 ; i < N ; i++){
        if((visited & (1<<i)) != 0) continue;
        else{
            DP[num][visited] = min(DP[num][visited] , dfs(num+1,visited|(1<<i)) + arr[num][i]);
        }
    }
    return DP[num][visited];
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    memset(DP , -1 , sizeof(DP));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(0,0);
    return 0;
}