#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10005] = {0,};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int input;
    for(int i = 0 ; i < N; i++){
        cin >> input;
        arr[input]++;
    }
    for(int i = 1 ; i <= 10000 ; i++){
        if(arr[i] != 0){
            for(int j = 0 ; j < arr[i]; j++){
                cout << i << "\n";
            }
        }
        
    }
    

    return 0;
} // 약 2분가량 sort를 쓰는 것이 아닌 범위가 10000까지 이므로, 10000까지의 배열을 직접 만들어 풀이한다.