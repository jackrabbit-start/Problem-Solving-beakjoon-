#include <bits/stdc++.h>
using namespace std;

int M, N;
int arr[20005] = {0,};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> M >> N;
    arr[1] = 1; // 1은 소수가 아니에용
    for(int i = 2; i <= N; i++){
        if(arr[i] == 0){
            int j = 2;
            while(j*i <= N){
                arr[i*j] = 1;
                j++;
            }
        }
    }
    int ans = 0;
    int min_ans  = 0;;
    for(int i = M; i <= N; i++){
        if(arr[i] == 0){
            ans += i;
            if(min_ans == 0) min_ans = i;
        }
    }
    if(ans == 0) cout <<"-1";
    else    cout << ans << "\n" << min_ans <<"\n";

    return 0;
}