from level_order import node
from construction import display
import numpy as np 


class queue:
	def __init__(self):
		self.array = []
		self.top = -1

	def push(self, head):
		self.top += 1
		if len(self.array) == 0:
			self.array.append(head)
		else:
			self.array[self.top] = head

	def front(self):
		if self.top < 0:
			print "Queue is empty"
		else:
			return self.array[self.top]

	def pop(self):
		if self.top>=0:
			self.top-= 1
		else:
			print "Queue is empty"

	def empty(self):
		if self.top < 0:
			return True
		else:
			return False

def level_order_traversal(head):
	q1 = queue()
	q1.push(head)
	while q1.empty() == False:
		
		temp = q1.front()
		print temp.data
		q1.pop()
		if temp.left != None:
			q1.push(temp.left)
		if temp.right != None:
			q1.push(temp.right)
		print q1.top

if __name__ == "__main__":
	head = node(10)
	head.left = node(6)
	head.right = node(14)
	head.left.right = node(8)
	head.right.right = node(18)
	level_order_traversal(head)
