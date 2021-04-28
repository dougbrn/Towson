import numpy as np

class Node_AVL():
    #Initialize an AVL node, has a val, depth, height, balance, left child, and right child
    def __init__(self, val=None, depth=0,height=0):
        self.val = val
        self.depth = depth
        self.height = height
        self.left = None
        self.right = None

class AVL_Tree():

    def findBalance(self, root):
        # The balance of a node is defined as the height of the left subtree - the height of the right subtree
        # Should be in {-1,0,1} or a rebalance is needed
        if not root.left:
            left_height = -1 # An empty node has height of -1
        else:
            left_height = root.left.height
        if not root.right:
            right_height = -1 # An empty node has height of -1
        else:
            right_height = root.right.height 
        return left_height - right_height

    def findHeight(self,root):
        #The height of a node is the maximum of {left tree height, right tree height} + 1
        if not root.left:
            left_height = -1 # An empty node has height of -1
        else:
            left_height = root.left.height
        if not root.right:
            right_height = -1 # An empty node has height of -1
        else:
            right_height = root.right.height 
        return max(left_height,right_height) + 1

    def updateDepths(self,root,dist_from_root=0):
        # update depths for all children of a node
        # needed for when rotations occur
        if root.val is not None:
            root.depth = dist_from_root
        if root.left is not None: 
            self.updateDepths(root.left,dist_from_root+1)
        if root.right is not None:
            self.updateDepths(root.right,dist_from_root+1)

        return root

    def insert(self, root, key,depth=0):
     
        # Insert node into proper place in AVL tree
        if not root:
            return Node_AVL(key,depth=depth)

        elif key < root.val:
            depth+=1
            root.left = self.insert(root.left, key,depth=depth)
        else:
            depth+=1
            root.right = self.insert(root.right, key,depth=depth)
 
        # Update the node heights after insertion and check for balance
        root.height = self.findHeight(root)
        balance = self.findBalance(root)
 
        # Do AVL Tree Balance Resolution
        # 4 Cases:
        #Case 1 - Left Left
        #Right Rotation
        if balance > 1 and key < root.left.val:
            return self.right_rotate(root)
        #Case 2 - Left Right
        #Left Rotation -> Right Rotation
        if balance > 1 and key > root.left.val:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        #Case 3 - Right Right
        #Left Rotation
        if balance < -1 and key > root.right.val:
            return self.left_rotate(root)

        #Case 4 - Right Left
        # Right Rotation -> Left Rotation
        if balance < -1 and key < root.right.val:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)
 
        return root

    def right_rotate(self,z):
        # z is the root node of the rotation
        y = z.left
        T3 = y.right

        # Perform a right rotation
        y.right = z
        z.left = T3

        z.height = self.findHeight(z)
        y.height = self.findHeight(y)

        return y

    
    def left_rotate(self,z):
        # z is the root node of the rotation
        y = z.right
        T2 = y.left

        #Perform a left rotation
        y.left = z
        z.right = T2

        z.height = self.findHeight(z)
        y.height = self.findHeight(y)

        return y

    def traverse(self, root, order, val_list=[]):
        # Order is one of inorder, preorder, or postorder
        if order == 'preorder':
            if root.val is not None:
                val_list.append(root.val)
            if root.left is not None:
                self.traverse(root.left,'preorder',val_list)
            if root.right is not None:
                self.traverse(root.right,'preorder',val_list)
        elif order == 'inorder':
            if root.left is not None:
                self.traverse(root.left,'inorder',val_list)
            if root.val is not None:
                val_list.append(root.val)
            if root.right is not None:
                self.traverse(root.right,'inorder',val_list)
        elif order == 'postorder':
            if root.left is not None:
                self.traverse(root.left,'postorder',val_list)
            if root.right is not None:
                self.traverse(root.right,'postorder',val_list)
            if root.val is not None:
                val_list.append(root.val)
        else:
            print("Not a valid traversal order: inorder, preorder, postorder")
        return val_list
    
    def get_depths(self,root,depths=[]):
        if root.val is not None:
            depths.append(root.depth)
        if root.left is not None:
            self.get_depths(root.left,depths)
        if root.right is not None:
            self.get_depths(root.right,depths)
        return depths

    def calc_avg_depth(self, root):
        depths = self.get_depths(root,[])
        #print(depths)
        return np.mean(depths)

if __name__ == "__main__":
    n=5000
    #np.random.seed(0) #set a seed for testing sake
    rand_ints = np.random.randint(0,50000,n)
    #print(rand_ints)
    AVL = AVL_Tree()
    root = None
    for rand_int in rand_ints:
        root = AVL.insert(root, rand_int)
        root = AVL.updateDepths(root) #needed for depth information
    #print(AVL.traverse(root,'preorder',[]))
    avg_depth = AVL.calc_avg_depth(root)
    print(f"Average Depth of AVL Tree (n={n}): {avg_depth}")