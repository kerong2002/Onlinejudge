def move_onto(block,position,a,b):
# ===========<檢查是否在同一個位置>============
    if(position[a][0]==position[b][0]):
        return
# ============<將A上方塊移回去>============
    A_Y=position[a][0]
    for x in range(position[a][1]+1,len(block[A_Y])):
        pick=block[A_Y][x]
        block[pick].append(pick)
        size=len(block[pick])-1
        position[pick][0]=pick
        position[pick][1]=size
    del block[A_Y][position[a][1]+1:]
# ============<將B上方塊移回去>============
    B_Y = position[b][0]
    for x in range(position[b][1] + 1, len(block[B_Y])):
        pick = block[B_Y][x]
        block[pick].append(pick)
        size = len(block[pick]) - 1
        position[pick][0] = pick
        position[pick][1] = size
    del block[B_Y][position[b][1] + 1:]
# ============<將A移到B>============
    block[position[b][0]].append(a)
    size=len(block[position[b][0]])-1
    del block[position[a][0]][position[a][1]:]
    position[a][0]=position[b][0]
    position[a][1]=size
    # print(block)
def move_over(block,position,a,b):
# ============<檢查是否在同一個位置>============
    if (position[a][0] == position[b][0]):
        return
    '''============<將A上方塊移回去>============'''
    A_Y = position[a][0]
    for x in range(position[a][1] + 1, len(block[A_Y])):
        pick = block[A_Y][x]
        block[pick].append(pick)
        size = len(block[pick]) - 1
        position[pick][0] = pick
        position[pick][1] = size
    del block[A_Y][position[a][1] + 1:]
# ============<將A移到B>============
    block[position[b][0]].append(a)
    size = len(block[position[b][0]]) - 1
    del block[position[a][0]][position[a][1]:]
    position[a][0] = position[b][0]
    position[a][1] = size
    # print(block)
def pile_onto(block,position,a,b):
    # ===========<檢查是否在同一個位置>============
    if (position[a][0] == position[b][0]):
        return
    # ============<將B上方塊移回去>============
    B_Y = position[b][0]
    for x in range(position[b][1] + 1, len(block[B_Y])):
        pick = block[B_Y][x]
        block[pick].append(pick)
        size = len(block[pick]) - 1
        position[pick][0] = pick
        position[pick][1] = size
    del block[B_Y][position[b][1] + 1:]
    size = position[b][1]+1
    for i in block[position[a][0]][position[a][1]:]:
        block[B_Y].append(i)
    del block[position[a][0]][position[a][1]:]
    for x in range(size,len(block[B_Y])):
        position[block[B_Y][x]][0]=B_Y
        position[block[B_Y][x]][1]=x
    # print(block)
def pile_over(block,position,a,b):
    # ===========<檢查是否在同一個位置>============
    if (position[a][0] == position[b][0]):
        return
    B_Y = position[b][0]
    size = position[b][1]+1
    for i in block[position[a][0]][position[a][1]:]:
        block[B_Y].append(i)
    del block[position[a][0]][position[a][1]:]
    for x in range(size,len(block[B_Y])):
        position[block[B_Y][x]][0]=B_Y
        position[block[B_Y][x]][1]=x
    # print(block)
while True:
    try:
        n=int(input())
        block=[]
        position=[]
        for i in range(n):
            position.append([i,0])
            block.append([i])
            # if(i==5 or i==9):
            #     block.append([])
            # else:
            #     block.append([i])
        # block[2].append(5)
        # block[2].append(9)
        # position[5][0]=2
        # position[9][0]=2
        # print(block)
        # print(position)
        while True:
            action=list(map(str,input().split()))
            if(action[0]=='quit'):
                # print('get out')
                break
            a=int(action[1])
            b=int(action[3])
            active=action[0]+" "+action[2]
            if(active=="move onto"):
                move_onto(block,position,a,b)
            if(active=="move over"):
                move_over(block,position,a,b)
            if(active=="pile onto"):
                pile_onto(block,position,a,b)
            if(active=="pile over"):
                pile_over(block,position,a,b)
        for y in range(n):
            print("{}:".format(y),end='')
            for x in range(len(block[y])):
                print(" {}".format(block[y][x]),end='')
            print()
    except:
        break