Fmin1 = [1]
Fmin2 = [1]

def big_sum():
	global Fmin1, Fmin2
	temp = 0
	d = 0
	for _ in range(len(Fmin2)):
		temp = Fmin1[d] + Fmin2[d] + temp
		Fmin2[d] = Fmin1[d]
		Fmin1[d] = temp%10
		temp = temp//10
		d += 1
	while temp > 0:
		if d < len(Fmin1):
			temp = Fmin1[d] + temp
			Fmin2.append(Fmin1[d])
			Fmin1[d] = temp%10
			temp = temp//10
		else:
			Fmin1.append(temp%10)
			temp = temp//10

index = 3
while True:
	big_sum()
	if len(Fmin1) == 1000:
		print(index)
		break
	index += 1
