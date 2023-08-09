N,K = map(int,input().split())
arr = list(map(int,input().split()))

dp=[0]*1000000
num=0
min=-1
for i in range(N) :
  if arr[i] == 2 :
    continue
  dp[num] = i
  if num > K-2 :
    tem = dp[num] - dp[num-K+1] + 1
    min = tem if tem < min or min < 0 else min
  num+=1
print(min)