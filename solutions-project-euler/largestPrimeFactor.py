import math

def is_prime(n):
	for i in range(2, int(math.sqrt(n)+1)):
		if (n%i == 0):
			return False
	return True

out = 2
num = 600851475143 
for i in range(2, num):
	if (num%i == 0):
		if(is_prime(num/i)):
			out = num/i
			break
print(out)
