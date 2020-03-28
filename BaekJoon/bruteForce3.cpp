// 테르로미노
// https://www.acmicpc.net/problem/14500
// 폴리오미노란 크기가 ×1인 정사각형을 여러 개 이어서 붙인 도형이다 
// 정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 총 5가지가 있다. 
// N * M  크기의 종이 위에 티트로미노를 하나 놓아서 
// 놓인 칸에 쓰여 있는 수의 합을 최대로 하는 문제 
// 4 <= N, M <= 500 
// 정사각형은 서로 겹치면 안 된다 
// 도형은 모두 연결되어 있어야 한다. 
// 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다 

// ㅁㅁㅁㅁ N * (M-3)
/* (N-2)(M-1) <= NM 
   ㅁ
   ㅁ
   ㅁ
   ㅁㅁ
*/ 
// 블록 19개 중에서 하나를 놓는 것은 NM 가지가 있다 
// O(19 * NM) = 19 * 500^2 
// 19가지 기준 
// 
#include <iostream>
using namespace std; 
int a[500][500];
int main() {
    int n,m; 
    cin >> n >> m;
    for (int i =0; i <n; i++){
        for (int j=0; j <m; j++){
            cin>> a[i][j];
        }
    }
    int ans = 0; 
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //1
            if(j+3 < m){ 
                // ㅅㅏ각형이 4개 가로로 붙어있는것 
                int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
                if (ans < temp) ans = temp; 
            }
            //2
            if (i+3 < n) {
                // 사각형이 4개 수직으로 
                int temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
                if (ans < temp) ans = temp;
            }
            //3
            if (i+1 < n && j+2 < m){
                // ㅁ
                // ㅁㅁㅁ
                int temp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
                if (ans < temp) ans = temp; 
            }
            //4
            if (i+2 < n && j+1 < m){
                // ㄱ자를 왼쪽으로 뒤집은 것. 사각형 왼쪽에 세로로 3줄 
                // ㅁㅁ
                // ㅁ
                // ㅁ
                int temp = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
                if (ans < temp) ans = temp;
            }
            //5
            if (i+1 < n && j+2 < m){
                // ㄱ 자  ㅁㅁㅁ
                //          ㅁ
                int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
                if(ans < temp) ans = temp; 
            }
            //6
            if (i+2 < n && j-1 >= 0){
                // ㅁ 
                // ㅁ
                //ㅁㅁ
                int temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1];
                if (ans < temp) ans = temp; 
            }
            //7
            if (i-1 >= 0 && j+2 < m){
                //    ㅁ
                // ㅁㅁㅁ
                int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i-1][j+2]; 
                if (ans < temp) ans = temp;
            }
            //8
            if (i+2 < n && j+1 < m) {
                // ㅁ
                // ㅁ
                // ㅁㅁ
                int temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1]; 
                if (ans < temp) ans = temp; 
            }
            //9
            if (i+1 < n && j+2 < m){
                // ㅁㅁㅁ
                // ㅁ
                int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j]; 
                if (ans < temp) ans = temp; 
            }
            //10
            if (i+2 < n && j+1 < m){
                // ㅁㅁ
                //  ㅁ
                //  ㅁ
                int temp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
                if (ans < temp) ans = temp; 
            }
            //11
            if (i+1 < n && j+1 < m){
                // ㅁㅁ
                // ㅁㅁ
                int temp = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
                if (ans < temp) ans = temp; 
            }
            //12
            if (i-1 >= 0 && j+2 < m){
                //  ㅁㅁ
                // ㅁㅁ
                int temp = a[i][j] + a[i][j+1] + a[i-1][j+1] + a[i-1][j+2];
                if (ans < temp) ans = temp; 
            }
            //13
            if (i+2 < n && j+1 < m){
                // ㅁ
                // ㅁㅁ
                //  ㅁ
                int temp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1]; 
                if (ans < temp) ans = temp; 
            }
            if (i+1 < n && j+2 < m) {
                // ㅁ ㅁ 
                //    ㅁ ㅁ
                int temp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
                if (ans < temp) ans = temp; 
            }
            if (i+2 < n && j-1 >= 0) {
                //  ㅁ  
                //ㅁ ㅁ
                //ㅁ
                int temp = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+2][j-1];
                if (ans < temp) ans = temp; 
            }
            if (j+2 < m) {

                int temp = a[i][j] + a[i][j+1] + a[i][j+2];
                if (i-1 >= 0){
                    int temp2 = temp + a[i-1][j+1]; 
                    if (ans < temp2) ans = temp2; 
                }
                if (i+1 < n){
                    int temp2 = temp + a[i+1][j+1] ;
                    if (ans < temp2) ans = temp2; 
                }
            }
            if (i+2 < n){
                int temp = a[i][j] + a[i+1][j] + a[i+2][j]; 
                if (j+1 < m){
                    int temp2 = temp + a[i+1][j+1]; 
                    if (ans < temp2) ans = temp2; 
                }
                if (j-1 >= 0 ) {
                    int temp2 = temp + a[i+1][j-1] ;
                    if (ans < temp2) ans = temp2; 
                }
            }
            cout << ans << '\n';
            return 0 ;
        }
    }
}