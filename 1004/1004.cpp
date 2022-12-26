#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int x_1, x_2, y_1, y_2;
int x_pos, y_pos, r;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        int answer = 0;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cin >> N;
        for(int i = 0 ; i < N ; i++){
            cin >> x_pos >> y_pos >> r;
            if((r*r > (x_pos-x_1)*(x_pos-x_1)+ (y_pos-y_1)*(y_pos-y_1)) || (r*r > (x_pos-x_2)*(x_pos-x_2)+ (y_pos-y_2)*(y_pos-y_2))){
                answer++;
            }
            if((r*r > (x_pos-x_1)*(x_pos-x_1)+ (y_pos-y_1)*(y_pos-y_1)) && (r*r > (x_pos-x_2)*(x_pos-x_2)+ (y_pos-y_2)*(y_pos-y_2))){
                answer--;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}