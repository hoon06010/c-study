import random

rand_list = list(range(10))
random.shuffle(rand_list)

target = rand_list[0]
for element in rand_list[1:]:
    if element - target > 0:
        target = element
    