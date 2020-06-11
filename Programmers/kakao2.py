'''
참가자에게 주어진 연산 수식이 담긴 문자열 expression이 매개변수로 주어질 때, 우승 시 받을 수 있는 가장 큰 상금 금액을 return 하도록 solution 함수를 완성해주세요.

[제한사항]
expression은 길이가 3 이상 100 이하인 문자열입니다.
expression은 공백문자, 괄호문자 없이 오로지 숫자와 3가지의 연산자(+, -, *) 만으로 이루어진 올바른 중위표기법(연산의 두 대상 사이에 연산기호를 사용하는 방식)으로 표현된 연산식입니다. 잘못된 연산식은 입력으로 주어지지 않습니다.
즉, "402+-561*"처럼 잘못된 수식은 올바른 중위표기법이 아니므로 주어지지 않습니다.
expression의 피연산자(operand)는 0 이상 999 이하의 숫자입니다.
즉, "100-2145*458+12"처럼 999를 초과하는 피연산자가 포함된 수식은 입력으로 주어지지 않습니다.
"-56+100"처럼 피연산자가 음수인 수식도 입력으로 주어지지 않습니다.
expression은 적어도 1개 이상의 연산자를 포함하고 있습니다.
연산자 우선순위를 어떻게 적용하더라도, expression의 중간 계산값과 최종 결괏값은 절댓값이 263 - 1 이하가 되도록 입력이 주어집니다.
같은 연산자끼리는 앞에 있는 것의 우선순위가 더 높습니다.

(\d+\D)+ (\d+)
'''
import re 
from itertools import permutations 

expression="100-200*300-500+20"
# operands=''

# def expressions(vals): 
#     exp_list = '' 
#     for i in range(len(vals)):    
#         forward = vals[:]
#         val = forward.pop(i)

#         for op in operators: 
#             operators.pop(i)
#             for rest in expressions(forward): 
#                 yield [val, op] + rest 

def changePriority(operators):
    
    operators = list(dict.fromkeys(operators))
    prioList = permutations(operators)
    print(prioList)
    return prioList

def solution(expression):
    answer = 0 
    result = 0 
    
    regex = re.compile('\D')
    operands = regex.findall(expression)

    regex = re.compile('\d+') 
    values = regex.findall(expression)

    for perm in changePriority(operands): 
        #change expression by priority 
        # calculate first priority 
        op_list = operands
        num_list = values
        for op in perm : 
            index = op_list.index(op)
            val1 = num_list[index] 
            val2 = num_list[index+1]
            
            exp = val1+op+val2 

            #if op_list.count(op) > 1 : 
            op_list.pop(index)
                
            exp = '' #= result + operands[i] + values[i]
        
            result = eval(exp)
            if answer < abs(result) : 
                answer = result 

    return answer

print(solution(expression))