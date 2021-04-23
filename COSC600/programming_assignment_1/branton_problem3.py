from timeit import default_timer as timer
import numpy as np

def read_input(filename):
    input_array = []
    with open(filename, "r") as f:
        for line in f.readlines():
            if line[-2:] == "\n": # remove endline characters
                line = line[0:-2]
            for elem in line.split(" "):
                if elem != "":
                    input_array.append(int(elem))
    return input_array     

# Method 1 ( O(N^2) algorithm): Write a program to have two loops 
# and keep track of maximum count for all different elements.  
# If maximum count becomes greater than N/2 then break the loops and 
# return the element having maximum count.  If maximum count doesn’t 
# become more than N/2 then majority element doesn’t exist
def majority_elem_alg1(input_array):
    count_dict = {} #dictionary for counting occurences
    n_elements = len(input_array)

    if n_elements == 1:
        return input_array[0]
    for elem in input_array:
        if str(elem) in count_dict.keys():
            count_dict[str(elem)] +=1
            if count_dict[str(elem)] > n_elements/2:
                return elem
        else:
            count_dict[str(elem)] = 1
    return "No majority element found"

# Method  2  (O(NlogN)  algorithm  using  a  divided-and-conquer  method.      
# The algorithm  begins  by  splitting  the  array  in  half  repeatedly  
# and  calling  itself  on  each  half.  When we get down to single elements, 
# that single element is returned as the majority of its (1-element)  array.    
# At  every  other  level,  it  will  get  return  values  from  its  two  recursive calls.
def majority_elem_alg2(input_array, start, end):
    n = end-start

    if n == 1:
        return input_array[start]

    k = n//2

    elemlsub = majority_elem_alg2(input_array, start, start+k)
    elemrsub = majority_elem_alg2(input_array, start+k, end)

    if elemlsub == elemrsub:
        return elemlsub

    lcount = 0
    for elem in input_array[start:end]:
        if elem == elemlsub:
            lcount += 1
    
    rcount = 0
    for elem in input_array[start:end]:
        if elem == elemrsub:
            rcount += 1

    if lcount > k:
        return elemlsub
    elif rcount > k:
        return elemrsub
    else:
        return "No majority element found"

# Method 3 (O(N)) algorithm: This algorithm is a two step process.
# 1.Get an element occurring most of the time in the array.  
# This phase will make sure that if there is a majority element then it will 
# return that only.
# 2.Check if the element obtained from above step is majority element.
def majority_elem_alg3(input_array):
    maj_index = 0
    count = 0

    #Get an element occurring most of the time in the array
    for i in input_array:
        if input_array[maj_index] == i:
            count += 1
        else:
            count -= 1
        if count == 0:
            maj_index = i
            count = 1

    #Check if the element is the majority element
    elem_count = 0
    for i in input_array:
        if input_array[maj_index] == i:
            elem_count += 1
    
    if elem_count > len(input_array)//2:
        return input_array[maj_index]
    else:
        return "No majority element found"

    


print("Array Example 1")
arr1 = read_input("Majex1.txt")
print("------- Algorithm 1 -------")
start = timer()
majelem = majority_elem_alg1(arr1)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)


print("------- Algorithm 2 -------")
start = timer()
majelem = majority_elem_alg2(arr1,0,len(arr1))
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 3 -------")
start = timer()
majelem = majority_elem_alg3(arr1)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("")

print("Array Example 2")
arr2 = read_input("Majex2.txt")
print("------- Algorithm 1 -------")
start = timer()
majelem = majority_elem_alg1(arr2)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 2 -------")
start = timer()
majelem = majority_elem_alg2(arr2,0,len(arr2))
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 3 -------")
start = timer()
majelem = majority_elem_alg3(arr2)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("")

print("Array Example 3")
arr3 = read_input("Majex3.txt")
print("------- Algorithm 1 -------")
start = timer()
majelem = majority_elem_alg1(arr3)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 2 -------")
start = timer()
majelem = majority_elem_alg2(arr3,0,len(arr3))
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 3 -------")
start = timer()
majelem = majority_elem_alg3(arr3)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("")

print("Array Example 4")
arr4 = read_input("Majex4.txt")
print("------- Algorithm 1 -------")
start = timer()
majelem = majority_elem_alg1(arr4)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 2 -------")
start = timer()
majelem = majority_elem_alg2(arr4,0,len(arr4))
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)

print("------- Algorithm 3 -------")
start = timer()
majelem = majority_elem_alg3(arr4)
end = timer()
print("Majority Element:",majelem)
print("Time to Execute (Seconds):" ,end - start)
