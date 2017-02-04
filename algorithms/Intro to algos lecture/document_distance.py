import urllib
url1 = "http://blog.hackerrank.com/the-history-of-hello-world/"
url2 = "https://en.wikipedia.org/wiki/%22Hello,_World!%22_program"

# Loading the documents
doc1 = urllib.urlopen(url1).read()
doc2 = urllib.urlopen(url2).read()

# Getting just words from the documents - Time : O(|doc1| + |doc2|)
import re
words1 = re.findall("\w+",doc1)
words2 = re.findall("\w+", doc2)

# forming count dictionary - Time : O(k1 + k2)
dict1 = {}
dict2 = {}

for word in words1:
	dict1[word] = dict1.get(word,0) + 1

for word in words2:
	dict2[word] = dict2.get(word,0) + 1

# Finding dot product  - Time : O(k1+k2)  - k1 is number of words in doc 1
dot_dict = {}
for word1 in dict1.keys():
	if dot_dict.get(word1, -1) < 0:
		dot_dict[word1] = dict1[word1]*dict2.get(word1, 0) 

dot_product = 0
for vals in dot_dict.values():
	dot_product += vals

# Finding angle
import numpy as np 
doc1_vector = np.array(dict1.values())
doc2_vector = np.array(dict2.values())
doc1_mag = np.sqrt(np.sum(doc1_vector**2))  
doc2_mag = np.sqrt(np.sum(doc2_vector**2))
cossine = dot_product/(doc1_mag*doc2_mag)


if __name__ == "__main__":
	print len(words1), len(words2)
	print cossine
