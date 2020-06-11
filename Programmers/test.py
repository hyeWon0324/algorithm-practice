import re 

expression="100-200*300-500+20"

res = re.split(r'(\D)', expression)
print(res)

regex = re.compile('\D')
operands = regex.findall(expression)
print(operands)

regex = re.compile('\d+')
numbers = regex.findall(expression)
print(numbers)