from collections import defaultdict

success = 1
fail = 0

class Node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

# delete , insert, search, print, insert last, insert before
class LinkedList:
    def __init__(self):
        self.head = None

    def makeNode(value, next):
        node = Node(value, next)
        return node

    def isEmpty(self):
        if self.head is None:
            print("List is empty")
            return True
        return False

    def search(self, target):
        if self.isEmpty():
            print("Nothing to search")
            return fail

        temp = self.head
        while temp is not None:
            if temp.val == target:
                return temp
            temp = temp.next

        if temp is None:
            print("Not in list")

        return None
    # 1 2 3 4 5
    def searchBefore(self, target):
        # last element is not returned
        if self.isEmpty():
            print("Nothing to search")
            return fail

        if self.head.val == target:
            return None

        temp = self.head
        while temp.next is not None:
            if temp.next.val == target:
                return temp
            temp = temp.next

        print("Not in list")
        return fail

    def insertFirst(self, value):
        node = Node(value)

        if self.isEmpty():
            self.head = node
            return success

        node.next = self.head
        self.head = node
        return success

    def insertLast(self, value):
        node = Node(value)

        if self.isEmpty():
            self.head = node
            return success

        temp = self.head
        while temp.next is not None:
            temp = temp.next

        temp.next = node
        return success

    def insertAfter(self, value, target):
        if self.isEmpty():
            print("Nothing to search")
            return fail

        targetNode = self.search(target)

        node = Node(value)
        node.next = targetNode.next
        targetNode.next = node

        return success

    def insertBefore(self, value, target):
        if self.isEmpty():
            print("Nothing to search")
            return fail
        # 1 2 3 5
        node = Node(value)
        targetNode = self.searchBefore(target)

        # in case of before head
        if targetNode is fail:
            print("Nothing to search")
            return fail

        if targetNode is None:
            node.next = self.head
            self.head = node
            return success

        node.next = targetNode.next
        targetNode.next = node

        return success

    def delete(self, target):
        if self.isEmpty():
            print("Nothing to delete")
            return fail

        targetNode = self.searchBefore(target)
        if targetNode == fail:
            print("Nothing to delete")
            return fail

        if targetNode is None:
            self.head = self.head.next
            return success

        targetNode.next = targetNode.next.next
        return success

    def deleteLast(self):
        if self.isEmpty():
            print("Nothing to delete")
            return fail

        temp = self.head
        prev = None

        if temp.next == None:
            self.head = None
            return success

        while temp.next is not None:
            prev = temp
            temp = temp.next

        prev.next = None
        return success

    def removeDuplicateUnsorted(self):
        if self.isEmpty():
            print("List is empty, nothing to remove")
            return
        if self.head.next is None:
            return

        keys = set()
        prev = self.head
        temp = prev.next
        keys.add(prev.val)

        while temp:
            if temp.val not in keys:
                keys.add(temp.val)
                prev.next = temp
                prev = temp

            temp = temp.next

        prev.next = None

    # 0 = > 1 = > 1 = > 1 = > 2 = > 3 = > 4 = > 5 = > 5 = > 6

    def removeDuplicateSorted(self):
        if self.isEmpty():
            return
        if self.head.next is None:
            return

        prev = self.head
        temp = prev.next

        while temp:
            if prev.val == temp.val:
                prev.next = temp.next
                temp.next = None
            else:
                prev = temp
            temp = temp.next
            # if prev.val != temp.val:
            #     prev = temp
            # temp = temp.next

        prev.next = None

    def reverse(self):
        if self.isEmpty():
            return None
        if self.head.next is None:
            return self.head

        # 1 2 3 4 5
        prev = None
        while self.head:
            temp = self.head.next
            self.head.next = prev
            prev = self.head
            self.head = temp

        self.head = prev

def printList(head):
    if head is None:
        return fail

    while head:
        print(head.val, end="=>")
        head = head.next

    print()
    return success
# 1 2 3 4 5
def reverse(node):
    if node is None:
        return None

    if node.next is None:
        return node

    new_head = reverse(node.next)
    node.next.next = node
    node.next = None
    return new_head

def main():
    ll = LinkedList()
    ll.insertFirst(2)
    ll.insertFirst(1)
    ll.insertLast(4)
    ll.insertBefore(3, 4)
    ll.insertAfter(6, 4)
    ll.insertBefore(0, 1)
    ll.insertBefore(5, 6)
    # printList(ll.head)
    # ll.reverse()

    ll.insertBefore(5, 5)
    ll.insertBefore(1, 1)
    ll.insertBefore(1, 1)

    printList(ll.head)

    ll2 = LinkedList()
    ll2.head = reverse(ll.head)
    printList(ll2.head)

    ll2.reverse()
    printList(ll2.head)

if __name__ == "__main__":
    main()