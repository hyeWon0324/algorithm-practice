'''
https://programmers.co.kr/learn/courses/30/lessons/64065


'''
def solution(s):
    answer = []
    s = s[2:-2]        # 맨 앞과 뒤에 있는 {{ }} 를 빼준다
    s = s.split("},{") # 사이에 있는 괄호도 
    #print(s)
    s.sort(key = len)   # 길이순 정렬 
    #print(s)

    for i in s: 
        tmp = i.split(',')
        #print(tmp)
        for j in tmp: 
            if int(j) not in answer: 
                answer.append(int(j))

    return answer


#input_s = "{{2},{2,1},{2,1,3},{2,1,3,4}}" 
input_s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"
#input_s = "{{123}}"
#input_s = "{{20,111},{111}}"
print(solution(input_s))


# 정규식 사용하기 
import re
from collections import Counter

def solution2(s):
   s = Counter(re.findall('\d+', s))
   return list(map(int, [k for k, v in sorted(s.items(), key=lambda x: x[1], reverse=True)]))


