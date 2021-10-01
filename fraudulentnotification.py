from bisect import bisect_left, insort_left
 
 
def activityNotifications(expenditure, d):
    warnings = 0
     
    running_median = sorted(expenditure[:d])
    for i,ele in enumerate(expenditure):
        if i < d:
            continue
                             
        if d % 2 == 1:
            median = running_median[d//2]
        else:
            median = (running_median[d//2 - 1] + running_median[d//2])/float(2)
             
        if ele >= median*2:
            warnings += 1
             
        # remove previous element
        del running_median[bisect_left(running_median, expenditure[i-d])]
         
        # add new element
        insort_left(running_median, ele)
 
    return warnings
