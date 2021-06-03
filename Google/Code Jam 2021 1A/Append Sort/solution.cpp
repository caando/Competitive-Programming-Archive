t = int(input())

for T in range(t):

	n = int(input())
	line = input().split()
	arr = []
	for i in range(n):
		temp = int(line[i])
		arr.append(temp)

	count = 0

	for i in range(1, n):
		mul = 1
		add = 0
		while (arr[i] * mul + add <= arr[i-1]):
			if (arr[i-1] + 1 - arr[i] * mul < mul):
				add = arr[i-1] + 1 - arr[i] * mul
			else:
				mul = mul * 10
				add = 0
				count += 1
		arr[i] = arr[i] * mul + add
	print("Case #"+str(T+1) + ":", count)

