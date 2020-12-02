a,b=1,1
out = 0
while (b<=4000000):
	print(a,b)
	temp = a+b
	if (temp%2 == 0):
		out += temp
	a = b
	b = temp
print(out)
