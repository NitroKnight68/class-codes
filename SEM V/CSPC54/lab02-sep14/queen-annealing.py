import random
from math import exp
from copy import deepcopy

N_QUEENS = 6
TEMPERATURE = 100

def threat_calculate(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    return (n - 1) * n / 2

def create_board(n):
    chess_board = {}
    temp = list(range(n))
    random.shuffle(temp)
    column = 0

    while len(temp) > 0:
        row = random.choice(temp)
        chess_board[column] = row
        temp.remove(row)
        column += 1
    del temp
    return chess_board

def cost(chess_board):
    threat = 0
    m_chessboard = {}
    a_chessboard = {}

    for column in chess_board:
        temp_m = column - chess_board[column]
        temp_a = column + chess_board[column]
        if temp_m not in m_chessboard:
            m_chessboard[temp_m] = 1
        else:
            m_chessboard[temp_m] += 1
        if temp_a not in a_chessboard:
            a_chessboard[temp_a] = 1
        else:
            a_chessboard[temp_a] += 1

    for i in m_chessboard:
        threat += threat_calculate(m_chessboard[i])
    del m_chessboard

    for i in a_chessboard:
        threat += threat_calculate(a_chessboard[i])
    del a_chessboard

    return threat

def simulated_annealing():
    solution_found = False
    answer = create_board(N_QUEENS)

    cost_answer = cost(answer)

    t = TEMPERATURE
    sch = 0.99   

    while t > 0:
        print(t)
        t *= sch
        successor = deepcopy(answer)
        while True:
            index_1 = random.randrange(0, N_QUEENS - 1)
            index_2 = random.randrange(0, N_QUEENS - 1)
            if index_1 != index_2:
                break
        successor[index_1], successor[index_2] = successor[index_2], \
            successor[index_1]
        delta = cost(successor) - cost_answer
        if delta < 0 or random.uniform(0, 1) < exp(-delta / t):
            answer = deepcopy(successor)
            cost_answer = cost(answer)
        if cost_answer == 0:
            solution_found = True
            print_chess_board(answer)
            break
    if solution_found is False:
        print("Failed")

def print_chess_board(board):
    print('\n')
    for column, row in board.items():
        print("{} -- {}".format(column, row))\

def main():
    simulated_annealing()

if __name__ == "__main__":
    main()