import numpy as np

class node:
	def __init__(self,data):
		self.left = None
		self.right = None
		self.data = data

def display(head):
	if head == None:
		return
	display(head.left)
	print head.data
	display(head.right)


head = node(10)
head.left = node(5)
head.right = node(14)
head.right.left = node(12)
print "hello"
display(head)