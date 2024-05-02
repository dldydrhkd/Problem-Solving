t = list(map(int, input().split()))
duration = int(input())

h = duration//60
m = duration%60

last_m = (m+t[1])%60
last_h = (((m+t[1])//60)+h+t[0])%24

print(str(last_h) + " " + str(last_m))