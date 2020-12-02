single_num = 1
triangle_num = 0
while True:
	triangle_num += single_num
	div = 1
	factors = 0
	while div <= triangle_num:
		if triangle_num%div == 0:
			if div > triangle_num/div:
				break
			if div == triangle_num/div:
				factors += 1
				break
			factors += 2
		div += 1
	print(factors)
	if factors >= 500:
		print(triangle_num)
		break
	single_num += 1
