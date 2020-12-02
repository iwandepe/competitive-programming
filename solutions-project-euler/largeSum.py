f = open('large sum.txt', 'r')
total = list(f.readline().strip())
total = list(map(int, total))
total.reverse()
for i in range(99):
	num = list(f.readline().strip())
	num = list(map(int, num))
	num.reverse()
	temp = 0
	d = 0
	for j in range(50):
		temp = total[d] + num[d] + temp
		total[d] = temp%10
		temp = temp//10
		d += 1
		
	while temp > 0:
		if d == len(total):
			total.append(temp%10)
			temp = temp//10
			d += 1
		else:
			temp = total[d] + temp
			total[d] = temp % 10
			temp = temp//10
			d += 1
			
total.reverse()
total = list(map(str, total))[:10]
print(''.join(total))
f.close()
