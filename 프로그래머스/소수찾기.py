from itertools import permutations

def solution(numbers):
    answer = []
    primes = [True]*10000000
    primes[0] = False
    primes[1] = False
    for i in range(2, 10000000):
        if(primes[i]==True):
            j = 2
            while(i*j < 10000000):
                primes[i*j] = False
                j+=1
    for i in range(1, len(numbers)+1):
        li = list(map(''.join,permutations(numbers,i)))
        for j in set(li):
            if(primes[int(j)]):
                answer.append(int(j))
    return len(set(answer))
