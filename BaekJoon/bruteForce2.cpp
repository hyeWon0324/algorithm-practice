// 1476번 - 날짜 계산
// https://www.acmicpc.net/problem/1476
// 준규가 사는 나라에서는 수 3개를 이용해서 연도를 나타낸다. 
// 지구를 나타내는 수를 E, 태양을 나타내는 수를 S, 달을 나타내는 수를 M이라고 했을 때, 이 세 수는 서로 다른 범위를 가진다. 
// (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)
// 1년이 지날 때마다, 세 수는 모두 1씩 증가한다. 만약, 어떤 수가 범위를 넘어가는 경우에는 1이 된다.


#include <iostream>
using namespace std;
int main(){
    int E, S, M;
    cin >> E >> S >> M;
    int e=1, s=1, m=1;
    for (int i=1; ; i++){
        if (e == E && s == S && m == M){
            cout << i << '\n';
            break; 
        }
        e += 1; 
        s += 1; 
        m += 1; 
        if (e == 16){
            e == 1; 
        }
        if (s == 29){
            s = 1 ; 
        }
    }
}