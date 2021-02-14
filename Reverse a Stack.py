fail = 0
success = 1

class Stack:
    def __init__(self, size):
        self.stack = []
        self.maxSize = size

    def isEmpty(self):
        if len(self.stack) == 0:
            return True
        return False

    def isFull(self):
        if len(self.stack) == self.maxSize:
            return True
        return False

    def push(self, item):
        if self.isFull():
            print("Stack Full, can not push")
            return fail

        self.stack.append(item)
        return success

    def pop(self):
        if self.isEmpty():
            print("Stack Empty, can not push")
            return fail

        self.stack.pop()
        return success

    # position is 1 indexed
    def peek(self, position):
        return self.stack[position - 1]

    def count(self):
        return len(self.stack)

    def display(self):
        print(self.stack)

    def top(self):
        return self.stack[len(self.stack) - 1]

def insertAtBottom(stack, item):
    if stack.isEmpty():
        stack.push(item)
    else:
        temp = stack.top()
        stack.pop()
        insertAtBottom(stack, item)
        stack.push(temp)

def reverseStack(stack):
    if not stack.isEmpty():
        temp = stack.top()
        stack.pop()
        reverseStack(stack)
        insertAtBottom(stack, temp)

def reverse(stack, ret):
    if stack.isEmpty():
        return
    temp = stack.top()
    stack.pop()
    ret.push(temp)
    reverse(stack, ret)

def main():
    stack = Stack(10)
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)
    stack.display()
    print(stack.top())
    stack.pop()
    stack.display()

    rev = Stack(10)
    reverse(stack, rev)
    rev.display()

if __name__ == '__main__':
    main()