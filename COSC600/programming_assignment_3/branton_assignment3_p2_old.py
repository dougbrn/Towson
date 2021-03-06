import numpy as np

class Node_AVL():
    #Initialize an AVL node, has a value, depth, height, balance, left child, and right child
    def __init__(self, value=None, depth=0):
        self.value = value
        self.depth=depth
        self.height = 0
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
            right_height = self.right.height 
        return left_height - right_height

    def findHeight(self):
        #The height of a node is the maximum of {left tree height, right tree height} + 1
        if not self.left:
            left_height = -1 # An empty node has height of -1
        else:
            left_height = self.left.height
        if not self.right:
            right_height = -1 # An empty node has height of -1
        else:
            right_height = self.right.height 
        return max(left_height,right_height) + 1

    def updateDepths(self,dist_from_root=0):
        # update depths for all children of a node
        # needed for when rotations occur
        if self.value is not None:
            self.depth = dist_from_root
        if self.left is not None: 
            self.left.updateDepths(dist_from_root+1)
        if self.right is not None:
            self.right.updateDepths(dist_from_root+1)

    def insert(self, value, depth=0):
        #if root is empty, insert value at root
        if self.value == None:
            self.value = value
            self.height = 0
            self.depth = 0
            return self
        #Do not insert values already in AVL Tree
        elif self.value == value:
            return self

        elif value < self.value:
            depth+=1
            if self.left is None:
                self.left = Node_AVL(value,depth) #insert node to the left
            else:
                self.left.insert(value,depth)
            # Update the node heights after insertion
            self.height = self.findHeight()

        elif value > self.value:
            depth+=1
            if self.right is None:
                self.right = Node_AVL(value,depth) # insert node to the right
            else:
                self.right.insert(value,depth)
            # Update the node heights after insertion
            self.height = self.findHeight()  

        # Check for node balance after insertion
        balance = self.findBalance()

        # Do AVL Tree Balance Resolution
        # 4 Cases:
 
        #Case 1 - Left Left
        #Right Rotation
        if balance > 1 and value < self.left.value:
            print("Case 1")
            return self.right_rotate(self)

        #Case 2 - Left Right
        #Left Rotation -> Right Rotation
        elif balance > 1 and value > self.left.value:
            print("Case 2")
            self.left = self.left_rotate(self.left)
            return self.right_rotate(self)

        #Case 3 - Right Right
        #Left Rotation
        elif balance < -1 and value > self.right.value:
            print("Case 3")
            #import pdb;pdb.set_trace()
            
            return self.left_rotate(self)

        #Case 4 - Right Left
        # Right Rotation -> Left Rotation
        
        elif balance < -1 and value < self.right.value:
            self.right = self.right_rotate(self.right)
            print("Case 4")
            return self.left_rotate(self)

        return self

    def right_rotate(self,z):
        # z is the root node of the rotation
        y = z.left
        T3 = y.right

        # Perform a right rotation
        y.right = z
        z.left = T3

        z.height = z.findHeight()
        y.height = y.findHeight()

        y.updateDepths() #update depth information
        return y

    
    def left_rotate(self,z):
        # z is the root node of the rotation
        y = z.right
        T2 = y.left

        #Perform a left rotation
        y.left = z
        z.right = T2

        z.height = z.findHeight()
        y.height = y.findHeight()

        y.updateDepths()
        #print(y.value)
        return y

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
        print(len(depths))
        return np.mean(depths)

if __name__ == "__main__":
    n=6
    np.random.seed(0) #set a seed for testing sake
    rand_ints = np.random.randint(0,50000,n)
    print(rand_ints)
    AVL = Node_AVL()
    for rand_int in rand_ints:
        AVL = AVL.insert(rand_int)
        print(AVL.traverse('preorder',[]))

    avg_depth = AVL.calc_avg_depth()
    
    print(f"Average Depth of AVL Tree (n={n}): {avg_depth}")

    #import pdb; pdb.set_trace()
        
