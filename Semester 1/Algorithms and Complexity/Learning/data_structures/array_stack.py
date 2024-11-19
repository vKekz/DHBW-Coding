class ArrayStack:
    def __init__(self, capacity):
        self.items = [None] * capacity
        self.capacity = capacity
        self.top = 0

    def push(self, item):
        self.items[self.top] = item
        self.top += 1

        self.increase_size()

    def pop(self):
        self.top -= 1
        top_item = self.items[self.top]
        self.items[self.top] = None

        self.decrease_size()

        return top_item

    def peek(self):
        return self.items[self.top - 1]

    def peek_at_index(self, index):
        return self.items[index]

    def is_empty(self):
        return self.top == 0

    def increase_size(self):
        prev_capacity = self.capacity

        # Double the size when full
        if self.top >= self.capacity:
            self.capacity *= 2
            self.copy_old_items(prev_capacity)

    def decrease_size(self):
        prev_capacity = self.capacity

        # Half the size when around 25%
        min_capacity = round(self.capacity * 0.25)
        if self.top < min_capacity:
            self.capacity //= 2
            self.copy_old_items(prev_capacity)

    def copy_old_items(self, prev_capacity):
        # Create empty array with new capacity
        new_items = [None] * self.capacity

        # Copy old items in previous array
        for i in range(prev_capacity):
            old_item = self.items[i]

            if old_item is None:
                continue

            new_items[i] = self.items[i]

        self.items = new_items

stack = ArrayStack(1)

print("Initial:", stack.items)

stack.push(1337)
stack.push(90)
stack.push(88)
stack.push(10202)

print("After push: ", stack.items)

print("Pop: ", stack.pop())
print("Peek", stack.peek())
