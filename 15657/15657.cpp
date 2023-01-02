#include <bits/stdc++.h>
using namespace std;
int N;
int M;
vector<int> arr;
vector<int> answer;

void backtracking(int cnt){
    if(cnt == M){ 
        for(int i = 0 ; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(cnt == 0){
        for(int i = 0 ; i < N ; i++){
            answer.push_back(arr[i]);
            backtracking(cnt+1);
            answer.pop_back();
        }
    }
    else{
        for(int i = 0 ; i < N ; i++){
            if(!answer.empty() && answer.back() <= arr[i]){
            answer.push_back(arr[i]);
            backtracking(cnt+1);
            answer.pop_back();
            }
        }
    }
    return;

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    int input;
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    backtracking(0);

    return 0;
    
}