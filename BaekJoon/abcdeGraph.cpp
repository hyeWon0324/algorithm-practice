//https://www.acmicpc.net/problem/13023
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
bool a[2000][2000];
vector<int> g[2000];
vector<pair<int,int>> edges; 
int main(){
    int n, m; 
    // n 은 사람의 수  //m 친구 관계의 수 
    cin >> n >> m; 
    for (int i=0; i<m; i++){
        int from, to;           // 친구 두 명 입력 
        cin >> from >> to; 
        edges.push_back({from, to});
        edges.push_back({to, from}); 
        a[from][to] = a[to][from] = true; 
        g[from].push_back(to);
        g[to].push_back(from); 
    }
    m *= 2; 


    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            // A -> B 
            int A = edges[i].first; 
            int B = edges[i].second; 

            //C -> D 는 그냥 간선이기 떄문에, 간선 리스트로 
            int C = edges[j].first ; 
            int D = edges[j].second; 
            if (A == B || A == C || A == D || B == C || B == D ||
             C == D ){
                continue; 
            }

            // B -> C 는 인접 행렬 
            if(!a[B][C]) {
                continue; 
            }

            // D -> E 는 인접 리스트로 
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E){
                    continue;
                }
                cout << 1 << '\n';
                return 0; 
            }
        }
    }
    cout << 0 << '\n';
    return 0; 
}