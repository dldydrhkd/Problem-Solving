#
# 누적합
import sys

input = sys.stdin.readline
n = int(input())
li = [list(map(int,input().strip().split())) for _ in range(n)]
x = [0]*1000010
y = [0]*1000010
for i in range(len(li)):
    if(li[i][0]==li[(i+1)%len(li)][0]):
        y[min(li[i][1]+500000,li[(i+1)%len(li)][1]+500000)]+=1
        y[max(li[i][1]+500000,li[(i+1)%len(li)][1]+500000)]-=1
    else:
        x[min(li[i][0]+500000,li[(i+1)%len(li)][0]+500000)]+=1
        x[max(li[i][0]+500000,li[(i+1)%len(li)][0]+500000)]-=1
v_max = y[0]
h_max = x[0]
for i in range(1, 1000001):
    x[i] = x[i-1]+x[i]
    h_max = max(h_max, x[i])
    y[i] = y[i-1]+y[i]
    v_max = max(v_max, y[i])
print(max(v_max,h_max))

######################################################
# heapq와 sorting을 이용

# import sys
# import heapq

# input = sys.stdin.readline

# def cal(arr):
#     arr.sort()
#     heap = []
#     max_h = 1
#     for i in range(len(arr)):
#         low = arr[i][0]
#         high = arr[i][1]
#         while(heap and low>=heap[0]):
#             heapq.heappop(heap)
#         heapq.heappush(heap,high)
#         max_h = max(max_h,len(heap))

#     return max_h

# n = int(input())
# li = [list(map(int,input().strip().split())) for _ in range(n)]
# h_li = []
# v_li = []
# for i in range(len(li)):
#     if(li[i][0]==li[(i+1)%len(li)][0]):
#         v_li.append([min(li[i][1],li[(i+1)%len(li)][1]),max(li[i][1],li[(i+1)%len(li)][1])])
#     else:
#         h_li.append([min(li[i][0],li[(i+1)%len(li)][0]),max(li[i][0],li[(i+1)%len(li)][0])])
# h = cal(h_li)
# v = cal(v_li)

# print(max(h,v))
