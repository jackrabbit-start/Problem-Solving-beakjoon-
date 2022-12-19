#include <bits/stdc++.h>
using namespace std;

int arr[105][105] = {0,};
int data_input[105][2] = {0,};
int paper_N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> paper_N;
    for(int i = 0; i < paper_N; i++){
        int x_pos, y_pos;
        cin >> x_pos >> y_pos;
        for(int j = 0 ; j < 10; j++){
            for(int k = 0; k < 10 ; k++){
                arr[x_pos+j][y_pos+k] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < 100 ;i++){
        for(int j = 0 ; j < 100 ;j++){
            if(arr[i][j] == 1) ans++;
        }
    }
    cout << ans;

    return 0;
}// 6분 22초
