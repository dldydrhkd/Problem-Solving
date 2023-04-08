def solution(cap, n, deliveries, pickups):
    answer = 0
    while(len(deliveries) or len(pickups)):
        while(deliveries and deliveries[len(deliveries)-1]==0):
            deliveries.pop()
        while(pickups and pickups[len(pickups)-1]==0):
            pickups.pop()
        del_ = cap
        answer += max(len(deliveries), len(pickups))
        while(deliveries and del_):
            del_temp = deliveries[len(deliveries)-1]
            if del_temp <= del_:
                del_ -= del_temp
                deliveries.pop()
            else:
                deliveries[len(deliveries)-1] -= del_
                del_ = 0
        pickups_ = cap
        while(pickups and pickups_):
            pick_temp = pickups[len(pickups)-1]
            if(pick_temp > pickups_):
                pickups[len(pickups)-1] -= pickups_
                pickups_ = 0
            else:
                pickups_ -= pickups[len(pickups)-1]
                pickups.pop()
    return answer*2
