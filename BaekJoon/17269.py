# https://www.acmicpc.net/problem/17269
# 이름궁합 테스트 
# 이름의 길이 N, M 
N, M = map(int, input().split()) 

# 이름 A,B 
A, B = input().split() 

alp = [3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,
        2,2,2,1,2,1,1,1,2,2,1]

# 이름 A:LEESIYUN ,  B: MIYAWAKISAKURA
# AB =  L M E I E Y S A I W Y A U K N I S A K U R A
# 두 이름 합친다 
AB = ''
min_len = min(N,M)   # 두 이름 중에 짧은 것으로 
for i in range(min_len):
    AB += A[i] + B[i]

AB += A[min_len:] + B[min_len:]   #끝에 남은 문자들. A는 빈문자열 될 것 

lst = [alp[ord(i)-ord('A')] for i in AB] 
# i 로 들어온 알파벳을 아스키코드로 변형 

for i in range(N+M-2):
    for j in range(N+M-1-i): 
        lst[j] += lst[j+1]

print("{}%".format(lst[0] % 10*10 + lst[1] % 10))


