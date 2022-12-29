#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int arr[1050][1050];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j]; 
        }
    }
    int x,y,x_1,y_1;
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y >> x_1 >> y_1;
        cout << arr[x_1][y_1] - arr[x-1][y_1] - arr[x_1][y-1] + arr[x-1][y-1] << "\n";
    }
    return 0;
}