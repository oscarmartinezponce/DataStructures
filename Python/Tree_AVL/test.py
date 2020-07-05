"""
>>> from tree_avl import TreeAVL

>>> def sum(*args, **kwargs):
...     print(args[0] + kwargs['node'].data)

>>> my_tree = TreeAVL(int)
>>> my_tree.type
<class 'int'>
>>> my_tree.is_empty()
True
>>> my_tree.__len__()
0
>>> my_tree.height()
0
>>> print(my_tree)
<BLANKLINE>
>>> print(my_tree.max())
None
>>> print(my_tree.min())
None
>>> print(my_tree.find(9))
None
>>> print(my_tree.delete(10))
None
>>> my_tree.pre_order(sum, None, 4)
>>> my_tree.in_order(sum, None, 4)
>>> my_tree.pos_order(sum, None, 4)


>>> my_tree.insert(5)
>>> my_tree.is_empty()
False
>>> my_tree.__len__()
1
>>> my_tree.height()
1
>>> print(my_tree)
5
<BLANKLINE>
>>> print(my_tree.max().data)
5
>>> print(my_tree.min().data)
5
>>> print(my_tree.find(5).data)
5
>>> my_tree.pre_order(sum, None, 4)
9
>>> my_tree.in_order(sum, None, 10)
15
>>> my_tree.pos_order(sum, None, 20)
25
>>> print(my_tree.delete(5))
None
>>> my_tree.is_empty()
True


>>> my_tree.insert(50)
>>> my_tree.insert(60)
>>> my_tree.insert(70)
>>> my_tree.min(my_tree.find(60)).data
50

>>> my_tree.insert(40)
>>> my_tree.insert(30)
>>> my_tree.max(my_tree.find(40)).data
50

>>> my_tree.insert(45)
>>> my_tree.min(my_tree.find(50)).data
30

>>> my_tree.insert(55)
>>> my_tree.insert(80)
>>> my_tree.insert(75)
>>> my_tree.max(my_tree.find(75)).data
80


>>> my_tree.delete(80)
>>> my_tree.delete(75)
>>> my_tree.delete(40)

>>> my_tree.__len__()
6
>>> my_tree.height()
3
>>> print(my_tree)
30
45
50
55
60
70
<BLANKLINE>
>>> print(my_tree.max().data)
70
>>> print(my_tree.min().data)
30
>>> my_tree.pre_order(sum, None, 1)
51
31
46
61
56
71
>>> my_tree.in_order(sum, None, 6)
36
51
56
61
66
76
>>> my_tree.pos_order(sum, None, 10)
55
40
65
80
70
60
"""

if __name__ == '__main__':
    import doctest
    doctest.testmod()
