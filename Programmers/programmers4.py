'''
https://programmers.co.kr/learn/courses/30/lessons/64064
def solution(user_id, banned_id):
    answer = 0
    return answer

'''


chk = 0b00000000 
s = [] 
def comb(user_id, banned_id,cnt): 
    global chk 
    if cnt == len(banned_id): 
        print(chk in s) 
        if chk in s==False: 
            print("ok") 
            s.append(chk) 
        print(s) 
        return 
    bid = banned_id[cnt] 
    for i in range(len(user_id)): 
        uid = user_id[i] 
        if len(bid)==len(uid) and chk & (1<<i) == False: 
            flag = True 
            for j in range(len(bid)): 
                if bid[j] != "*" and bid[j]!=uid[j]: 
                    flag = False 
                    break 

            if flag: 
                chk +=1<                comb(user_id, banned_id,cnt+1) 
                chk -=1<def solution(user_id, banned_id): 
    answer = 0 
    s =[] 
    comb(user_id, banned_id,0) 
    answer = len(s) 

    return answer 



input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"] 
input_bid = ["fr*d*", "abc1**"] 

# input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"] 
# input_bid = ["*rodo", "*rodo", "******"] 

# input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"] 
# input_bid = ["fr*d*", "*rodo", "******", "******"] 

print(solution(input_uid, input_bid)) 