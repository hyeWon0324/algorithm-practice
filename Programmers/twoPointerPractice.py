# 특정한 합을 가지는 부분 연속 수열 찾기 
# 투 포인터를 활용한 알고리즘 설명 
# 1.시작점과 끝전이 첫번째 원소의 인덱스를 가리키도록 한다 
# 2. 현재 부분 합이 M과 같다면, 카운트한다 
# 3. 현재 부분 합이 M보다 작다면, end 를 1 증가시킨다 
# 4. 현재 부분 합이 M보다 크다면, start를 1 증가시킨다 
# 5. 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다 
# O(N)
# 데이터의 개수 N과 부분 연속 수열의 합 M을 입력 받기 
n, m = 5,5 
data = [1,2,3,2,5]

result = 0 
summary = 0 
end = 0 

for start in range(n):
    # end를 가능한 만큼 이동시키기 
    while summary < m and end < n: # 현재 부분 합이 m보다 작으므로 end 를 1 증가 
        summary += data[end] 
        end += 1 
    # 부분 합이 m일 때 카운트 증가 
    if summary == m: 
        result += 1 
    summary -= data[start]

print(result)