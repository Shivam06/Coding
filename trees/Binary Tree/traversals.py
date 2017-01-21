import numpy as np 

class node :
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def traverse(head, type = "in"):
	if head == None:
		return
	if type == "in":
		traverse(head.left,type)
		print head.data
		traverse(head.right, type)

	elif type == "pre":
		print head.data
		traverse(head.right,type)
		traverse(head.left, type)

	elif type == "post":
		traverse(head.left, type)
		traverse(head.right, type)
		print head.data

if __name__ == "__main__":
	head = node(10)
	head.left = node(7)
	head.right = node(13)
	head.left.right = node(9)
	head.right.left = node(11)
	head.right.right = node(15)
	traverse(head)