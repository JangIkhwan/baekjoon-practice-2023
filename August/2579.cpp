/*

23-08-14

22:05 ~ 22:28

b[n] = max(a[n] + b[n - 2], a[n] + b[n-3], a[n] + a[n - 1] + b[n - 3])
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int dp[MAX];
int score[MAX];

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &score[i]);
	}
	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = score[1] + score[2]; //
	for (int i = 3; i <= N; i++) {
		int& cur = dp[i];
		cur = score[i] + dp[i - 2];
		cur = max(cur, score[i] + dp[i - 3]);
		cur = max(cur, score[i] + score[i - 1] + dp[i - 3]);
	}
	printf("%d", dp[N]);
	return 0;
}