import numpy as np

T = int(raw_input())

for i in range(T):
	N,K = map(int, raw_input().split())
	words = raw_input().split()

	arr = []

	for k in range(K):
		arr2 = raw_input().split()
		L = int(arr2[0])
		arr2 = arr2[1:]
		arr += arr2

	output = ""
	for word in words:
		if word in arr:
			output += "YES "
		else:
			output += "NO " 

	print output