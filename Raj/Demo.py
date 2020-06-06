# create a linked list
# insert in a linked list
# count the length of linked list
# delete a node in a linked list
# get nth node
# get nth node from back
# print the middle of a linked list

#  13 -> 4 -> 5 ->  6 -> 7-> NULL

#
class Node :
    def __init__(self , var):
        self.data = var
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def addAtFront(self, newValue):
        if self.head == None:
            newNode = Node(newValue)
            self.head = newNode
        else :
            newNode = Node(newValue)
            newNode.next = self.head
            self.head = newNode

    def addAtLast(self, newValue):
        if self.head == None:
            self.head = Node(newValue)
        else :

            # 9 -> 13 -> 11-> None
            temp = self.head
            while temp.next != None:
                #moves one step forward
                temp = temp.next

            newNode = Node(newValue)
            temp.next = newNode

    def print(self):
        temp = self.head;
        while temp != None:
            print(temp.data ,end=" -> ")
            temp = temp.next
        print("None")


# 9 -> 2 -> 4 -> 6 -> None
# 9 -> 2 -> 4 -> 6 -> 13 -> None

def main():
    myList = LinkedList();

    myList.addAtFront(6);
    myList.addAtFront(4);
    myList.addAtFront(2);
    myList.addAtFront(9);

    myList.addAtLast(13);

    myList.print()

main()
