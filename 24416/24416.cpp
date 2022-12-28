#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100];
int fibo(int num){
    if(arr[num] != 0) return arr[num];
    return arr[num] = fibo(num-1) + fibo(num-2);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    arr[1] = 1;
    arr[2] = 1;
    int tmp = 0;
    if(N ==1 || N == 2) tmp = 0;
    else tmp = N-2;
    cout << fibo(N) << " " << tmp;

    return 0;
}