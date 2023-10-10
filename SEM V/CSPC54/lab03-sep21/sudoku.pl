% index conversion
get_index(Row, Col, Idx) :- Idx is Row * 9 + Col.
get_col(Idx, Col) :- Col is Idx mod 9.
get_row(Idx, Row) :- Row is Idx div 9.
get_block(Idx, Block) :-
	get_row(Idx, R), get_col(Idx, C),
	Block is (R div 3) * 3 + C div 3.
get_pos(Idx, Row, Col, Block) :-
	get_row(Idx, Row), get_col(Idx, Col), get_block(Idx, Block).

% find the available number with constraints
available(Row, Col, Block, X) :-
	between(1, 9, X),
	not(row_used(Row, X)),
	not(col_used(Col, X)),
	not(block_used(Block, X)).

% initialise the constraints with the original problem
init_cons([], _).

% non-empty element 
init_cons([Num|Remain], Idx) :-
	between(1, 9, Num),
	get_pos(Idx, R, C, B),
	% add the constraints into database
	asserta(row_used(R, Num)), 
	asserta(col_used(C, Num)), 
	asserta(block_used(B, Num)),
	Idx1 is Idx + 1, init_cons(Remain, Idx1).

% skip empty element
init_cons([Num|Remain], Idx) :-
	not(between(1, 9, Num)),
	Idx1 is Idx + 1, init_cons(Remain, Idx1).

% dynamic add/delete constraints
modify_cons(Cons) :- asserta(Cons).
modify_cons(Cons) :- retract(Cons), fail.

% solve
solve_sudoku(Prob, Sol) :-
	init_cons(Prob, 0),
	solve(Prob, Sol, 0).
	
% key procedure
solve([],Sol,_) :- Sol = [].
% skip non-empty element
solve([Num|Remain], Sol, Idx) :-
	between(1, 9, Num),
	Idx1 is Idx + 1, solve(Remain, Sol1, Idx1), Sol = [Num|Sol1].
% enumerate available number
solve([Num|Remain], Sol, Idx) :-
	not(between(1, 9, Num)),
	get_pos(Idx, R, C, B),
	available(R, C, B, X),
	modify_cons(row_used(R, X)), 
	modify_cons(col_used(C, X)), 
	modify_cons(block_used(B, X)),
	Idx1 is Idx + 1, solve(Remain, Sol1, Idx1), Sol = [X|Sol1].

sudoku_solver :-
	readln(Sudoku_prob), 
	solve_sudoku(Sudoku_prob, Sol), 
	forall(member(X, Sol), (write(X), tab(1))), halt.

:- initialization(sudoku_solver).

% sample input: 0 0 5 3 0 0 0 0 0 8 0 0 0 0 0 0 2 0 0 7 0 0 1 0 5 0 0 4 0 0 0 0 5 3 0 0 0 1 0 0 7 0 0 0 6 0 0 3 2 0 0 0 8 0 0 6 0 5 0 0 0 0 9 0 0 4 0 0 0 0 3 0 0 0 0 0 0 9 7 0 0
% sample output: 1 4 5 3 2 7 6 9 8 8 3 9 6 5 4 1 2 7 6 7 2 9 1 8 5 4 3 4 9 6 1 8 5 3 7 2 2 1 8 4 7 3 9 5 6 7 5 3 2 9 6 4 8 1 3 6 7 5 4 2 8 1 9 9 8 4 7 6 1 2 3 5 5 2 1 8 3 9 7 6 4 
