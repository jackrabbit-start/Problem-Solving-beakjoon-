#include <bits/stdc++.h>
using namespace std;
int arr[5000][5000];
int answer[3];
int N;

int divide_conquer(int cnt, int x_pos, int y_pos){
    if(cnt == 1) {
        answer[arr[x_pos][y_pos]+1]++;
        return 0;
    }
    for(int i = 0 ; i < cnt ; i++){
        for(int j = 0 ; j < cnt ; j++){
            if(arr[x_pos][y_pos] != arr[x_pos+i][y_pos+j]){
                divide_conquer(cnt/3 , x_pos , y_pos);
                divide_conquer(cnt/3 , x_pos + cnt/3 , y_pos);
                divide_conquer(cnt/3 , x_pos + (cnt/3*2) , y_pos);
                divide_conquer(cnt/3 , x_pos , y_pos + cnt/3);
                divide_conquer(cnt/3 , x_pos , y_pos + (cnt/3*2));
                divide_conquer(cnt/3 , x_pos+cnt/3 , y_pos+cnt/3);
                divide_conquer(cnt/3 , x_pos+cnt/3 , y_pos + (cnt/3*2));
                divide_conquer(cnt/3 , x_pos+ (cnt/3*2) , y_pos + cnt/3);
                divide_conquer(cnt/3 , x_pos+(cnt/3*2) , y_pos+(cnt/3*2));
                return 0;
            }
        }
    }
    answer[arr[x_pos][y_pos]+1]++;
    return 0;

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> arr[i][j];
        }
    }
    divide_conquer(N,1,1);
    for(int i = 0 ; i < 3; i++){
        cout << answer[i] << "\n";
    }

    

    return 0;
    
}