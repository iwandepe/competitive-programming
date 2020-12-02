from math import sqrt

def is_prime(n):
	for i in range(2, int(sqrt(n))+1):
		if n%i == 0:
			return False
	return True

def gen_prime(n):
	total = 0
	for i in range(2, n+1):
		if (is_prime(i)):
			total += i
			print(i)
	print(total)
gen_prime(2000000)
