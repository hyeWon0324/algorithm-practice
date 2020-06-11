//https://www.acmicpc.net/problem/16234 
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std; 

struct POSI {
    int y, x; 
}; 
int n, l, r; 
int map[50][50]; 

void create_area(int sy, int sx, int status[][50], 
                int index, int& count, int& sum ) {
    int visited[50][50] = {0, }; 

    const int dy[] = {0,0,-1,+1};  //4가지 방향돌기 위한 좌표 
    const int dx[] = {-1,+1,0,0,}; //4가지 방향돌기 위한 좌표 

    queue<POSI> q; 
    POSI head; 
    head.y = sy; 
    head.x = sx; 
    visited[sy][sx] = 1; 
    q.push(head); 

    while(!q.empty()){
        POSI cur = q.front(); 
        q.pop(); 

        status[cur.y][cur.x] = index; 
        ++count; 
        sum += map[cur.y][cur.x]; 

        for (int dir = 0; dir < 4; ++dir){ //네가지 방향 탐색 
            POSI next; 
            next.y = cur.y + dy[dir];      
            next.x = cur.x + dx[dir]; 

            if (next.y < 0 || next.y >= n || next.x < 0|| next.x >= n){
                continue; //외곽으로 나갔을 때 
            }
            int delta = abs(map[cur.y][cur.x] - map[next.y][next.x]); 
            if (visited[next.y][next.x] == 0 && l <= delta && delta <= r) {
                visited[next.y][next.x] = 1; 
                q.push(next); 
            }
        }
    }
}

int main(){
    //
    scanf("%d %d %d", &n, &l, &r); //n 은 땅의 크기.  두 나라의 인구 차이가 L명 이상, R명 이하 
    //map 입력 받기 
    for (int y = 0; y < n; ++y) {
        for (int x =0; x <n; ++x){
            scanf("%d", &map[y][x]); 
        }
    }
    int ret = 0; 
    bool is_update = true; 
    while(is_update){
        is_update = false;    // 업데이트가 일어나지 않았다. 

        int status[50][50] = {0,}; //2차원 배열 
        int area_index = 0; 
        int count[2501] = {0,}; 
        int sum[2501] = {0,}; 

        for (int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x){
                if (status[y][x] == 0){
                    ++area_index;       //다음 공간 
                    create_area(y, x, status, area_index, count[area_index], sum[area_index]); 
                
                }
            }
        }

        for (int y =0; y < n; ++y){
            for (int x=0; x < n; ++x){
                int index = status[y][x]; 
                int avg = sum[index] / count[index]; 

                if (map[y][x] != avg){ //업데이트가 일어난 경우
                    map[y][x] = avg; 
                    is_update = true; 
                }
            }
        }
        if (is_update){
            ++ret; 
        }
    }
    printf("%d\n", ret);
    return 0; 
}