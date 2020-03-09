#include <iostream>
#include <algorithm>

using namespace std;

int a[9];
int n = 9;

// 2309번 - 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
// 아홉 난쟁이 중 일곱명의 난쟁이를 찾는 문제 
// 일곱 난쟁이의 키의 합은 100이다 
// 아홉 명 중에 두 명을 고르는 것과 같다 
//

int main(){
    int sum = 0;
    for (int i=0; i < n; i++ ){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n); 
    for (int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(sum -a[i] - a[j] == 100){
                for (int k=0; k<n; k++){
                    if(i == k|| j == k) continue;
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}