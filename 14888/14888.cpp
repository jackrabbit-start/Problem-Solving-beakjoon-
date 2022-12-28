#include <bits/stdc++.h>
using namespace std;
long long int N;
long long int arr[100];
long long int arr2[100];
long long int max_n = -1000000009;
long long int min_n = 1000000009;
long long int calc;
long long int r_cal[4] = {1,0,3,2};
void cal_num(long long int a, long long int num){
    switch(a){
                case 0:
                calc = calc + arr[num];
                break;
                case 1:
                calc = calc - arr[num];
                break;
                case 2:
                calc = calc * arr[num];
                break;
                case 3:
                calc = calc / arr[num];
                break;
            }
            return;

}

void dfs(int cnt){
    if(cnt == N-1){
        if(calc > max_n) max_n = calc;
        if(calc < min_n) min_n = calc;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(arr2[i] > 0){
            arr2[i]--;
            int tmp = calc;
            cal_num(i,cnt+1);
            dfs(cnt+1);
            calc = tmp;
            arr2[i]++;
        }
    }
}



int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < 4; i++){
        cin >> arr2[i];
    }
    calc = arr[0];
    dfs(0);
    cout << max_n << "\n" << min_n;


    return 0;
}