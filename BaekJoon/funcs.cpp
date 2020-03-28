#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> calculate(vector<int> &a, int index, int cur, int plus, int minus, int multip, int div){
    int n = a.size;
    if (index == n){
        return make_pair(cur, cur);
    }
    vector<pair<int,int>> res;
    if (plus > 0){
        res.push_back(calculate(a,index+1, cur+a[index], plus-1, minus, multip,div));
    }
    if (minus > 0){
        res.push_back(calculate(a,index+1, cur-a[index], plus, minus-1, multip, div)) ;
    }
    if (multip > 0){
        res.push_back(calculate(a,index+1, cur*a[index], plus, minus, multip-1, div)); 
    }
    if (div > 0){
        res.push_back(calculate(a,index+1, cur/a[index],plus,minus,multip,div-1));
    }
    auto ans = res[0];
    for (auto p : res){
        if (ans.first < p.first) {
            ans.first = p.first;
        }
        if (ans.second > p.second) {
            ans.second = p.second; 
        }
    }
    return ans; 
}
int main(){
    int n ;
    cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int plus, minus, multip, div;
    cin >> plus >> minus >> multip >> div;
    auto p = calculate(a, 1, a[0], plus, minus, multip, div);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0; 
}