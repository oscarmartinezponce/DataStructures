#!/usr/bin/python3
# -*- coding: utf-8 -*-

from node_avl import NodeAVL

__email__ = "oscar07112009@hotmail.com"
__license__ = "GPL"
__maintainer__ = "Oscar Martínez"
__status__ = "Developing"

__version__ = "1.0"

__date__ = "jun/08/2020"

__author__ = "Oscar Martínez"

__credits__ = "AvanZen"


class TreeAVL:
    """This class is a balancing binary search tree."""

    # ______________________________Class methods______________________________

    @staticmethod
    def __str(**kwargs) -> str:
        """This is an auxiliary method used to concatenate the node data."""
        val_left = kwargs['val_left'] or ''
        val_right = kwargs['val_right'] or ''
        return val_left + str(kwargs['node'].data) + "\n" + val_right

    @staticmethod
    def __len(**kwargs) -> int:
        """This is an auxiliary method used to count the number of nodes."""
        val_left = kwargs['val_left'] or 0
        val_right = kwargs['val_right'] or 0
        return val_left + val_right + 1

    @staticmethod
    def __height(**kwargs) -> int:
        """This is an auxiliary method used to calculate the height of tree."""
        val_left = kwargs['val_left'] or 0
        val_right = kwargs['val_right'] or 0
        return (val_left if val_left > val_right else val_right) + 1

    @staticmethod
    def __is_leaf(node: NodeAVL) -> bool:
        """Returns True if the node is a leaf, otherwise it returns False."""
        return not (node.left or node.right)

    @staticmethod
    def __is_full(node: NodeAVL) -> bool:
        """Returns True if the node has 2 nodes (left and right), otherwise it
        returns False."""
        return bool(node.left and node.right)

    @staticmethod
    def __max(node: NodeAVL) -> NodeAVL:
        """This is an auxiliary method to find the highest data."""
        return TreeAVL.__max(node.right) if node and node.right else node

    @staticmethod
    def __min(node: NodeAVL) -> NodeAVL:
        """This is an auxiliary method to find the lowest data."""
        return TreeAVL.__min(node.left) if node and node.left else node

    @staticmethod
    def __replace(old: NodeAVL, new: NodeAVL) -> None:
        """Replaces the old node with the new node in the tree."""
        if old.left != new:
            new.left = old.left
        if old.right != new:
            new.right = old.right
        new.parent = old.parent

    @staticmethod
    def __find(data: object, node: NodeAVL) -> NodeAVL:
        """Receives by parameter the data to search, if it find returns the
        object in aux_node, if not find returns in aux_node like None."""
        if isinstance(node, NodeAVL):
            if data < node.data:
                aux = TreeAVL.__find(data, node.left)
            elif data > node.data:
                aux = TreeAVL.__find(data, node.right)
            else:
                return node
            return aux

    @staticmethod
    def __pre_order(func, node: NodeAVL, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in pre order and
        execute the function."""
        if isinstance(node, NodeAVL):
            val = func(node=node, *args, **kwargs)
            TreeAVL.__pre_order(func, node.left, *args, **kwargs)
            TreeAVL.__pre_order(func, node.right, *args, **kwargs)
            return val

    @staticmethod
    def __in_order(func, node: NodeAVL, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in order and
        execute the function."""
        if isinstance(node, NodeAVL):
            val_left = TreeAVL.__in_order(func, node.left, *args, **kwargs)
            val = func(node=node, val_left=val_left, *args, **kwargs)
            TreeAVL.__in_order(func, node.right, *args, **kwargs)
            return val

    @staticmethod
    def __pos_order(func, node: NodeAVL, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in pos order and
        execute the function."""
        if isinstance(node, NodeAVL):
            val_left = TreeAVL.__pos_order(func, node.left, *args, **kwargs)
            val_right = TreeAVL.__pos_order(func, node.right, *args, **kwargs)
            val = func(node=node, val_left=val_left, val_right=val_right, *args, **kwargs)
            return val

    # ______________________________Class methods______________________________

    # ______________________________MAGIC METHODS______________________________

    # _____________________________Generic methods_____________________________

    def __init__(self, class_type: type):
        self.__type = class_type
        self.__root = None

    def __len__(self):
        """Returns the total number of nodes that the tree has."""
        return self.pos_order(TreeAVL.__len) or 0

    def __str__(self):
        """Returns a string with the node data in order."""
        return self.pos_order(TreeAVL.__str) or ''

    # _____________________________Generic methods_____________________________

    # ______________________________MAGIC METHODS______________________________

    # _________________________________Getters_________________________________

    @property
    def type(self) -> type:
        """Returns the tree data type."""
        return self.__type

    # _________________________________Getters_________________________________

    # _____________________________Private methods_____________________________

    def __choose_node(self, node: NodeAVL) -> NodeAVL:
        """If node is None it returns the root of the tree, otherwise it
        returns the same node."""
        return node or self.__root

    def __balance_factor(self, node: NodeAVL) -> int:
        """Returns the balance factor of the node."""
        return self.height(node.right, False) - self.height(node.left, False)

    def __balance(self, node: NodeAVL) -> None:
        """Decides if node balancing is necessary and the type of balancing."""
        balance_factor = self.__balance_factor(node)
        if balance_factor >= 2:
            if self.__balance_factor(node.right) >= 0:
                self.__simple_left_rot(node)
            else:
                self.__double_left_rot(node)
        elif balance_factor <= -2:
            if self.__balance_factor(node.left) < 0:
                self.__simple_right_rot(node)
            else:
                self.__double_right_rot(node)

    def __connect_parent(self, old: NodeAVL, new: NodeAVL) -> None:
        """Connects the parent node (old.parent) with node.child (new)"""
        if not old.parent:
            self.__root = new
        elif old.parent.left == old:
            old.parent.left = new
        else:
            old.parent.right = new

    def __simple_left_rot(self, node: NodeAVL) -> None:
        """Does a simple left rotation in the tree."""
        self.__connect_parent(node, node.right)
        if node.right.left:
            node.right.left.parent = node
        node.right.parent = node.parent
        node.parent = node.right

        node.right = node.right.left
        node.parent.left = node

    def __simple_right_rot(self, node: NodeAVL) -> None:
        """Does a simple right rotation in the tree."""
        self.__connect_parent(node, node.left)
        if node.left.right:
            node.left.right.parent = node
        node.left.parent = node.parent
        node.parent = node.left

        node.left = node.left.right
        node.parent.right = node

    def __double_left_rot(self, node: NodeAVL) -> None:
        """Does a double left rotation in the tree."""
        self.__simple_right_rot(node.right)
        self.__simple_left_rot(node)

    def __double_right_rot(self, node: NodeAVL) -> None:
        """Does a double right rotation in the tree."""
        self.__simple_left_rot(node.left)
        self.__simple_right_rot(node)

    def __insert(self, node: NodeAVL, aux_node: NodeAVL) -> None:
        """Insert a node in order in the tree and it does a balancing."""
        if aux_node.data < node.data:
            if isinstance(node.left, NodeAVL):
                self.__insert(node.left, aux_node)
            else:
                node.left = aux_node
                aux_node.parent = node
        else:
            if isinstance(node.right, NodeAVL):
                self.__insert(node.right, aux_node)
            else:
                node.right = aux_node
                aux_node.parent = node

        self.__balance(node)

    def __delete(self, node: NodeAVL, data: object) -> None:
        """This an auxiliary method to delete nodes by object"""
        if data < node.data:
            if isinstance(node.left, NodeAVL):
                self.__delete(node.left, data)
        elif data > node.data:
            if isinstance(node.right, NodeAVL):
                self.__delete(node.right, data)
        else:
            if self.__is_leaf(node):  # Is leaf
                self.__connect_parent(node, node.left)
            elif self.__is_full(node):  # Has 2 nodes
                node_oldest = self.max(node.left)
                self.__connect_parent(node, node_oldest)
                if node_oldest != node.left:
                    if node_oldest.left:
                        node_oldest.left.parent = node_oldest.parent
                    self.__connect_parent(node_oldest, node_oldest.left)
                    node.left.parent = node_oldest
                TreeAVL.__replace(node, node_oldest)
                node.right.parent = node_oldest
            else:  # Only has 1 node
                if node.left:
                    self.__connect_parent(node, node.left)
                    TreeAVL.__replace(node, node.left)
                else:
                    self.__connect_parent(node, node.right)
                    TreeAVL.__replace(node, node.right)

        self.__balance(node)

    # _____________________________Private methods_____________________________

    # _____________________________Public methods______________________________

    def is_empty(self) -> bool:
        """If the tree has no any node, it returns True, otherwise it
        returns False."""
        return False if self.__root else True

    def height(self, node: NodeAVL = None, root: bool = True) -> int:
        """If root is True it checks if node is None, if node is None it
        returns the height of the tree. If root is False, it returns the
        height of the sub-tree."""
        if root:
            node = self.__choose_node(node)
        return self.__pos_order(self.__height, node) if node else 0

    def max(self, node: NodeAVL = None) -> NodeAVL:
        """Returns the highest data in the sub-tree, if node is None then it
        returns the highest data in the tree."""
        node = self.__choose_node(node)
        return TreeAVL.__max(node)

    def min(self, node: NodeAVL = None) -> NodeAVL:
        """Returns the lowest data in the sub-tree, if node is None then it
        returns the lowest data in the tree."""
        node = self.__choose_node(node)
        return TreeAVL.__min(node)

    def insert(self, data: object) -> None:
        """Receives an object and insert a node with the object in the tree
        when it inserts the node it does a balancing."""
        if not isinstance(data, self.__type):
            msg = "Try to insert a data type " + str(type(data)) + \
                  " into a tree of type " + str(self.__type)
            raise TreeAVL.TreeAVLError(msg)

        if self.__root:
            aux_node = NodeAVL(data)
            self.__insert(self.__root, aux_node)
        else:
            self.__root = NodeAVL(data)

    def find(self, data: object, node: NodeAVL = None,) -> NodeAVL:
        """Receives an object by parameter and it returns an object if the
        object is equal None then did not find the data, otherwise is it equals
        to None then the object is the data find."""
        node = self.__choose_node(node)
        return self.__find(data, node)

    def delete(self, data: object) -> None:
        """Deletes a node in the tree if it finds otherwise it does nothing."""
        if not isinstance(data, self.__type):
            msg = "The " + str(type(data)) + " data type is invalid. " + \
                  "The data type of this tree is " + str(self.__type)
            raise TreeAVL.TreeAVLError(msg)

        if self.__root is not None:
            self.__delete(self.__root, data)

    def pre_order(self, func, node: NodeAVL = None, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in pre order and
        execute the function."""
        node = self.__choose_node(node)
        return self.__pre_order(func, node, *args, **kwargs)

    def in_order(self, func, node: NodeAVL = None, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in order and
        execute the function."""
        node = self.__choose_node(node)
        return self.__in_order(func, node, *args, **kwargs)

    def pos_order(self, func, node: NodeAVL = None, *args, **kwargs) -> object:
        """Receives a function by parameter and travel the tree in pos order and
        execute the function."""
        node = self.__choose_node(node)
        return self.__pos_order(func, node, *args, **kwargs)

    # _____________________________Public methods______________________________

    # ______________________________Inner classes______________________________

    class TreeAVLError(Exception):
        def __init__(self, msg: str):
            super().__init__(msg)

    # ______________________________Inner classes______________________________
