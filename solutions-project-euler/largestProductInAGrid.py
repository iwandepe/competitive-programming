f = open('largestProductInAGrid.txt', 'r')
nums = []
largest = 0
for _ in range(20):
	nums.append(list(map(int, list(f.readline().strip().split()))))

for row in range(20):
	for col in range(20):
		right = 1
		down = 1
		diagonalL =1
		diagonalR =1
		
		if col+3 < 20:
			for i in range(4):
				right *= nums[row][col+i]
		if row+3 < 20:
			for i in range(4):
				down *= nums[row+i][col]
		if row+3 < 20 and col+3 <20:
			for i in range(4):
				diagonalL *= nums[row+i][col+i]
		if row > 2 and col+3 < 20:
			for i in range(4):
				diagonalR *= nums[row-i][col+i]
		
		largest=max(right,largest)
		largest=max(down,largest)
		largest=max(diagonalL,largest)
		largest=max(diagonalR,largest)
print(largest)
f.close()
