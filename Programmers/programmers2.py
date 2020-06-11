'''
https://programmers.co.kr/learn/courses/30/lessons/64061
위쪽에 크레인 / 좌우 움직임 

n * n 크기의 정사각 격자
격자의 가장 아래 칸에 

board 배열 : 5 이상 30 이하 
board 각 칸에 0~100 인형인덱스 / 0 은 아무것도 없다 
예시: 
a[row][column] 
a[소집합][세부원소]
[
[0,0,0,0,0],
[0,0,1,0,3],
[0,2,5,0,1],
[4,2,4,4,2],
[3,5,1,3,1]
]

moves 배열 : 1 ~ 1000 
예시: [1,5,3,5,1,2,1,4]


int result
예시: 4

'''
def solution(board, moves):
    # moves-1 는 어떤 column으로 갈지 
    answer = 0   #마지막에 쌓인 개수 
    stack = []   #쌓아가는 곳 
    count = 0

    for col in moves:
        for i in range(len(board)) : 
            picked = board[i][col-1]
            if picked == 0 : 
                continue

            if len(stack) > 0 :
                print(stack[-1])
                if stack[-1] == picked:
                    stack.pop()
                    count += 1
                else:
                    stack.append(picked)
                    
            else: 
                stack.append(picked)

            board[i][col-1] = 0 
            break
            
    answer = count * 2 

    return answer

board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
moves = [1, 5, 3, 5, 1, 2, 1, 4]
print(solution(board, moves))