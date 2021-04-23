import numpy as np
from collections import deque

#Josephus Problem

n_soldiers = int(input("How many soldiers?"))

print("Type {} soldiers names:".format(n_soldiers))
soldiers = []
for i in np.arange(1,n_soldiers+1):
    soldiers.append(input())

soldiers = np.array(soldiers)
#using the deque object from collections as implementation of a circular queue
circular_queue = deque(soldiers, maxlen=n_soldiers)

position = int(input("Enter the position: "))

print("Eliminating Order: ")
while len(circular_queue) > 1:
    circular_queue.rotate(-1*position) # -1 to rotate to the left
    eliminated = circular_queue.pop()
    index = np.where(soldiers == eliminated)[0][0] + 1
    print("{} ({})".format(eliminated, index))

survivor = circular_queue.pop()
index = np.where(soldiers == survivor)[0][0] + 1
print("The Survivor is {} ({}) ".format(survivor, index)) 