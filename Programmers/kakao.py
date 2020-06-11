'''
맨 처음 왼손 엄지손가락은 * 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 
엄지손가락을 사용하는 규칙은 다음과 같습니다.

엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 
해당합니다.
왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서
 더 가까운 엄지손가락을 사용합니다.
4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손
엄지손가락을 사용합니다.
순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열
hand가 매개변수로 주어질 때, 각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는
연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.

https://programmers.co.kr/tryouts/13901/submissions/5798233?challengeable_type=ChallengeAlgorithm
'''
# left : *[3,0] , 1[0,0], 4[1,0], 7[2,0] 
# right : #[3,2], 3[0,2], 6[1,2], 9[2,2] 
# 2[0,1] , 5[1,1] ,8[2,1], 0[3,1], 
def solution(numbers, hand):
    answer = ''

    left = ['*',1,4,7]
    leftM = [[3,0], [0,0], [1,0], [2,0]]

    right = ['#',3,6,9]
    rightM = [[3,2], [0,2], [1,2], [2,2]]

    mid = [2,5,8,0]
    midM = [[0,1], [1,1], [2,1], [3,1]] 
    
    phone = left + right + mid 
    matrix = leftM + rightM + midM 

    leftPos = -1
    rightPos = -1
    leftDist = 0 
    rightDist = 0 

    for num in numbers : 

        if num in left:
            leftPos = num 
            answer += 'L'
        elif num in right: 
            rightPos = num 
            answer += 'R'
        else: 
            i = phone.index(num)
            l = phone.index(leftPos)
            r = phone.index(rightPos)
            leftDist = abs(matrix[i][0] - matrix[l][0]) + abs(matrix[i][1]-matrix[l][1])
            rightDist = abs(matrix[i][0] - matrix[r][0]) + abs(matrix[i][1]-matrix[r][1])

            if leftDist < rightDist : 
                answer += 'L'
                leftPos = num           # 왼손 위치 변동 
            elif rightDist < leftDist :
                answer += 'R'
                rightPos = num          # 오른손 위치 변동 
            else : 
                if hand == 'left' : 
                    answer += 'L'
                    leftPos = num        # 왼손 위치 변동 
                else: 
                    answer += 'R'
                    rightPos = num       # 오른손 위치 변동 
        
        print('answer= ', end='')
        print(answer)

    return answer

numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
hand = 'right'
print(solution(numbers,hand))

        # print('num ', end='')
        # print(num)
        
            # print('left ', end='')
            # print(leftPos)
            # print('right ', end='')
            # print(rightPos)

            # print('leftDist ', end='')
            # print(leftDist)
            # print('rightDist ', end='')
            # print(rightDist)
            #leftDist = midM[i].sub(leftM[l]).abs()
            #leftDist = np.abs(midM[i] - leftM[l])
            #rightDist = midM[i].sub(rightM[r]).abs()
            #rightDist = np.abs(midM[i] - rightM[r])