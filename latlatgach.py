F = [0 for i in range(101)]
F[0] = 1
F[1] = 1
for i in range(2, 101):
    F[i] = F[i-1] + F[i-2]

ntest = int(input())
for test in range(ntest):
    n = int(input())
    print(F[n])
