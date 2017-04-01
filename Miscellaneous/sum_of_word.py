

def sum_of_month(mon) :
	
	if type(mon) != str:
		print "Enter a string only"
		return -1
	sum = 0
	for i in range(len(mon)):
		sum += int(mon[i])
	return sum


print str(3.5)