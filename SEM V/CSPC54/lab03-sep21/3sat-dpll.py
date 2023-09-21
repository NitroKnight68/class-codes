import sys
from copy import deepcopy

assign_true = set()
assign_false = set()
n_props, n_splits = 0, 0

def solve(cnf, literals):
    new_true = []
    new_false = []
    global assign_true, assign_false, n_props, n_splits
    assign_true = set(assign_true)
    assign_false = set(assign_false)
    n_splits += 1
    cnf = list(set(cnf))
    units = [i for i in cnf if len(i)<3]
    units = list(set(units))
    if len(units):
        for unit in units:
            n_props += 1
            if '!' in unit:
                assign_false.add(unit[-1])
                new_false.append(unit[-1])
                i = 0
                while True:
                    if unit in cnf[i]:
                        cnf.remove(cnf[i])
                        i -= 1
                    elif unit[-1] in cnf[i]:
                        cnf[i] = cnf[i].replace(unit[-1], '').strip()
                    i += 1
                    if i >= len(cnf):
                        break
            else:
                assign_true.add(unit)
                new_true.append(unit)
                i = 0
                while True:
                    if '!'+unit in cnf[i]:
                        cnf[i] = cnf[i].replace('!'+unit, '').strip()
                        if '  ' in cnf[i]:
                            cnf[i] = cnf[i].replace('  ', ' ')
                    elif unit in cnf[i]:
                        cnf.remove(cnf[i])
                        i -= 1
                    i += 1
                    if i >= len(cnf):
                        break

    if len(cnf) == 0:
        return True

    if sum(len(clause)==0 for clause in cnf):
        for i in new_true:
            assign_true.remove(i)
        for i in new_false:
            assign_false.remove(i)
        return False
    literals = [k for k in list(set(''.join(cnf))) if k.isalpha()]

    x = literals[0]
    if solve(deepcopy(cnf)+[x], deepcopy(literals)):
        return True
    elif solve(deepcopy(cnf)+['!'+x], deepcopy(literals)):
        return True
    else:
        for i in new_true:
            assign_true.remove(i)
        for i in new_false:
            assign_false.remove(i)
        return False


def dpll():
    global assign_true, assign_false, n_props, n_splits
    input_cnf = open(sys.argv[1], 'r').read()
    literals = [i for i in list(set(input_cnf)) if i.isalpha()]
    cnf = input_cnf.splitlines()
    if solve(cnf, literals):
        print('\nResult: SATISFIABLE\n')
        print('Solution:')
        for i in assign_true:
            print(' ' + i, '= True')
        for i in assign_false:
            print(' ' + i, '= False')
    else:
        print('\nResult: UNSATISFIABLE')
    print()

if __name__=='__main__':
    dpll()