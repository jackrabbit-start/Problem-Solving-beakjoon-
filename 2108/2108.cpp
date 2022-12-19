#include <bits/stdc++.h>
using namespace std;


int N;
vector<int> v;

double avg;
int mid_value;
int range;

int arr[10000] = {0,};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int input;
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        avg += double(input);
        arr[input+4000]++;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    
    mid_value = v[N/2]; // 중앙값
    range = v[N-1]-v[0]; //범위
    cout << (int)(round(avg/N)) << "\n" << mid_value << "\n"; 
    // 평균시 반올림 할때 사용가능한 방법 1. round함수사용(math.h include) 2. 0.5를 더해서 int 형으로 출력하는 야매방법 3. printf로 %.0f 로 출력하는방법
    // 2번방법은 0.5를 더해주기만해도 반올림을 한 것과 같게 사용할 수있다 4.4->4.9 4.7->5.2 등 이후 int로 내림 시키면 반올림과 같음
    // ++ round를 그냥사용하면 -0 이 출력되는 경우가 있다.
    // 이때를 없애기 위해 그냥 int형으로 바꾸어 주었다.
    auto iter = max_element(arr, arr+8001);
    if(*iter != *max_element(iter+1, arr+8001)){//2번째 최빈값 찾기 최대값 찾아주는 max_element
        cout << (iter-arr)-4000 << "\n" << range;
    }
    else{
        iter = max_element(iter+1, arr+8001);
        cout << (iter-arr)-4000 << "\n" << range;
    }


    return 0;
}