#!/usr/bin/python

# apple vs orange
#https://www.youtube.com/watch?v=cKxRvEZd3Mw&list=PLOU2XLYxmsIIuiBfYad6rFYQU_jL2ryal

# CLASSIFIER
# supervised learning
#import sklearn
from sklearn import tree

features = [[140, 1], [130,1], [150,0], [170,0]]
labels   = [0, 0, 1, 1] # 0 apple , 1 orange

# Train a decision tree (box of rules )
clf = tree.DecisionTreeClassifier() # empty decision tree

# Learnning algorithm
clf = clf.fit(features, labels)
print clf.predict([[150,0]])



