sum = 1
F = [1] * 16

for i in range(1, 16):
    F[i] = sum * 2 + F[i-1]
    sum += F[i]

while True:
    n = int(input())
    if n == -1:
        break
    if n % 2 == 1:
        print(0)
    else:
        print(F[n // 2])
