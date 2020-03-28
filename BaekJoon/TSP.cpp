#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream> 

using namespace std;
int w[20][20];
int main(){
    int n; //도시의 수 
    //cin >> n; 
    scanf("%d", &n); 
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            //cin >> w[i][j];
            scanf("%d", &w[i][j]);
        }
    }
    vector<int> d(n);  //n개 사이즈만큼
    for (int i=0; i<n; i++){
        d[i] = i;
    }
    int ans = 2147483647; 

    do{
        bool ok = true; 
        int sum = 0; 
        for (int i=0; i < n-1; i++){
            if(w[d[i]][d[i+1]] == 0){
                ok = false; 
            } else {
                sum += w[d[i]][d[i+1]];
            }
        }
        if ( ok && w[d[n-1]][d[0]] != 0){
            sum += w[d[n-1]][d[0]];
            if (ans > sum) ans = sum; 
        }

    }while (next_permutation(d.begin(), d.end()));

    printf("%d\n", ans); 
    return 0; 

}