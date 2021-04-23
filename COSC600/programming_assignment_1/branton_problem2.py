import numpy as np

def magic_square(n):
    n = int(n)
    if (n%2 == 0) or (n < 0):
        return "Invalid Number (only positive odd n)"
    else:
        #Initialize the array
        square_array = np.array([ [0]*n for i in range(n)])
        current_row = 0
        current_col = 0
        for i in range(1,n**2 + 1):
            #Place 1 in the middle of the top row
            if i==1:
                current_row = 0
                current_col = n//2
            else:
                #move up one row and over one column to the right
                current_row -= 1
                current_col += 1

                #If a move takes you above the top row in the j-th column, 
                #move to the bottom of the j-th column and place k+ 1 there.
                if (current_row < 0) and (current_col < n): 
                    current_row = n-1

                #If a move takes you outside to the right of the square in the i-th row, 
                # place k+ 1 in the i-th row at the left side.
                if current_col > n-1:
                    current_col = 0
                
                #If a move takes you to an already filled square or 
                # if you move out of the square at the upper right-hand corner, 
                # place k+ 1 immediately below k.
                if (square_array[current_row][current_col] != 0) or (current_row + 1 == 0 and current_col -1 == n-1):
                    current_row += 2
                    current_col -= 1

            square_array[current_row][current_col] = i
        return square_array

n = input("Enter the size of magic square (positive odd integer): ")
print("Your {} x {} magic square is: ".format(n,n))
print(magic_square(n))