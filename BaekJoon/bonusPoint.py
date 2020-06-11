# https://www.acmicpc.net/problem/17389

# OX 표에 N개의 문제들이 있을 때, 1번 ~ N번 문제 순 채점 
# 뒤로 갈수록 어려워짐. i번 문제 기본 점수는 i 점 
# 보너스 점수 : 문제 맞히면 0점부터 시작해서 1점씩 증가 
# 연속으로 맞춰야함. 연속아니면 초기화 

N, S = input(), input() 

score, bonus = 0, 0

for idx, OX in enumerate(S):
    if OX == 'O': 
        #score += idx + 1 
        #bonus += 1 
        score, bonus = score + idx + 1, bonus + 1 
    else : 
        bonus = 0 
    
print(score) 