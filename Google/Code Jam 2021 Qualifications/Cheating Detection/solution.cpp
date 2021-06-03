#import matplotlib.pyplot as plt

t = int(input())

percent = input()

for T in range(t):

	data = []
	difficulty = []
	for j in range(10000):
		difficulty.append([0, j])
	for i in range(100):
		line = input()
		for j in range(len(line)):
			if (line[j] == '1'):
				difficulty[j][0] += 1
		data.append(line)


	difficulty.sort()

	high = 0
	index = 0
	#calcs = []
	for i in range(100):
		a, b, c, d, e, count = 0, 0, 0, 0, 0, 1
		for j in range(5000):
			if data[i][difficulty[j][1]] == '1':
				count += 1
				a += j + 1
				b += count
				c += (j+1)*(j+1)
				d += count * count
				e += (j+1) * count
		calc = (count * e -a*b) / max((((count * c - a * a) * (count * d - b*b)) ** (1/2)), 1)
		if (calc * calc > high):
			index = i
			high = calc * calc
	#	calcs.append((calc * calc, i))
	#print(sorted(calcs))
	print("Case #{}: {}".format(T+1, index + 1))

'''
	calcs = []
	a, b, c, d, e, count = 0, 0, 0, 0, 0, 1
	x, y = [], []
	for j in range(5000):
		if data[80][difficulty[j][1]] == '1':
			count += 1
			a += j + 1
			b += count
			c += (j+1)*(j+1)
			d += count * count
			e += (j+1) * count
			x.append(j+1)
			y.append(count)

	plt.plot(x, y, 'ro')
	plt.show()
'''