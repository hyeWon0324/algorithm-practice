//https://www.acmicpc.net/problem/13549
//수빈이는 현재 점 N 
//동생은 점 K
//수빈이가 동생을 찾을 수 있는 가장 빠른 시간은? 
// 수빈위치가 x 라면: 
//1.걷기: x-1 또는 x+1 
//2.순간이동: 0초 후 2*X 위치 이동 
//BFS
//덱 사용 : 순간이동은 덱의 앞에, 걷기는 덱의 뒤에 
#include <iostream>
#include <queue>
#include <deque>
using namespace std; 
bool c[1000000];
int d[1000000]; 
int MAX = 1000000;
int main(){
    int n,m;
    cin >> n >> m;  //수빈, 동생 위치 
    c[n] = true;    //
    d[n] = 0;       //
    deque<int> q; 
    q.push_back(n); 
    while(!q.empty()){
        int now = q.front(); 
        q.pop_front();
        if(now*2 < MAX) {
            if(c[now*2] == false){ // 2배 이동 
                q.push_front(now*2);
                c[now*2] = true; 
                d[now*2] = d[now]; //0초 
            }
        }
        if (now-1 >= 0){
            if(c[now-1] == false){ // -1 이동 
                q.push_back(now-1);
                c[now-1] = true; 
                d[now-1] = d[now] + 1; //1초 
            }
        }
        if (now+1 < MAX){
            if(c[now+1] == false){
                q.push_back(now+1);
                c[now+1] = true; 
                d[now+1] = d[now] + 1 ;
            }
        }
    }
    cout << d[m] << '\n'; 
    return 0 ; 
} 