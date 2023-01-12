#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int V, E;
ll a, b, c;
ll arr[500][500];
ll ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> V >> E;
    fill(&arr[0][0], &arr[450][450], INT_MAX);
    ans = INT_MAX;
    for(int i = 0 ; i < E; i++){
        cin >> a >> b >> c;
        arr[a][b] = min(c, arr[a][b]);
    }
    for(int i = 1; i <= 450; i++){
        arr[i][i] = 0;
    }
    for(int i = 1; i <= V ; i++){
        for(int j = 1; j<= V; j++){
            for(int k = 1; k <= V; k++){
                arr[j][k] = min(arr[j][k] , arr[j][i] + arr[i][k]);
            }
        }
    }
    for(int i = 1; i <= V ; i++){
        int start = i;
        for(int j = 1; j<= V; j++){
            if(i != j){
                ans = min(ans, arr[i][j] + arr[j][i]);
            }
        }
    }
    if(ans >= INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}