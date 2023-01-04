#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll T;
ll arr[100010];
ll answer;


ll divide_conquer(ll left, ll right){
    //cout << "(" << left << " " << right << " " << answer << ")";
    ll mid_max = max(arr[(right+left)/2],arr[(right+left)/2+1]);
    ll tmp = 0;
    if(left+1 == right){
        answer = max(answer, min(arr[left], arr[right]) * 2);
        answer = max(answer, arr[left]);
        answer = max(answer, arr[right]);
        return answer;
    }
    if(left == right){
        answer = max(answer, arr[left]);
        return answer;
    }
    ll left_t = (right+left)/2;
    ll right_t = (right+left)/2+1;
    ll total_min = min(arr[(right+left)/2], arr[(right+left)/2+1]);
    mid_max = max(mid_max, total_min*(right_t - left_t + 1));
    while(left_t > left  || right_t < right){
        if(left_t <= left || ((right_t < right)&&(arr[left_t-1] <= arr[right_t+1]))){
            total_min = min(arr[right_t+1], total_min);
            right_t++;
        }
        else{
            total_min = min(arr[left_t-1], total_min);
            left_t--;
        }
        mid_max = max(mid_max, total_min*(right_t - left_t + 1));
    }
    answer = max(max(mid_max, divide_conquer(left, (right+left)/2)),divide_conquer((right+left)/2+1, right));
    return answer;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        answer = 0;
        cin >> T;
        if(T == 0) break;
        for(ll i = 1 ; i <= T ; i++){
            cin >> arr[i];
        }
        arr[0] = -1;
        arr[T+1] = -1;
        divide_conquer(1, T);
        cout << answer << "\n";
    }

    return 0;
}