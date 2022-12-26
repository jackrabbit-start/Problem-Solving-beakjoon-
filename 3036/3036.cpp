#include <bits/stdc++.h>
using namespace std;
int N;
int arr[105] = {0,};

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 1 ; i < N ; i++){
        if(arr[0] >= arr[i]){
            int tmp = gcd(arr[0], arr[i]);
            cout << arr[0]/tmp << "/" << arr[i]/tmp << "\n";
        }
        else{
            int tmp = gcd(arr[i], arr[0]);
            cout << arr[0]/tmp << "/" << arr[i]/tmp <<"\n";
        }
    }

    return 0;
}