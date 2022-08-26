t={}
def count_time(run):
    if run in t:
        return t[run]
    if run <=1:
        return 1
    if run % 2 ==1:
        y = 3*run+1
    else:
        y = run //2
    t[run]=count_time(y)+1
    return t[run]
while True:
    try:
        i,j = map(int,input().split())
    except EOFError:
        break
    max_length=0
    for run in range(min(i,j),max(i,j)+1):
        max_length=max(max_length,count_time(run))
    print(i,j,max_length)