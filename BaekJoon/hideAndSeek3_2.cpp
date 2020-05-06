#include <iostream>
#include <queue>
using namespace std; 
const int MAX = 1000000;
bool check[MAX+1]; 
int d[MAX+1];
int main(){
    int n,m; 
    cin >> n >> m; 
    check[n] = true; 
    d[n] = 0 ; 
    queue<int> q; 
    queue<int> next_queue; 
    q.push(n) ; 
    while (!q.empty()){
        int now = q.front() ; 
        q.pop(); 
        if (now * 2 < MAX) {
            if (check[now*2] == false){
                q.push(now*2); 
                check[now * 2] = true; 
                d[now * 2] = d[now]; 
            }
        }
        if(now-1 >= 0){
            if(check[now-1] == false){
                next_queue.push(now-1); 
                check[now-1] = true; 
                d[now-1] = d[now] + 1 ; 
            }
        }
        if(now+1 < MAX){
            if(check[now+1] == false){
                next_queue.push(now+1); 
                check[now+1] = true; 
                d[now+1] = d[now] + 1; 
            }
        }
        if (q.empty()) {
            q = next_queue; 
            next_queue = queue<int>(); 
        }
    }
    cout << d[m] << '\n';
    return 0; 

}