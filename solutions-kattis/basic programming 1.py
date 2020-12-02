from sys import stdin

n, t = map(int, stdin.readline().strip().split())
A = list(map(int, stdin.readline().strip().split()))

if(t==1):
	print('7')
elif(t==2):
	if(A[0]>A[1]):
		print('Bigger')
	elif(A[0]==A[1]):
		print('Equal')
	else:
		print('Smaller')
elif(t==3):
	A = A[:3]
	A.sort()
	print(A[1])
elif(t==4):
	print(sum(A))
elif(t==5):
	sum_ = 0
	for i in A:
		if(i%2 == 0):
			sum_ += i
	print(sum_)
elif(t==6):
	print(''.join(chr(97 + i%26) for i in A))
elif(t==7):
	visited = [False]*n
	i = 0
	
	while(True):
		if (i >= n):
			print('Out')
			break
		if(i == n-1):
			print('Done')
			break
		if(visited[i]):
			print('Cyclic')
			break
				
		visited[i] = True
		i = A[i]	
