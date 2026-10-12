# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = nextclass Solution:# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        dummy = ListNode(-1)
        current = dummy
        
        h1 = list1
        h2 = list2
        
        while h1 is not None and h2 is not None:
            if h1.val < h2.val:
                current.next = h1
                h1 = h1.next
            else:
                current.next = h2
                h2 = h2.next
            current = current.next
            
        if h1 is not None:
            current.next = h1
        else:
            current.next = h2
            
        return dummy.next