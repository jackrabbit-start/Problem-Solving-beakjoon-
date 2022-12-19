#include <bits/stdc++.h>
using namespace std;
#define MAXnum 15000

int tCase;
int N;
int arr[20001] = {0,};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    arr[1] = 1;
    for(int i = 2; i < MAXnum; i++){
        int j = 2;
        while((i*j) < MAXnum){
            arr[i*j] = 1;
            j++;
        }
    }

    cin >> tCase;
    
    for(int i = 0 ; i < tCase; i++){
        cin >> N;
        int dif = 999999;
        for(int j = 2; j < N; j++){
            if(arr[N-j] == 0 &&arr[j] == 0){
                if(dif > abs((2*j)-N)) dif = abs((2*j)-N);
            }
        }
        int ans = (N-dif)/2;
        cout << ans << " " << N-ans << "\n";
    }

    return 0;
} // 시간 14:37 틀린횟수 3