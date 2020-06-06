# ctrl+B


                                 
myList = [ 24,76,42,97,26,85,97,25,7,97]




#myList[2:5] = [101,102,103]
#print(myList)

#a = [1,2,3]
#myList += a

#print(myList[-(len(myList)):-1:2])


#continue
for i in range(26):

    if (i%4 == 0)  or  (i%5 == 0):
        continue
    
    print(i)



oddList = []
evenList = []
#print(len(myList))


#myList.append(100)

# O(n) = O(len(myList))

for m in myList[::-1]:
    #current_Element = myList[m]

    if m %2 == 1:
        #odd
        oddList.append(m)
    else :
        evenList.append(m)

#print(oddList)
#print(evenList)

to_search = int(input())
found = False
           
           #len = 10
           #0  1  2   3  4  5  6  7  8  9
myList = [ 24,76,42,97,26,85,97,25, 7, 97]

i = len(myList) -1

while i >= 0:
    current_Element = myList[i]
    
    if to_search == current_Element:
        print("Element ",to_search, "found at index : ",i)
        found = True
        break

    i = i-1

if found == False:
    print("No occurence of element ",to_search," was found")




