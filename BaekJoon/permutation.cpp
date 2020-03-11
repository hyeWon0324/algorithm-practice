#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

//다음 순열 
//A[i-1] < A[i] 를 만족하는 가장 큰 i를 찾는다 
// j>= i 이면서 A[j] > A[i-1] 를 만족하는 가장 큰j를 찾는다 
// A[i-1]과 A[j] 를 swap한다 
// A[i]부터 순열을 뒤집는다


// 다음 순열
bool next_permutation(int *a, int n){ // 배열 a 의 값을 바꾼다 
    int i = n-1;    //마지막 요소부터 
    while (i > 0 && a[i-1] >= a[i]) i -= 1; // 이전 요소가 현재 요소보다 크면 앞으로 간다 
    if (i <= 0) return false;       //마지막 순열 
    int j = n-1;                    // 크면서 가장 작은 수 
    while (a[j] <= a[i-1]) j -= 1;  //
    swap(a[i-1], a[j]); //
    j = n-1; 
    while (i < j){
        swap(a[i], a[j]);
        i += 1; 
        j -= 1; 
    }
    return true; 
}

// 다음 순열
bool prev_permutation(int *a, int n){ // 배열 a 의 값을 바꾼다 
    int i = n-1;    //마지막 요소부터 
    while (i > 0 && a[i-1] <= a[i]) i -= 1; // 이전 요소가 현재 요소보다 크면 앞으로 간다 
    if (i <= 0) return false;       //마지막 순열 
    int j = n-1;                    // 크면서 가장 작은 수 
    while (a[j] >= a[i-1]) j -= 1;  //
    swap(a[i-1], a[j]); //
    j = n-1; 
    while (i < j){
        swap(a[i], a[j]);
        i += 1; 
        j -= 1; 
    }
    return true; 
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        a[i] = i+1; 
    }
    do{
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }while (next_permutation(a.begin(), a.end()));
    return 0; 
}