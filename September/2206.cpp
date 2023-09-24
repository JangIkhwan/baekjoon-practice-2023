/*
23-09-24 9:00 ~ 9:16 , 15:34 ~ 16:21
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool visitedFromStart[1001][1001];
bool visitedFromEnd[1001][1001];
int map[1001][1001];
int steps[1001][1001];

void print() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << steps[y][x];
		}
		cout << endl;
	}
}

// bfs로 바꾸는 것이 필요함
void bfs(int sy, int sx, int sstep, bool visited[1001][1001]) {
	queue<pair<int, pair<int, int>>> qu;
	qu.push({ sstep, {sy, sx} });
	while (!qu.empty()) {
		int step = qu.front().first;
		int y = qu.front().second.first;
		int x = qu.front().second.second;
		qu.pop();
		if (y > N || y < 1 || x > M || x < 1) continue;
		if (!visited[y][x]) {
			visited[y][x] = true;
			steps[y][x] += step;
			if (map[y][x] != 1) {
				qu.push({ step + 1, { y + 1, x } });
				qu.push({ step + 1, { y - 1, x } });
				qu.push({ step + 1, { y, x + 1 } });
				qu.push({ step + 1, { y, x - 1 } });
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	int shortestDist = N * M + 1;
	bfs(1, 1, 1, visitedFromStart);
	if (steps[N][M] > 0) {
		shortestDist = steps[N][M];
	}
	bfs(N, M, 1, visitedFromEnd);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (map[y][x] == 1 && visitedFromStart[y][x] && visitedFromEnd[y][x]) {
				if (steps[y][x] - 1 < shortestDist) {
					shortestDist = steps[y][x] - 1;
				}
			}
		}
	}
	if (shortestDist == N * M + 1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", shortestDist);
	}	
	return 0;
}

