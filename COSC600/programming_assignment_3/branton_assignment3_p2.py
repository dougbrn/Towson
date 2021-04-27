import numpy as np

class Node_AVL():
    #Initialize an AVL node, has a value, left child and right child
    def __init__(self, value=None,depth=None):
        self.value = value
        self.depth = depth
        self.left = None
        self.right = None