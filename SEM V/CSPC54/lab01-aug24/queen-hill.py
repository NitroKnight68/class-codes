from random import randint
inf = 10000
N = 6

# Provides starting chessboard
def configureRandomly(board, state):
	for i in range(N):
		state[i] = randint(0, inf) % N
		board[state[i]][i] = 1

# Prints chessboard
def printBoard(board):	
	for i in range(N):
		print(*board[i])

# Prints current state
def printState(state):
	print(*state)
 
# Compares two states
def compareStates(state1, state2):
	for i in range(N):
		if (state1[i] != state2[i]):
			return False
	return True

# Fills entire board with value
def fill(board, value):
	for i in range(N):
		for j in range(N):
			board[i][j] = value

# Returns number of attacking pairs in state
def calculateObjective( board, state):
	attacking = 0
	for i in range(N):
     
        # Queens attacking from left
		row = state[i]
		col = i - 1
		while (col >= 0 and board[row][col] != 1):
			col -= 1
		if (col >= 0 and board[row][col] == 1):
			attacking += 1
   
        # Queens attacking from right
		row = state[i]
		col = i + 1
		while (col < N and board[row][col] != 1):
			col += 1
		if (col < N and board[row][col] == 1):
			attacking += 1
   
        # Queens attacking from top-left
		row = state[i] - 1
		col = i - 1
		while (col >= 0 and row >= 0 and board[row][col] != 1):
			col-= 1
			row-= 1
		if (col >= 0 and row >= 0 and board[row][col] == 1):
			attacking += 1

        # Queens attacking from bottom-right
		row = state[i] + 1
		col = i + 1
		while (col < N and row < N and board[row][col] != 1):
			col+= 1
			row+= 1
		if (col < N and row < N and board[row][col] == 1):
			attacking += 1
   
        # Queens attacking from bottom-left
		row = state[i] + 1
		col = i - 1
		while (col >= 0 and row < N and board[row][col] != 1):
			col -= 1
			row += 1
		if (col >= 0 and row < N and board[row][col] == 1):
			attacking += 1

        # Queens attacking from top-right
		row = state[i] - 1
		col = i + 1
		while (col < N and row >= 0 and board[row][col] != 1):
			col += 1
			row -= 1
		if (col < N and row >= 0 and board[row][col] == 1):
			attacking += 1

	return int(attacking / 2)

# Generate board
def generateBoard(board, state):
	fill(board, 0)
	for i in range(N):
		board[state[i]][i] = 1

# Copies state
def copyState(state1, state2):
	for i in range(N):
		state1[i] = state2[i]

# Gets neighbour with least attacking states
def getNeighbour(board, state):
    
    # Declaring the optimal board
	opBoard = [[0 for _ in range(N)] for _ in range(N)]
	opState = [0 for _ in range(N)]
	copyState(opState, state)
	generateBoard(opBoard, opState)
	opObjective = calculateObjective(opBoard, opState)
 
    # Declaring a temporary neighbour board
	NeighbourBoard = [[0 for _ in range(N)] for _ in range(N)]
	NeighbourState = [0 for _ in range(N)]
	copyState(NeighbourState, state)
	generateBoard(NeighbourBoard, NeighbourState)

    # Iterating through all possible neighbours
	for i in range(N):
		for j in range(N):
      
            # Skips current state
			if (j != state[i]):
				NeighbourState[i] = j
				NeighbourBoard[NeighbourState[i]][i] = 1
				NeighbourBoard[state[i]][i] = 0
				temp = calculateObjective( NeighbourBoard, NeighbourState)
    
                # Checking if temporary is less than optimal
				if (temp <= opObjective):
					opObjective = temp
					copyState(opState, NeighbourState)
					generateBoard(opBoard, opState)
                
                # Backtracking to original configuration
				NeighbourBoard[NeighbourState[i]][i] = 0
				NeighbourState[i] = state[i]
				NeighbourBoard[state[i]][i] = 1
    
    # Copying optimal board to current board
	copyState(state, opState)
	fill(board, 0)
	generateBoard(board, state)

def hillClimbing(board, state):
    
    # Declaring temporary board as current board
	neighbourBoard = [[0 for _ in range(N)] for _ in range(N)]
	neighbourState = [0 for _ in range(N)]
	copyState(neighbourState, state)
	generateBoard(neighbourBoard, neighbourState)
 
	while True:
		copyState(state, neighbourState)
		generateBoard(board, state)
		getNeighbour(neighbourBoard, neighbourState)
  
        # If states are equal, then no optimal neighbour exists
		if (compareStates(state, neighbourState)):
			printBoard(board)
			break

        # If states are not equal, but attacking pairs are equal then it is either a shoulder or local maxima
		elif (calculateObjective(board, state) == calculateObjective( neighbourBoard,neighbourState)):
			neighbourState[randint(0, inf) % N] = randint(0, inf) % N
			generateBoard(neighbourBoard, neighbourState)

state = [0] * N
board = [[0 for _ in range(N)] for _ in range(N)]
configureRandomly(board, state)
hillClimbing(board, state)
