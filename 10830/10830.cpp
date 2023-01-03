#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, B;
ll arr[10][10];
ll ans[10][10];
ll answer[10][10];
ll tmp;
void divide_conquer(long long int n){
    if(n == 1 || n == 0){
        return;
    }
    divide_conquer(n/2);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j ++){
            ans[i][j] = answer[i][j];
        }
    }
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j++){
            tmp = 0;
            for(int k = 0 ; k < N ; k++){
                tmp += (ans[i][k] * ans[k][j])%1000;
                tmp %= 1000;
            }
            answer[i][j] = tmp%1000;
            tmp = 0;
        }
    }
    if(n % 2 == 1){
        for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j ++){
            ans[i][j] = answer[i][j];
        }
    }
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < N ; j++){
                tmp = 0;
                for(int k = 0 ; k < N ; k++){
                    tmp += (ans[i][k] * arr[k][j])%1000;
                    tmp %= 1000;
                }
                answer[i][j] = tmp%1000;
            }
        }
    }
    
    return;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> B;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> arr[i][j];
            answer[i][j] = arr[i][j];
        }
    }
    divide_conquer(B);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << answer[i][j]%1000 << " ";
        }
        cout << "\n";
    }
    

    return 0;
}