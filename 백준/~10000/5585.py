t = int(input())
t = 1000-t

t_sum = 0

t_sum += t//500
t = t%500
t_sum += t//100
t = t%100
t_sum += t//50
t = t%50
t_sum += t//10
t = t%10
t_sum += t//5
t = t%5
t_sum += t//1

print(t_sum)