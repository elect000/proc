from sys import stdin

def create_tree (mytree) :
    for i in range(2, 1001):
        temp = 0
        for j in range(0, i):
            temp +=  mytree[j] * mytree[(i - 1) - j]
        mytree.append(temp)
    return mytree

if __name__ == '__main__':
    myTree = create_tree([1, 1])
    for a in stdin:
        print (myTree[int(a)])
