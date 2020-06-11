#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check[25][25];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int answer = -1;
int go(vector<vector<int>> board, int x, int y, int price, int cross, int previous){
    int sizea = board.size();
    if(x == sizea -1 && y == sizea - 1){
        return price;
    }
    if(answer != -1 && answer < price  +( (sizea - x) + (sizea - y) ) * 100){
        return -1;
    }
    int temp = -1;
    int nx = x + dx[previous];
    int ny = y + dy[previous];
    if(nx>=0 && nx<sizea && ny >= 0 && ny<sizea && board[nx][ny] == 0 && check[nx][ny] == false){
        check[nx][ny] = true;
            temp = go(board, nx, ny, price +100, abs(dx[previous]), previous);
            if(temp != -1 && (answer == -1 || answer>temp)){
                answer = temp;
            }
        check[nx][ny] = false;
    }
    for(int i=0; i<4; i++){
        if(previous == i || previous == (i+2)%4){
            continue;
        }
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx>=0 && nx<sizea && ny >= 0 && ny<sizea && board[nx][ny] == 0 && check[nx][ny] == false){
            check[nx][ny] = true;
            temp = go(board, nx, ny, price+600, abs(dx[i]), i);
            if(temp != -1 && (answer == -1 || answer>temp)){
                answer = temp;
            }
            check[nx][ny] = false;
        }
    }
    return answer;
}
int solution(vector<vector<int>> board) {
    check[0][0] = true;
    for (int i = 0; i<2; i++){
        answer = go(board, 0, 0, 0, 0, i);
    }
    return answer;
}