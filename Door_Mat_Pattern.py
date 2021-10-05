N,M=[int(i) for i in input('').split()]
y=int((M-7)/2)
for i in range(1,N,2):
    x=3*i
    m=int((M-x)/2)
    print('-'*m+'.|.'*i+'-'*m)
    s=i
print('-'*(y)+'WELCOME'+'-'*(y))
for i in range(s,0,-2):
    x=3*i
    m=int((M-x)/2)
    print('-'*m+'.|.'*i+'-'*m)
