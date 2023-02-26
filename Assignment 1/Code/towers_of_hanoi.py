# Towers of Hanoi game for the graph G = (V,E) with V={S, A1, A2, A3, A4, D} and E={(S,A1), (A1,A2), (A2,A3), (A3,A4), (A4, A1), (A4, D)}

global moves
moves = 0

def move(n, S, D):
    global moves
    moves += 1
    print("Step " + str(moves) + ": Move disk", n, "from", S, "to", D)
    
def hanoiTower(n, S, A1, A2, A3, A4, D):
    if n == 1:
        move(n, S, A1)
        move(n, A1, A2)
        move(n, A2, A3)
        move(n, A3, A4)
        move(n, A4, D)
    else:
        S_to_A4(n - 1, S, A1, A2, A3, A4)
        move(n, S, A1)
        move(n, A1, A2)
        move(n, A2, A3)
        A4_to_A2(n - 1, A4, A3, A2)
        move(n, A3, A4)
        move(n, A4, D)
        A2_to_D(n-1, A2, A3, A4, D)


def S_to_A4(n, S, A1, A2, A3, A4):
    if n == 1:
        move(n, S, A1)
        move(n, A1, A2)
        move(n, A2, A3)
        move(n, A3, A4)
    else:
        S_to_A4(n - 1, S, A1, A2, A3, A4)
        move(n, S, A1)
        move(n, A1, A2)
        move(n, A2, A3)
        A4_to_A2(n - 1, A4, A3, A2)
        move(n, A3, A4)
        A4_to_A2(n - 1, A2, A3, A4)


def A4_to_A2(n, A1, A2, A3):
    if n == 1:
        move(n, A1, A2)
        move(n, A2, A3)
    else:
        A4_to_A2(n - 1, A1, A2, A3)
        move(n, A1, A2)
        A4_to_A2(n - 1, A3, A2, A1)
        move(n, A2, A3)
        A4_to_A2(n - 1, A1, A2, A3)


def A2_to_D(n, A2, A3, A4, D):
    if n == 1:
        move(n, A2, A3)
        move(n, A3, A4)
        move(n, A4, D)
    else:
        A4_to_A2(n - 1, A2, A3, A4)
        move(n, A2, A3)
        A4_to_A2(n - 1, A4, A3, A2)
        move(n, A3, A4)
        move(n, A4, D)
        A2_to_D(n - 1, A2, A3, A4, D)


def main():
    n = int(input("Enter the number of disks: "))
    hanoiTower(n, "S", "A1", "A2", "A3", "A4", "D")
    print("Total moves for " + str(n) + " disks:", moves)
        
    
if __name__ == "__main__":
    main()

# Original problem with 3 pegs
def H(n, A1, A2, A3):
    if n == 0:
        return
    else:
        H(n - 1, A1, A3, A2)
        print(f"Move a disk from {A1} to {A2}")
        H(n - 1, A3, A2, A1)
