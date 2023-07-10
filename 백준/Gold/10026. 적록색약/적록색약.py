N = int(input())
rgb = [input() for _ in range(N)]
up_down = [0,0,1,-1]
left_right = [1,-1,0,0]

area = [[-1 for _ in range(N)] for _ in range(N)]
num = 0

def find_rgb(i,j) :
  global num
  for k in range(4):
    x = max(0,min(N-1,i+up_down[k]))
    y = max(0,min(N-1,j+left_right[k]))
    if rgb[x][y] == rgb[i][j] :
      if area[x][y] < 0 :
        area[x][y] = area[i][j]
      else :
        tem = area[x][y]
        area[x][y] = area[i][j] = min(area[x][y],area[i][j])
        if area[x][y] != tem :
          find_rgb(x,y)
    elif area[x][y] < 0 :
      num += 1
      area[x][y] = num

def func() :
  area[0][0] = 0
  for i in range(N):
    for j in range(N):
      find_rgb(i,j)

func()
num1 = len(set(sum(area,[])))

for i in range(N):
  rgb[i] = rgb[i].replace('G','R')
func()
num2 = len(set(sum(area,[])))

print(num1,num2)