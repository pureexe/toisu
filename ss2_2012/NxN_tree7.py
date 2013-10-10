import sys
def make(en):
    x=0
    for i in range(en):
        x=x+i
    return x
roundx=input()
ct=0
gen=0
while ct<roundx:
    gen=gen+1
    ct=ct+gen
for i in range(gen+1):
    if i%2==1:
        sys.stdout.write(" "*(gen-1))
        for k in range(i):
            if((make(i)+k+1)<roundx):
                sys.stdout.write(str((make(i)+k+1)%10))
            else:
                sys.stdout.write(" ")
        sys.stdout.write("\n")
    else:
        sys.stdout.write(" "*(gen-i))
        for k in reversed(range(i)):
            if((make(i)+k)<roundx):
                sys.stdout.write(str((make(i)+k+1)%10))
            else:
                sys.stdout.write(" ")
        sys.stdout.write("\n")
