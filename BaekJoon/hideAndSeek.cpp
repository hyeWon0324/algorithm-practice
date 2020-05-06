//https://www.acmicpc.net/problem/1697
//수빈이의 위치: N 
//동생의 위치: K 
//동생을 찾는 가장 빠른 시간을 구하기 
//수빈이가 할 수 있는 행동(위치: X)
// 1.걷기: X+1 또는 X-1 로 이동(1초)
// 2.순간이동: 2 * X 로 이동(1초)
//큐에 수빈의 위치를 넣어가며 이동 
//갔던 곳은 배열로 체크 
//check[i] = i 룰 방문해는지
//dist[i] = i 를 몇 번만에 방문했는지 
//check[n] = true; 
#include <iostream>
#include <queue>
using namespace std; 
const int MAX = 200000; 
bool check[MAX+1];
int dist[MAX+1];
int main(){
    int n,m;
    cin >> n >> m; 
    check[n] = true; 
    dist[n] = 0; 
    queue<int> q; 
    q.push(n);
    while(!q.empty()){
        int now = q.front(); 
        q.pop(); 
        if (now -1 >= 0){
            if(check[now-1] == false){
                q.push(now-1); 
                check[now-1] = true; 
                dist[now-1] = dist[now] +1; 
            }
        }
        if(now+1 < MAX){
            if(check[now+1] == false){
                q.push(now+1); 
                check[now+1] = true; 
                dist[now+1] = dist[now] + 1; 
            }
        }
        if (now * 2 < MAX) {
            if (check[now*2] == false){
                q.push(now*2); 
                check[now*2] = true; 
                dist[now*2] = dist[now] + 1;
            }
        }
    }
    cout << dist[m] << '\n'; 
    return 0 ; 
}
