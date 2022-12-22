#include <bits/stdc++.h>
using namespace std;


int K;
int arr[7];
int arr2[6];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> K;
    int w = 0;
    int h = 0;
    int ans = 0;
    for(int i = 0; i < 6; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = b;
        arr2[i] = a;
        if(a == 1) w += b;
        if(a == 3) h += b;
    }
    int left = 0;
    int right = 3;
    for(int i = 0 ; i <= 6; i++){
        if(arr2[left%6] == arr2[(left+2)%6] && arr2[right%6] == arr2[(right-2)%6]){
            ans = arr[(left+1)%6]*arr[(right-1)%6];
            break;
        }
        left++;
        right++;
    }
    cout << (w*h - ans)*K;
    return 0;
}