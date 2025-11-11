import sys

input = sys.stdin.readline

n = int(input())
tree = {}

for _ in range(n):
    root, left, right = input().split()
    tree[root] = [left, right]

def preorder(root):
    left = tree[root][0]
    right = tree[root][1]
    print(root, end='')
    if left != '.':
        preorder(left)
    if right != '.':
        preorder(right)

def inorder(root):
    left = tree[root][0]
    right = tree[root][1]
    if left != '.':
        inorder(left)
    print(root, end='')
    if right != '.':
        inorder(right)

def postorder(root):
    left = tree[root][0]
    right = tree[root][1]
    if left != '.':
        postorder(left)
    if right != '.':
        postorder(right)
    print(root, end='')

preorder('A')
print('')
inorder('A')
print('')
postorder('A')