#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
typedef unsigned long long int ull;
ull N;
map<ull, ull> maping;
ull fibo(ull n) {
	if (n == 2) return 1;
	if (n == 1) return 1;
	if (n == 0) return 0;
    if(maping.count(n) > 0) return maping[n]; // maping을 활용하여 숫자가 엄청 크더라도 메모이제이션이 가능하다. count 함수를 이용해 정보가 존재하는지 확인 가능
    // map.count() 함수는 해당 키값에 해당하는 원소들의 개수를 반환하면 된다.
    // maping 안하면 시간초과가 난다.
    // *행렬으로 푸는방식*
    // 피보나치의 점화식을 행렬의 곱셈으로 표현 가능
    // https://cocoon1787.tistory.com/349 참고
	if (n % 2 == 1) {
		ull tmp1 = fibo(n / 2);
		ull tmp2 = fibo(n / 2 + 1);
		tmp1 = (tmp1*tmp1) % MOD;
		tmp2 = (tmp2*tmp2) % MOD;
		return maping[n] = (tmp1 + tmp2) % MOD;
	}
	else {
		ull tmp1 = fibo(n / 2 + 1);
		ull tmp2 = fibo(n / 2 - 1);
		tmp1 = (tmp1*tmp1) % MOD;
		tmp2 = (tmp2*tmp2) % MOD;
		if (tmp1 >= tmp2) return maping[n] = (tmp1 - tmp2)%MOD;
		else return maping[n] = ((tmp1 - tmp2)+MOD)%MOD;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cout << fibo(N)%MOD;
	return 0;
}