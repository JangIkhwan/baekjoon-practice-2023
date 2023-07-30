/*
23-07-30 20:48 ~ 21:06

1차 시도 : 성공

bfs를 이용해서 섬을 하나씩 찾아가면 됨
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
int dy[] = { 0, 1, 1, 1, 0, - 1, -1, -1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void bfs(int y, int x, int w, int h) {
	queue<pair<int, int>> qu;
	qu.push({ y, x });
	visited[y][x] = true;
	while (!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();
		for (int direct = 0; direct < 8; direct++) {
			int nextY = y + dy[direct];
			int nextX = x + dx[direct];
			if (nextY < 1 || nextY > h || nextX < 1 || nextX > w) continue;
			if (map[nextY][nextX] == 1 && !visited[nextY][nextX]) { //
				qu.push({ nextY, nextX });
				visited[nextY][nextX] = true; // 
			}
		}
	}
}

int main(void) {
	int w, h;
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				scanf("%d", &map[y][x]);
			}
		}
		memset(visited, 0, sizeof(visited)); //
		int islandCount = 0;
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				if (map[y][x] == 1 && !visited[y][x]) {
					bfs(y, x, w, h);
					islandCount++;
				}
			}
		}
		printf("%d\n", islandCount);
	}
	return 0;
}

