import numpy as np

class Node_AVL():
    #Initialize an AVL node, has a value, depth, height, balance, left child, and right child
    def __init__(self, value=None,depth=None,height=None):
        self.value = value
        self.depth = depth
        self.height = height
        self.left = None
        self.right = None

    def findBalance(self):
        # The balance of a node is defined as the height of the left subtree - the height of the right subtree
        # Should be in {-1,0,1} or a rebalance is needed
        if not self.left:
            left_height = -1 # An empty node has height of -1
        else:
            left_height = self.left.height
        if not self.right:
            right_height = -1 # An empty node has height of -1
        else:
            right_height = self.left.height 
        return left - right

    def insert(self, value):
        #if root is empty, insert value at root
        if self.value == None:
            self.value = value
            self.depth = 0
            self.height = 0
            return

    def traverse(self, order, val_list=[]):
        # Order is one of inorder, preorder, or postorder
        if order == 'preorder':
            if self.value is not None:
                val_list.append(self.value)
            if self.left is not None:
                self.left.traverse('preorder',val_list)
            if self.right is not None:
                self.right.traverse('preorder',val_list)
        elif order == 'inorder':
            if self.left is not None:
                self.left.traverse('inorder',val_list)
            if self.value is not None:
                val_list.append(self.value)
            if self.right is not None:
                self.right.traverse('inorder',val_list)
        elif order == 'postorder':
            if self.left is not None:
                self.left.traverse('postorder',val_list)
            if self.right is not None:
                self.right.traverse('postorder',val_list)
            if self.value is not None:
                val_list.append(self.value)
        else:
            print("Not a valid traversal order: inorder, preorder, postorder")
        return val_list
    
    def get_depths(self,depths=[]):
        if self.value is not None:
            depths.append(self.depth)
        if self.left is not None:
            self.left.get_depths(depths)
        if self.right is not None:
            self.right.get_depths(depths)
        return depths

    def calc_avg_depth(self):
        depths = self.get_depths([])
        return np.mean(depths)

if __name__ == "__main__":
    n=10
    rand_ints = np.random.randint(0,50000,n)
    AVL = Node_AVL()
        