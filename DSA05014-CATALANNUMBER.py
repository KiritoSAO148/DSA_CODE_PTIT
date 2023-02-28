C = [0] * 101

def catalan():
    C[1] = 1
    for i in range(2, 101):
        C[i] = (4 * i - 2) * C[i - 1] // (i + 1)

if __name__ == '__main__':
    TC = int(input())
    catalan()
    for t in range(TC):
        n = int(input())
        print(C[n])