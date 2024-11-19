class Stack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.top = 0
        self.items = [None] * capacity

    def push(self, item):
        if self.top >= self.capacity:
            raise IndexError('Stack is full')
        else:
            self.items[self.top] = item
            self.top += 1

    def pop(self):
        if self.top == 0:
            raise IndexError('Stack is empty')
        else:
            top = self.items[self.top]
            self.top -= 1
            return top

