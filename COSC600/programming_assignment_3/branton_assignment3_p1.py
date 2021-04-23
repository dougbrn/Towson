import numpy as np

class Node_BST():
    #Initialize a node, has a value, left child and right child
    def __init__(self, value=None):
        self.value = value
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

    def insert(self, value):
        #if root is empty, insert value at root
        if self.value == None:
            self.value = value
            return
        #Do not insert values already in BST
        elif self.value == value:
            return
        elif value < self.value:
            if self.left is None:
                self.left = Node_BST(value)
            else:
                self.left.insert(value)
            return
        elif value > self.value:
            if self.right is None:
                self.right = Node_BST(value)
            else:
                self.right.insert(value)
            return

    def delete(self,val):
        pass
        
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

    def calc_avg_depth(self):
        pass
                

if __name__ == "__main__":
    
    rand_ints = np.random.randint(0,50000,10)
    print(rand_ints)
    BST = Node_BST()
    for rand_int in rand_ints:
        BST.insert(rand_int)
    print(BST.traverse('inorder'))