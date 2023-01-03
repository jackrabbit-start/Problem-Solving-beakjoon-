#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int arr[150][150];
int arr2[150][150];
int ans[150][150];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> arr[i][j];
        }
    }
    cin >> M >> K;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < K ; j++){
            cin >> arr2[i][j];
        }
    }
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < K ; j++){
            for(int k = 0 ; k < M ; k++){
                ans[i][j] += arr[i][k]*arr2[k][j];
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < K ; j++){
            cout << ans[i][j] << " ";
        }
        cout <<"\n";
    }
    

    return 0;
}