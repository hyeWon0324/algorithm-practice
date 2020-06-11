//https://www.acmicpc.net/problem/15686
#include <stdio.h>
#include <algorithm>
#include <vector> 
using namespace std;

struct POSI {
    int y, x;
};

int n, m, type, result; //N*N 크기의 도시 //최대 M개 치킨집을 제거
                        // type : 0은 빈 칸, 1은 집, 2는 치킨집 
vector<POSI> house, shop, pick; //집 위치, 치킨집 위치, 삭제하기로 선정된 치킨집 

void dfs(int pos) {
    if (pick.size() == m){ //뽑힌 크기가 m 사이즈가 되면 최대이면 종려 
        int total = 0;     //도시의 치킨 거리

        for (int i= 0; i < house.size(); ++i){
            int min_dist = 1000000;
            for (int j=0; j < pick.size(); ++j){
                // 거리 |집y좌표 - 치킨집 y좌표| + |집 x좌표 - 치킨집 x좌표|
                min_dist = min(min_dist, 
                abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));  
            }
            total += min_dist; 
        }
        if (result > total){ //최소 거리 갱신 
            result = total ; // 가장 작은 도시의 치킨 거리 
        }
        return; 
    }
    for (int i = pos ; i < shop.size(); ++i){
        pick.push_back(shop[i]); 
        dfs(i+1);
        pick.pop_back();
    }
}

int main() 
{
    POSI target; 
    scanf("%d %d", &n, &m);

    //행렬 값 받기 
    for (int y =0; y < n; ++y){
        for (int x = 0; x < n ; ++x){
            scanf("%d", &type);
            if(type == 1){ //집 
               target.x = x , target.y = y ; 
               house.push_back(target); //집 벡터에 값 넣기
            }
            if(type == 2){ //치킨집
                target.x = x, target.y = y; 
                shop.push_back(target); //치킨집 위치 벡터 넣기 
            }
        }
    }

    result = 0x7fffffff; 
    dfs(0);
    printf("%d\n",result);
    return 0; 
}