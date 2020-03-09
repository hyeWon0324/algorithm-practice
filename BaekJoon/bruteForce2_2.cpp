// 모든 E,S,M 에서 1을 빼면, 이 문제는 다음을 만족하는 가장 작은 자연수 year 를 찾는 문제이다.
#include <iostream>
using namespace std; 

int main() {
    int e,s,m; 
    cin >> e >> s >> m; 
    e -= 1; 
    s -= 1; 
    m -= 1; 
    for (int i=0; ; i++){
        if(i % 15 == 3 && i % 28 == s && i % 19 == m ){
            cout << i +1 << '\n';
            break; 
        }
    }
}