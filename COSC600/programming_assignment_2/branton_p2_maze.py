import numpy as np


def read_input(filename):
    input_array = []
    with open(filename, "r") as f:
        for line in f.readlines():
            line_arr = []
            if line[-1:] == "\n": # remove endline characters
                line = line[0:-1]
            for elem in line:
                if elem != "":
                    line_arr.append(str(elem))
            input_array.append(line_arr)
    return np.array(input_array)  



def traverse_maze(maze_array, start_row, start_col):
    print("Traversing Maze...")

    # Handle special cases
    if (start_row < 0) or (start_row >= len(maze_array)): # check if start row is in bounds
        maze_state = "Error: Starting row out of maze bounds. Returning input maze."
        return maze_array, maze_state

    elif (start_col < 0) or (start_col >= len(maze_array[0])): # check if start col is in bounds
        maze_state = "Error: Starting column out of maze bounds. Returning input maze."
        return maze_array, maze_state

    elif maze_array[start_row,start_col] == "E":
        maze_state = "I am free! (Started at the exit)"
        return maze_array, maze_state

    #Initialize Maze
    maze_array[start_row, start_col] = "S"

    current_row = start_row
    current_col = start_col

    traversing = True

    move_stack = [] # python list data structure has stack functionality

    while traversing:
        # Examine the four adjacent squares and push 0 or E
        adjacent_squares = [[current_row+1, current_col],
                            [current_row, current_col+1],
                            [current_row-1, current_col],
                            [current_row, current_col-1]]
        
        for square in adjacent_squares:
            if (square[0] >= 0) and (square[0] < len(maze_array)): # check if row index is in bounds
                if (square[1] >= 0) and (square[1] < len(maze_array[0])): # check if col index is in bounds
                    if (maze_array[square[0], square[1]] == '0') or (maze_array[square[0], square[1]] == 'E'):
                        move_stack.append(square)

        #Move by popping one square from the stack
        try:
            move_square = move_stack.pop()

            if maze_array[move_square[0],move_square[1]] == 'E':
                maze_state = "I am free!"
                traversing=False
            else:
                maze_array[move_square[0],move_square[1]] = '+'

            #update the current row/col
            current_row = move_square[0]
            current_col = move_square[1]

        except IndexError:
            maze_state = "Help, I am trapped."
            traversing = False


    return maze_array, maze_state



if __name__ == "__main__":
    #Grab a row and column from the user to start the maze in
    starting_row = int(input("Please input an integer starting row (zero-indexed):"))
    starting_col = int(input("Please input an integer starting column (zero-indexed):"))

    maze_array = read_input("maze.txt")


    traversed_maze, maze_state = traverse_maze(maze_array,starting_row, starting_col)

    print(maze_state)
    for row in traversed_maze:
        print(' '.join(row))

