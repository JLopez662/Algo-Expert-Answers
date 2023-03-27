# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def removeDuplicatesFromLinkedList(linkedList):
    # Write your code here.
    CurNode = linkedList
    BeginNode = CurNode
    
    while (CurNode.next != None):
        DupNode = CurNode.next
        if(CurNode.value == DupNode.value):
            CurNode.next = DupNode.next
        else:
            CurNode = DupNode

    return BeginNode