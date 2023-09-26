def get_move(fa: list[list[set[int]]], ip_states: set[int], symbol_index: int) -> set[int]:
    op_states = set()
    for state in ip_states:
        result_states = fa[state][symbol_index]
        if not bool(result_states):
            continue
        op_states = op_states.union(result_states)
    return op_states


def get_epsilon_closure(fa: list[list[set[int]]], ip_states: set[int], epsilon_index: int) -> set[int]:
    result_states = get_move(fa, ip_states, epsilon_index)
    if not bool(result_states):
        return ip_states
    op_states = get_epsilon_closure(fa, result_states, epsilon_index)
    return op_states.union(ip_states)


def nfa_to_dfa(nfa: list[list[set[int]]], initial_state: int, no_of_symbols: int) -> list[list[int]]:
    dfa = []
    dfa_states = list()
    processing_states = list()
    initial_state = get_epsilon_closure(nfa, {initial_state}, 0)
    dfa_states.append(initial_state)
    processing_states.append(initial_state)
    while processing_states:
        states = processing_states.pop(0)
        for symbol_index in range(1, no_of_symbols):
            next = get_move(nfa, states, symbol_index)
            next_states = get_epsilon_closure(nfa, next, 0)
            if not bool(next_states):
                continue
            if next_states not in dfa_states:
                processing_states.append(next_states)
                dfa_states.append(next_states)
            
            source_state = dfa_states.index(states)
            target_state = dfa_states.index(next_states)
            if len(dfa) - 1 < source_state:
                dfa.append([None for _ in range(no_of_symbols)])
            dfa[source_state][symbol_index] = target_state
    return dfa

def print_dfa(dfa: list[list[int]]):
    print("\033[1m" + "\nstate\tepsilon\ta\tb\n" + "\033[0m")
    for index, row in enumerate(dfa):
        print(chr(65 + index), end="\t")
        for col in row:
            letter = chr(65 + col) if col else None
            print(letter, end="\t")
        print("\n")

# symbols: epsilon, letter, digit
identifier_nfa = [
    [{}, {1}, {}],
    [{2, 8}, {}, {}],
    [{3, 5}, {}, {}],
    [{}, {4}, {}],
    [{7}, {}, {}],
    [{}, {}, {6}],
    [{7}, {}, {}],
    [{2, 8}, {}, {}],
    [{}, {}, {}],
]

# symbols: epsilon, symbol, digit, dot, exponent
nfa = [
    [{1, 4, 9}, {}, {}, {}, {}],
    [{2}, {2}, {}, {}, {}],
    [{}, {}, {3}, {}, {}],
    [{}, {}, {3}, {}, {}],
    [{5}, {5}, {}, {}, {}],
    [{}, {}, {6}, {}, {}],
    [{}, {}, {6}, {7}, {}],
    [{}, {}, {8}, {}, {}],
    [{}, {}, {8}, {}, {}],
    [{10}, {10}, {}, {}, {}],
    [{}, {}, {11}, {}, {}],
    [{}, {}, {}, {12}, {}],
    [{}, {}, {13}, {}, {}],
    [{}, {}, {13}, {}, {14}],
    [{15}, {15}, {}, {}, {}],
    [{}, {}, {16}, {}, {}],
    [{}, {}, {16}, {}, {}],
]

# epsilon, a, b
pom_pom = [
    [{1, 4, 5}, {}, {}],
    [{}, {}, {2}],
    [{}, {3}, {}],
    [{}, {}, {3}],
    [{}, {4}, {4}],
    [{}, {}, {6}],
    [{}, {7}, {}],
    [{}, {}, {7}],
]

print_dfa(nfa_to_dfa(pom_pom, 0, 3))