#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int arr[500005];

void merge(int* A, int p, int q, int r) {
    int i = p;
    int j = q+1;
    int t = 1;
    int tmp[500005];
    while (i <= q && j <= r) {
        if (A[i] <= A[j]){
            tmp[t++] = A[i++]; // tmp[t] <- A[i]; t++; i++;
        }
        else tmp[t++] = A[j++]; // tmp[t] <- A[j]; t++; j++;
    }
    while (i <= q){  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    }
    while (j <= r){  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    }
    i = p; t = 1;
    while (i <= r){  // 결과를 A[p..r]에 저장
        A[i] = tmp[t];
        K--;
        if(K == 0) {cout << A[i]; K = -1;} 
        i++;
        t++;
    } 
}

void merge_sort(int* A, int p , int r) { // A[p..r]을 오름차순 정렬한다.
    int q;
    if (p < r){
        q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(A, p, q);      // 전반부 정렬
        merge_sort(A, q + 1, r);  // 후반부 정렬
        merge(A, p, q, r);        // 병합
    }
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, N-1);
    if(K>0){
        cout << "-1\n";
    }
    return 0;
}