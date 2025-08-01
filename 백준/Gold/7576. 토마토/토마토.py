M,N = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
stack=[]
dx = [0,0,1,-1]
dy = [1,-1,0,0]
num=0
for i in range(N):
  for j in range(M):
    if arr[i][j]==1 :
      stack.append([i,j])
while stack:
  new_stack = []
  while stack:
    xy=stack.pop()
    for i in range(4):
      x1 = xy[0]+dx[i]
      y1 = xy[1]+dy[i]
      if x1<0 or y1<0 or x1>=N or y1>=M:
        continue
      if arr[x1][y1] == 0:
        arr[x1][y1] = 1
        new_stack.append([x1,y1])
  stack=new_stack
  num+=1
sum=0
for i in range(N):
  sum += arr[i].count(0)
if sum!=0:
  num=0
print(num - 1)