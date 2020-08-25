
class Node:

    def __init__(self, val):
        self.val = val
        self.rChild = None
        self.lChild = None


class BinaryTree:

    def __init__(self):
        self.root = None

    def insert(self, val):

        if not self.root:
            self.root = Node(val)
        else:
            
            current = self.root
            while True:
                if current.val == val:
                    break
                if val < current.val:
                    if current.lChild:
                        current = current.lChild
                    else:
                        current.lChild = Node(val)
                        break
                if val > current.val:
                    if current.rChild:
                        current = current.rChild
                    else:
                        current.rChild = Node(val)
                        break
            
            



    def delete(self, val):

        # prev[1] indicates either left or right child, 0 left, 1 right
        prev = [None, 0]
        current = self.root
        counter = 0
        while current:

            if counter == 2:
                break

            if current.val == val:

                if not prev[0]:
                    self.root = None
                else:
                    if not current.lChild and not current.rChild:
                        if prev[1]:
                            prev[0].rChild = None
                        else:
                            prev[0].lChild = None
                    elif current.rChild and not current.lChild:
                        if prev[1]:
                            prev[0].rChild = current.rChild
                        else:
                            prev[0].lChild = current.rChild
                    elif current.lChild and not current.rChild:
                        if prev[1]:
                            prev[0].rChild = current.lChild
                        else:
                            prev[0].lChild = current.lChild
                    else:
                        
                        previous = None
                        leftMost = current.rChild

                        while leftMost.lChild:
                            leftMost = leftMost.lChild
                        
                        leftMost.lChild = current.lChild
                        leftMost.rChild = current.rChild
                        if previous:
                            previous.lChild = None
                break
            else:
                prev[0] = current
                if val < current.val:
                    prev[1] = 0
                    current = current.lChild
                else:
                    prev[1] = 1
                    current = current.rChild
                counter += 1

    # Level order traversal
    def print(self):
        
        if not self.root:
            print("Tree is empty")
            return


        queue = []
        queue.append(self.root)

        while queue:
            current = queue.pop(0)

            if current:
                print(current.val)
                if current.lChild:
                    queue.append(current.lChild)
                if current.rChild:
                    queue.append(current.rChild)    