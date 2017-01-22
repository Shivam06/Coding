import numpy as np 

class node:
	def __init__(self,data):
		self.data = data
		self.left = None
		self.right = None

def height(head):
	if head == None:
		return -1
	else:
		return max(height(head.left), height(head.right)) + 1

def print_single_level(head,level):
	if level == 0:
		print head.data
	elif level > 0:
		print_single_level(head.left, level - 1)
		print_single_level(head.right, level - 1)

def level_order_traversal(head):
	for h in range(height(head)+1):
		print_single_level(head, h)

if __name__ == "__main__":
	head = node(10)
	head.left = node(6)
	head.left.left = node(4)
	head.right = node(14)
	head.right.left = node(12)
	head.right.right = node(16)
	head.left.right = node(8)
	level_order_traversal(head)