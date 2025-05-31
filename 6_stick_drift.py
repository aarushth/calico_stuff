T = int(input())

def shortDistance(startN, startM, endN, endM):
        return min(abs(startN-endN), min(startN+N-endN,endN+N-startN)) + min(abs(startM-endM), min(startM+M-endM, endM+M-startM))

for t in range(T):
    N, M = map(int, input().split())
    S = input()
    

    dic = {}
    lis = []
    for n in range(N):
        li = [int(x) for x in input().split()]
        for m in range(M):
            dic[lis[m]] = (n, m)
        lis.append(li)
    
    prev = (0, 0)
    tot = 0
    for i in range(1, (N*M)+1):
        tup = dic[i]
        tot += shortDistance(prev[0], prev[1], tup[0], tup[1])
        prev = tup
        
    print(tot)