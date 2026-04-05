Upper_Sorted_List = sorted(str(input()).upper())

Count_List = [1]
idx = 0

for i in range(1, len(Upper_Sorted_List)):
    if Upper_Sorted_List[i] == Upper_Sorted_List[i - 1]:
        Count_List[idx] += 1
    else:
        idx += 1
        Count_List.append(1)

max = count = 0
Idx_List = []
for num in Count_List:
    if num == max:
        Idx_List.append(count)
    elif num > max:
        max = num
        Idx_List.clear()
        Idx_List.append(count)
    count += 1

Unique_Upper_Sorted_List = sorted(list(set(Upper_Sorted_List)))
if len(Idx_List) > 1:
    print('?')
else:
    print(Unique_Upper_Sorted_List[Idx_List[0]])

# for word in Upper_Sorted_List[1:]:
#     if Upper_Sorted_List[count] == Upper_Sorted_List[count - 1]:
#         Count_List[idx] += 1
#     else:
#         idx += 1
#         Count_List.append(1)
#     count += 1

# for word in Upper_Sorted_List:
#     if count > 0 and Upper_Sorted_List[count] == Upper_Sorted_List[count - 1]:
#         Count_List[idx] += 1
#     else:
#         idx += 1
#         Count_List.append(1)
#     count += 1