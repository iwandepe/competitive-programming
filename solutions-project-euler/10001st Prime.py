from math import sqrt

prime_list = []

def is_prime(n):
	for i in prime_list:
		if n%i == 0:
			return False
	
	return True

def gen_prime(n):
	counter = 0
	num = 2
	while True:
		if (is_prime(num)):
			prime_list.append(num)
			counter += 1
			
		if counter == n:
			return num
			break
		num += 1
		
gen_prime(10001)
print(prime_list[-1])

