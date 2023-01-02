#include <bits/stdc++.h>
using namespace std;
int N;
char arr[100][100];
int divide_conqurence(int cnt, int x_pos, int y_pos){
    if(cnt== 1) {cout << arr[x_pos][y_pos]; return 0;}
    for(int i = 0; i < cnt ; i++){
        for(int j = 0 ; j < cnt ; j++){
            if(arr[x_pos][y_pos] != arr[x_pos+i][y_pos+j]){
                cout << "(";
                divide_conqurence(cnt/2 , x_pos , y_pos);
                divide_conqurence(cnt/2 , x_pos  , y_pos+ cnt/2);
                divide_conqurence(cnt/2 , x_pos+ cnt/2 , y_pos );
                divide_conqurence(cnt/2 , x_pos+ cnt/2 , y_pos+ cnt/2);
                cout << ")";
                return 0;
            }
        }
    }
    cout << arr[x_pos][y_pos];
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin >> arr[i][j];
        }
    }
    divide_conqurence(N, 0,0);
    return 0;
}