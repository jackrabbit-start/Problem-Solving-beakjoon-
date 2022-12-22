#include <bits/stdc++.h>
using namespace std;

int arr[2][1001];
int x_pos;
int y_pos;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i = 0 ; i < 6; i++){
        int a;
        cin >> a;
        arr[i%2][a]++;
    }
    
    for(int i = 0 ; i < 1001;i++){
        if(arr[0][i] == 1) x_pos = i;
        if(arr[1][i] == 1) y_pos = i;
    }
    cout << x_pos << " " << y_pos;
    return 0;
}