year = 1901
month = 1
day = 1

# 1 Jan 1901
day = (day + 365%7) % 7

count_sundays = 0
while year < 2001:
	for i in range(1,13):
		if day == 0:
			count_sundays += 1
		if i == 2:
			if (year%4 == 0 and year%100 != 0) or year%400 == 0:
				day = (day + 29%7) % 7
			else:
				day = (day + 28%7) % 7
		elif i == 4 or i == 6 or i == 9 or i == 11:
			day = (day + 30%7) % 7
		else:
			day = (day + 31%7) % 7
			
	year += 1
		
print(count_sundays)
