#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int arr[2010][2010];
int DP[2][2010][2010];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> K;
    char input;
    int input2;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M ; j++){
            cin >> input;
            if(input == 'B') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
            if(arr[i][j] == ((i+j)%2))DP[0][i][j] = 1;
            else DP[1][i][j] = 1;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M ; j++){
            DP[0][i][j] = DP[0][i-1][j] + DP[0][i][j-1] - DP[0][i-1][j-1] + DP[0][i][j];
            DP[1][i][j] = DP[1][i-1][j] + DP[1][i][j-1] - DP[1][i-1][j-1] + DP[1][i][j];
        }
    }
    int answer = 987564321;
    for(int i = K ; i <= N; i++){
        for(int j = K; j <= M ; j++){
            answer = min(DP[0][i][j]-DP[0][i-K][j] - DP[0][i][j-K] + DP[0][i-K][j-K], answer);
            answer = min(DP[1][i][j]-DP[1][i-K][j] - DP[1][i][j-K] + DP[1][i-K][j-K], answer);
        }
    }
    cout << answer;
    return 0;
}