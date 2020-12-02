tot = 0
for i in range(1,101):
	for j in range(i+1,101):
		if (i != j):
			tot += (i*j) * 2
print(tot)
