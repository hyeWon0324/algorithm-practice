#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int R, C, M; // M : 상어의 갯수
const int MAX = 105;
int map[MAX][MAX];
int temp_map[MAX][MAX] = { 0, };
int answer = 0;
struct myData {
	int r;
	int c;
	int s;
	int d;
	int z;
	bool alive;
};
myData sharks[MAX * MAX];
void catch_shark(int x) {
	for (int i = 1; i <= C; i++) {
		if (map[i][x] != 0) {
			// 가장 가까운 상어
			int shark_num = map[i][x];
			sharks[shark_num].alive = false;
			map[i][x] = 0; // 먹는다
			answer += sharks[shark_num].z;
			break;
		}
	}
}
void move_shark(myData shark, int shark_num) {
	int x = shark.r;
	int y = shark.c;
	int speed = shark.s;
	int dir = shark.d;
	int size = shark.z;
	map[x][y] = 0;
	if (dir == 3 || dir == 4) {
		speed = speed % (C * 2 - 2);
	}
	else {
		speed = speed % (R * 2 - 2);
	}
	
	for (int i = 0; i < speed; i++) {
		if (dir == 1) {
			x -= 1;
			if (x == 0) {
				x = 2;
				dir = 2;
			}
		}
		else if (dir == 2) {
			x += 1;
			if (x == R + 1) {
				x = R - 1;
				dir = 1;
			}
		}
		else if (dir == 3) {
			y += 1;
			if (y == C + 1) {
				y = C - 1;
				dir = 4;
			}
		}
		else if (dir == 4) {
			y -= 1;
			if (y == 0) {
				y = 2;
				dir = 3;
			}
		}
	}
	if (temp_map[x][y] != 0) { // 이미 상어가 있다면
		int shark2_num = temp_map[x][y]; // 이전 상어 정보 get
		if (size > sharks[shark2_num].z) { // 내가 더 크면
			sharks[shark2_num].alive = false; // 먹고
			sharks[shark_num].r = x;
			sharks[shark_num].c = y;
			sharks[shark_num].d = dir;
			temp_map[x][y] = shark_num;
		}
		else { // 상대방이 더 크면
			sharks[shark_num].alive = false; // 내가 죽는다.
		}
	}
	else { // 상어가 없다면
		sharks[shark_num].r = x;
		sharks[shark_num].c = y;
		sharks[shark_num].d = dir;
		temp_map[x][y] = shark_num;
	}
}
int main() {
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) { // sharks 정보를 입력받는다.
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i] = { r, c, s, d, z, true };
		map[r][c] = i; // map[r][c]에는 상어의 번호가 기록된다.
	}
	for (int x = 1; x <= C; x++) { // 사람은 계속 오른쪽으로 이동한다.
		// 낚시왕이 있는 열에 있는 상어중에서 땅과 제일 가까운 상어를 잡는다.
		catch_shark(x);
		// 상어가 이동한다.
		for (int i = 1; i <= M; i++) {
			if (sharks[i].alive == true) { // 상어가 살아있으면
				move_shark(sharks[i], i);
			}
		}
		
		for (int j = 1; j <= R; j++) { 
			for (int k = 1; k <= C; k++) {
				map[j][k] = temp_map[j][k];
				temp_map[j][k] = 0;
			}
		}
	}
	cout << answer;
	return 0;
}
