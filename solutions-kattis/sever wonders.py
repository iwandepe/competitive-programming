from collections import Counter
from itertools import combinations
cards = list(input())
score = 0
counter = Counter(cards).most_common()
for card in counter:
	score += card[1]**2
comb = combinations(cards, 3)
while len(set(cards)) > 2:
	set3 = []
	idx = 0
	for i in range(len(cards)):
		if cards[idx] not in set3:
			set3.append(cards[idx])
			cards.pop(idx)
		else:
			idx += 1

		if len(set3) == 3:
			score+=7
			break
print (score)
