f = open('largest product in a series.txt', 'r')
line_list = f.read().strip().split()
nums = []
product = 1
largest = 1

for line in line_list:
	nums += list(map(int, list(line)))

for i in range(13):
	largest *= nums[i]

product = largest
for i in range(13, len(nums)-13):
	product = 1
	for p in range(i+1, i+14):
		product *= nums[p]
			
	if product > largest:
		largest = product 
print(largest)
f.close()
