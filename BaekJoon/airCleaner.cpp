// 미세먼지 안녕 

#include <stdio.h>
#include <iostream> 

using namespace std; 

int row,column,t;     //가로길이, 세로길이, 시간 
int map[2][50][50];   // [0] [1]    
int up_y, up_x, down_y, down_x; //공기청정기 윗쪽 좌표, 아랫쪽 좌표 

const int dy[] = {-1,+1,0,0}; //네 방향 탐색을 위해 
const int dx[] = {0,0,-1,+1};

void spread(int cur){
    int next = (cur +1) % 2;  // cur 아닌 것 
    for (int y =0; y < row; ++y){
        for (int x =0; x < column; ++x){
            if (map[cur][y][x] == -1){
                map[next][y][x] = -1; 
            }else{
                map[next][y][x] = 0; 
            }
        }
    }

    for (int y =0; y < row; ++y){
        for (int x=0; x < column; ++x){
            int val = (map[cur][y][x] / 5);  /// 주변에 확산되는 공식 
            int candidate = 0;  //실제로 확산된 양 
            for (int dir = 0; dir < 4; ++dir){ // 사방향으로 돌면서 
                int ny = y + dy[dir];
                int nx = x + dx[dir]; 

                if (ny < 0 || ny >= row || nx < 0 || nx >= column){ 
                    continue;  //공간 밖으로 나간 상황 
                }
                if (map[next][ny][nx] != -1){ //위치가 공기청정기 아님 
                    map[next][ny][nx] += val; 
                    candidate += val; 
                }
            }
            if(map[next][y][x] != -1){
                map[next][y][x] += map[cur][y][x] - candidate; 
                // 그 다음 미세먼지 양은 현재 있는 양에서 퍼져야 할 
            }
        }
    }
}
void move(int cur){
    for (int y = up_y -1; y>0; --y){
        map[cur][y][0] = map[cur][y-1][0]; 
    }
    for (int x =0; x < column-1; ++x){
        map[cur][0][x] = map[cur][0][x+1]; 
    }
    for(int y=0; y < up_y; ++y){
        map[cur][y][column-1] = map[cur][y+1][column-1]; 
    }
    for(int x= column-1; x > 1; --x){
        map[cur][up_y][x] = map[cur][up_y][x-1]; 
    }

    map[cur][up_y][1] = 0; 

    for (int y = down_y + 1; y < row; ++y){ //아래 왼쪽 
        map[cur][y][0] = map[cur][y+1][0];
    }
    for (int x = 0; x < column-1; ++x){ 
        map[cur][row-1][x] = map[cur][row-1][x+1]; 
    }
    for (int y = row-1; y>down_y; --y){
        map[cur][y][column - 1] = map[cur][y-1][column-1];
    }
    for (int x = column-1; x > 1; --x){
        map[cur][down_y][x] = map[cur][down_y][x-1]; 
    }
    map[cur][down_y][1] = 0 ; 
}
int main()
{   
    up_y = -1; 
    //cin >> row >> column >> t; 
    scanf("%d %d %d", &row, &column, &t); 
    //scanf{"%d %d %d", &row, &column, &t}; // 세로 길이 , 가로 길이, 시간  
    for (int y = 0; y < row; ++y){
        for (int x = 0; x < column; ++x){
            scanf("%d", &map[0][y][x]); 
            if (map[0][y][x] == -1){ //공기청정기 
                if (up_y == -1){
                    up_y = y, up_x = x; //공기청정기 위의 좌표 
                }else{
                    down_y = y, down_x = x; //아래 좌표 
                }
            }
        }
    }
    int cur = 0; // 현재 맵 
    for (int time = 0; time < t; ++time){
        spread(cur);    //미세먼지가 확산 
        cur = (cur + 1) % 2 ; // 현재가 0 이면 map 1 에 미세먼지 이동량을 저장  
        move(cur);     //미세먼지가 이동 
    }
    int ret = 0;
    for (int y=0; y < row; ++y){
        for (int x=0; x < column; ++x){
            if (map[cur][y][x] != -1){  // 공기청정기의 위치가 아니면 
                ret += map[cur][y][x]; 
            }
        }
    }
    printf("%d\n",ret);

    return 0; 

}