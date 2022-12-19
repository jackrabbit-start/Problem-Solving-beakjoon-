#include <bits/stdc++.h>
using namespace std;


int arr[11][11] = {0,};
int maximum = -1;
int ans_x, ans_y;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int input;
    for(int i = 1 ;i <= 9 ; i++){
        for(int j = 1 ; j <= 9; j++){
            cin >> input;
            if(maximum < input){
                maximum = input;
                ans_x = i;
                ans_y = j;
            }
        }
    }
    cout << maximum << "\n" << ans_x << " " << ans_y;
    return 0;
} // 3분 51초
