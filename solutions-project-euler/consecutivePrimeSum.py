from math import sqrt

prime_list = []

def is_prime(n):
	for i in range(2,int(sqrt(n))+1):
		if n%i == 0:
			return False
	return True

def gen_prime():
	counter = 2
	while True:
		if is_prime(counter):
			prime_list.append(counter)
		if counter > 1000000:
			break
		counter += 1
gen_prime()
print('start')
prime_len = len(prime_list)
longest_len = 0
longest_prime = 2

for idx in range(prime_len-1, -1, -1):
	prime = prime_list[idx]
	flag = False
	for i in range(prime_len):
		for j in range(i+1, prime_len):
			l = prime_list[i:j+1]
			l_len = len(l)
			if sum(l) == prime:
				if longest_len < l_len:
					print(l_len, prime)
					longest_len = l_len
					longest_prime = prime
					break
			if sum(l) > prime:
				break
		if flag:
			break
print(longest_len, longest_prime)
997651
