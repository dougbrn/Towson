import numpy as np

class Node_BST():
    #Initialize a node, has a value, left child and right child
    def __init__(self, value=None,depth=None):
        self.value = value
        self.depth = depth
        self.left = None
        self.right = None
        

    def search(self, search_value):
        #Return when found or if the node is empty
        if (self.value == search_value) or (self.value == None):
            return self
        #Recursively search children
        elif self.value > search_value:
            return self.left.search(search_value)
        else:
            return self.right.search(search_value)

    def insert(self, value, depth=0):
        #if root is empty, insert value at root
        if self.value == None:
            self.value = value
            self.depth = 0
            return
        #Do not insert values already in BST
        elif self.value == value:
            return
        elif value < self.value:
            depth+=1
            if self.left is None:
                self.left = Node_BST(value,depth)
            else:
                self.left.insert(value,depth)
            return
        elif value > self.value:
            depth+=1
            if self.right is None:
                self.right = Node_BST(value,depth)
            else:
                self.right.insert(value,depth)
            return

    def delete(self,val):
        #search for the node to delete
        if val < self.value:
            if self.left:
                self.left = self.left.delete(val)
            return self
        if val > self.value:
            if self.right:
                self.right = self.right.delete(val)
            return self
        
        #End if node doesn't exist
        if self == None:
            return self

        #Replacement, first look at children
        if self.right == None:
            return self.left
        if self.left == None:
            return self.right
        #When node has two children, find maximum of left child
        max_left_child = self.left
        while max_left_child.right:
            max_left_child = max_left_child.right
        self.value = max_left_child.value
        self.left = self.left.delete(max_left_child.value)
        return self
        
        
        
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
    n=5000
    rand_ints = np.random.randint(0,50000,n)
    BST = Node_BST()
    for rand_int in rand_ints:
        BST.insert(rand_int)
    avg_depth = BST.calc_avg_depth()
    print(f"Average Depth of Binary Search Tree (n={n}): {avg_depth}")
