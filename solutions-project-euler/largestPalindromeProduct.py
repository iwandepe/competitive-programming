def palindrom(num):
	for i in range(int(len(num)/2)):
		if(num[i] != num[-i-1]):
			return False
	return True

for i in range(900, 1000):
	for j in range(900, 1000):
		num = ''.join(str(i*j))
		if(palindrom(num)):
			print(i,j,num)
		
