total = [2]
for i in range(999):
	temp = 0
	for j in range(len(total)):
		temp = total[j] + total[j] + temp 
		total[j] = temp%10
		temp = temp // 10
	
	if temp > 0:
		total.append(temp)
		
print(sum(total))
