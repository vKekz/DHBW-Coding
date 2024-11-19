class Queue:
    def __init__(self, capacity):
        self.queue = [None] * capacity
        self.head = None
        self.tail = None
