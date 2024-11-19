from data_structures.helper.node import Node


class NodeStack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, item):
        node = Node(item)
        node.next = self.head

        self.head = node
        self.size += 1

    def pop(self):
        top = self.head
        # del top

        popped_value = top.value
        self.head = top.next
        self.size -= 1

        return popped_value

    def peek(self):
        return self.head.value

    def is_empty(self):
        return self.size == 0 or self.head is None


stack = NodeStack()

stack.push(1337)
stack.push(90)
stack.push(88)
stack.push(10202)

print("Pop: ", stack.pop())
print("Peek", stack.peek())