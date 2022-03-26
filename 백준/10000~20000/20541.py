import sys
import heapq

input = sys.stdin.readline

def count(album):
    al = 1
    pic = len(album[1])
    for i,j in album[0].items():
        temp_al,temp_pic = count(album[0][i])
        al+=temp_al
        pic+=temp_pic
    return al, pic

n = int(input().strip())
d = [{},{},'','album',[],[],[],[]]      # 앨번, 사진, 부모
cur = d
for i in range(n):
    man, file_name = input().strip().split()
    if(man == 'mkalb'):
        if not(file_name in cur[0]):
            cur[0][file_name] = [{},{},cur,file_name,[],[],[],[]]
            temp_arr = [0]*20
            for i in range(len(file_name)):
                temp_arr[i] = ord(file_name[i])*-1
            heapq.heappush(cur[4],file_name)
            heapq.heappush(cur[5],[temp_arr,file_name])
        else:
            print('duplicated album name')
    elif(man=='rmalb'):
        if(file_name == '-1'):
            al = 0
            pic = 0
            while(cur[4]):
                if not (cur[4][0] in cur[0]):
                    heapq.heappop(cur[4])
                else:
                    break
            while(cur[5]):
                if not (cur[5][0][1] in cur[0]):
                    heapq.heappop(cur[5])
                else:
                    break
            if cur[4]:
                small = heapq.heappop(cur[4])
                al,pic = count(cur[0][small])
                del cur[0][small]
            print(al, pic)
        elif(file_name == '0'):
            al = 0
            pic = 0
            for i,j in cur[0].items():
                temp_al, temp_pic = count(cur[0][i])
                al+=temp_al
                pic+=temp_pic
            print(al, pic)
            cur[0] = {}
            cur[4] = []
            cur[5] = []
        elif(file_name == '1'):
            al = 0
            pic = 0
            while(cur[4]):
                if not (cur[4][0] in cur[0]):
                    heapq.heappop(cur[4])
                else:
                    break
            while(cur[5]):
                if not (cur[5][0][1] in cur[0]):
                    heapq.heappop(cur[5])
                else:
                    break
            if cur[5]:
                big = heapq.heappop(cur[5])
                al,pic = count(cur[0][big[1]])
                del cur[0][big[1]]    
            print(al, pic)
        else:
            al = 0
            pic = 0
            if file_name in cur[0]:
                al,pic = count(cur[0][file_name])
                del cur[0][file_name]
            print(al, pic)
    elif(man == 'insert'):
        if not (file_name in cur[1]):
            cur[1][file_name]=1
            temp_arr = [0]*20
            for i in range(len(file_name)):
                temp_arr[i] = ord(file_name[i])*-1
            heapq.heappush(cur[6],file_name)
            heapq.heappush(cur[7],[temp_arr,file_name])
        else:
            print('duplicated photo name')
    elif(man == 'delete'):
        if file_name == '-1':
            pic = 0
            while(cur[6]):
                if not (cur[6][0] in cur[1]):
                    heapq.heappop(cur[6])
                else:
                    break
            while(cur[7]):
                if not (cur[7][0][1] in cur[1]):
                    heapq.heappop(cur[7])
                else:
                    break
            if cur[6]:
                small = heapq.heappop(cur[6])
                pic += 1
                del cur[1][small]
            print(pic)
        elif file_name == '0':
            print(len(cur[1]))
            cur[1] = {}
            cur[6] = []
            cur[7] = []
        elif file_name == '1':
            pic = 0
            while(cur[6]):
                if not (cur[6][0] in cur[1]):
                    heapq.heappop(cur[6])
                else:
                    break
            while(cur[7]):
                if not (cur[7][0][1] in cur[1]):
                    heapq.heappop(cur[7])
                else:
                    break
            if cur[7]:
                big = heapq.heappop(cur[7])
                pic += 1
                del cur[1][big[1]]
            print(pic)
        else:
            if file_name in cur[1]:
                print(1)
                del cur[1][file_name]
            else:
                print(0)
    elif(man == 'ca'):
        if(file_name == '..'):
            if cur[2] == '':
                print(cur[3])
                continue
            cur = cur[2]
            print(cur[3])
        elif(file_name == '/'):
            cur = d
            print(cur[3])
        else:
            if file_name in cur[0]:
                cur = cur[0][file_name]
            print(cur[3])