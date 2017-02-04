import numpy as np 



def find_peak(arr,start,end):
	mid = (start + end)/2
	if mid > 0 and arr[mid] < arr[mid-1]:
		return find_peak(arr, start, mid-1)
	elif mid<=end-1 and arr[mid] < arr[mid+1]:
		return find_peak(arr, mid+1, end)
	else:
		return arr[mid]

arr = [1,2,3,4,5,6,7]
	
	

if __name__ == "__main__":
	print find_peak(arr,0,len(arr)-1)  # output : 7