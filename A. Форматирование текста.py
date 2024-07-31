inp = input()

arr = inp.replace(',', ' , ').split(" ")
arr = [item for item in arr if item != '']

max_len = len(max(arr, key=len)) * 3
cur_len = 0
idx = 0
res = ['']
rid = 0

while idx < len(arr):
    if idx + 1 < len(arr) and arr[idx + 1] == ',':
        if len(res[rid]) + len(arr[idx]) + 1 <= max_len: 
            res[rid] += arr[idx] + ','
            idx+=1
            if(len(res[rid]) < max_len):
                res[rid] += ' '
        else:
            res.append('')
            rid += 1
            res[rid] += arr[idx] + ', '
            idx += 1
    elif len(res[rid]) + len(arr[idx]) <= max_len:
        res[rid] += arr[idx]
        if(len(res[rid]) < max_len):
            res[rid] += ' '
    else:
        res.append('')
        rid += 1
        res[rid] += arr[idx] + ' '
    idx+=1
  

for item in res:
    print(item.strip())




