#include <bits/stdc++.h>
using namespace std;
#define MAXnum 300000

int tCase;
int arr[300006] = {0,};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    arr[1] = 1;
    for(int i = 2; i <= MAXnum;i++){
        int j = 2;
        while(i*j<= MAXnum){
            arr[i*j] = 1;

            j++;
        }
    }

    cin >> tCase;
    while(tCase != 0){
        int answer = 0;
        for(int i = tCase ; i < tCase*2; i++){
            if(arr[i+1] == 0){
                answer++;
            }
        }
        cout << answer << "\n";
        cin >> tCase;
    }

    return 0;
}