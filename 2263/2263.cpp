#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100005];
int arr2[100005];
vector<int> dq;
int solve(int arr1_left, int arr1_right, int arr2_left, int arr2_right){
    if(arr1_left > arr1_right || arr2_left > arr2_right) return 0;
    if(arr1_left == arr1_right && arr2_left == arr2_right){
        dq.push_back(arr2[arr2_left]);
        return 0;
    }
    int n1_x = arr1_left;
    while(arr[n1_x] != arr2[arr2_right]){
        n1_x++;
    }
    dq.push_back(arr2[arr2_right]);

    if(n1_x == arr1_left){
        solve(n1_x + 1, arr1_right, arr2_left, arr2_right-1);
    }
    else{
        solve(arr1_left, n1_x-1, arr2_left, arr2_left + ( n1_x - arr1_left - 1 ));
        solve(n1_x + 1, arr1_right, arr2_left + ( n1_x - arr1_left), arr2_right-1);
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= N ; i++){
        cin >> arr2[i];
    }
    solve(1,N,1,N);
    for(int i = 0 ; i < dq.size(); i++){
        cout << dq[i] << " ";
    }
    return 0;
}