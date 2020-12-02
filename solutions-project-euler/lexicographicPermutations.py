from itertools import permutations
perm = permutations(['0','1','2','3','4','5','6','7','8','9'])
count = 1
for i in list(perm):
	if count == 1000000:
		print (''.join(list(i)))
	count += 1
