from sys import stdin, stdout

def get_ints():
	return map(float, stdin.readline().strip().split())

n = int(stdin.readline())

#n = int(input())

QALY = 0.0
for _ in range(n):

	a,b = get_ints()

	#a,b = list(map(float, input().strip().split()))
	QALY += a*b

stdout.write("{:.3f}\n".format(QALY))

#print("{:.3f}\n".format(QALY))
