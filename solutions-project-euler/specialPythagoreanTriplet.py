from itertools import combinations_with_replacement

num = [i for i in range(1,999)]
all_comb = combinations_with_replacement(num, 3)
comb_1000 = []
for x in all_comb:
	if sum(x) == 1000:
		comb_1000.append(x)
		if x[0]**2 + x[1]**2 == x[2]**2:
			print(x[0]*x[1]*x[2])
			#print(x)
			break;
			
#print(200 * 375 * 425)
