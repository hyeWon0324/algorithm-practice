//https://www.acmicpc.net/problem/14226
//이모티콘 S개
//화면에 1개 입력, 3가지 연산만 사용 
//화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장 
//클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 
//화면에 있는 이모티콘 중 하나 삭제
//S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값
// S (2 ≤ S ≤ 1000) 
#include <iostream> 
#include <tuple>
#include <queue>
#include <cstring>
using namespace std; 
int d[1001][1001];
int main() {
    int n; //S 개 
    cin>> n; 
    memset(d,-1, sizeof(d));
    queue<pair<int,int>> q; 
    q.push(make_pair(1,0)); 
    d[1][0] = 0; 
    while(!q.empty()){
        int s, c; 
        tie(s,c) = q.front() ;
        q.pop();
        // 복사: (s,c) -> (s,s)
        if(d[s][s] == -1){
            d[s][s] = d[s][c] + 1; 
            q.push(make_pair(s,s)); 
        }
        //붙여넣기: (s,c)-> (s+c, c)
        if(s+c <= n && d[s+c][c] == -1){
            d[s+c][c] = d[s][c] + 1; 
            q.push(make_pair(s+c, c)); 

        }
        //삭제 : (s,c)->(s-1,c)
        if(s-1 >= 0 && d[s-1][c] == -1){
            d[s-1][c] = d[s][c] + 1; 
            q.push(make_pair(s-1, c)); 
        }
    }
    int ans = -1 ; 
    for (int i =0; i<n; i++){
        if(d[n][i] != -1){
            if(ans == -1 || ans > d[n][i]){
                ans = d[n][i]; //  i개의 이모티콘을 화면에 만드는데 걸리는 시간
            }
        }
    }
    cout << ans << '\n';
    return 0; 
}