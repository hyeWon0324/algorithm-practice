//https://www.acmicpc.net/problem/16236
//N*N 크기의 공간 // 물고기 M 마리// 아기 상어 1 마리 
//한칸에 한 마리 
// 아기상어 크기 == 2 // 1초에 상하좌우 인접한 한칸 이동 
// babyShark_size > fish_size  :: 먹는다 
// babyShark_size == fish_size :: 지나갈 수 있다 
// 먹을 수 있는 물고기 없으면 도움 요청 : 종료 
// fish.size() == 1 : eat 
// fish.size() > 1 : priority(상 > 좌)
// eat_size  == babyshark_size : babyshark_size++ 
// 이동 -> time++ 
// 먹으면서 동시 이동 
//0: 빈 칸
//1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
//9: 아기 상어의 위치
#include <stdio.h>
#include <queue>
using namespace std; 

struct SHARK{
    int y, x, time; //위치 좌표와 시간 
};

int n; 
int map[20][20]; // 공간의 크기 N(2 ≤ N ≤ 20)

int shark_size, shark_eat; //상어 크기 //상어가 먹은 개수 
SHARK shark; 

const int dy[] = {0, 0, -1, +1}; 
const int dx[] = {-1, +1, 0, 0}; 

int main(){
    scanf("%d", &n);   //공간의 크기 

    //초기화 
    for (int y=0; y < n; ++y){
        for (int x =0; x< n; ++x){
            scanf("%d", &map[y][x]);
            if (map[y][x] ==9){     // 9는 아기 상어의 위치 
                shark.y = y, shark.x, shark.time = 0; 
                shark_size = 2, shark_eat = 0; 
                map[y][x] = 0; 
            }
        }
    }

    bool is_update = true; 
    while (is_update){ //상어가 먹은 물고기가 있는지 없는지 
        is_update = false; 
        
        bool visited[20][20] = { false, }; //방문한 곳을 기록.// false 로 초기화 
        queue<SHARK> q;                    // 상어 큐 만들기 
        visited[shark.y][shark.x] = true;  // 방문했던 맵에 현재 위치 true로 만든다 
        q.push(shark);                     // 초기 위치를 큐에 넣는것

        SHARK candi;                       //먹을 물고기 하나 
        candi.y = 20, candi.time = -1;      //y는 가장 큰 값으로 초기화 
        while (!q.empty()) {                //먹을 수 있는지 없는지 확인하기 위해 큐 순회하기 
            SHARK cur = q.front();
            q.pop();

            if (candi.time != -1 && candi.time < cur.time ){ //갱신이됨 
                break;              //가장 가까운 것을 이미 먹었다는 뜻 
            } 

            //현재 위치에 아기 상어의 크기보다 작은 상어가 있을때 
            if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0){ 
                is_update = true; //갱신
                if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)){
                    candi = cur; 
                }
            }
            for (int dir = 0; dir < 4 ; ++dir){
                SHARK next; 
                next.y = cur.y + dy[dir]; 
                next.x = cur.y + dx[dir]; 
                next.time = cur.time + 1; 

                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n){
                    continue; 
                }
                if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]){
                    // 안 가 봤고 상어의 크기보다 작거나 같을 때 그 위치로 이동 

                    visited[next.y][next.x] = true; 
                    q.push(next); 
                }
            }
        }
        if (is_update) { // 물고기를 먹을 수 있다 
            shark = candi;                  //
            ++shark_eat;                    //먹는다 
            if (shark_eat == shark_size){   //자기 사이즈만큼 먹었으므로 사이즈 키우기 
                ++ shark_size;              //크기 키우기 
                shark_eat = 0;              //다시 초기화 
            }
            map[shark.y][shark.x] = 0;      //빈자리 
        }
    }
    printf("%d\n", shark.time); 
    return 0; 
}