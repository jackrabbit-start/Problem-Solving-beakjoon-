#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N, M;
ll A, B, W;
ll arr[200][200];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    fill(&arr[0][0], &arr[190][190], INT_MAX);
    cin >> N;
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> A >> B >> W;
        arr[A][B] = min(W, arr[A][B]); // 같은 경로라도 최소값 걸러주기
    }
    for(int i = 1; i <= N ; i++){
        arr[i][i] = 0;
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            for(int k = 1; k <= N; k++){
                arr[j][k] = min(arr[j][k] , arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            if(arr[i][j] == INT_MAX) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}