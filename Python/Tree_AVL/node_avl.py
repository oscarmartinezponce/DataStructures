#!/usr/bin/python3
# -*- coding: utf-8 -*-

__email__ = "oscar07112009@hotmail.com"
__license__ = "GPL"
__matypeainer__ = "Oscar Martínez"
__status__ = "Developing"

__version__ = "1.0"

__date__ = "jun/08/2020"

__author__ = "Oscar Martínez"

__credits__ = "AvanZen"


class NodeAVL:
    """This is an inner class for tree_avl.
    Used for tree nodes."""

    # ______________________________MAGIC METHODS______________________________

    # _____________________________Generic methods_____________________________

    def __init__(self, data: object = None, node=None):
        """data: Class"""
        if node:
            self.__data = node.data
            self.__left = node.left
            self.__right = node.right
            self.__parent = node.parent
        else:
            self.__data = data
            self.__left = None
            self.__right = None
            self.__parent = None

    # _____________________________Generic methods_____________________________

    # ______________________________MAGIC METHODS______________________________

    # _________________________________Getters_________________________________

    @property
    def data(self):
        """return self.__data"""
        return self.__data

    @property
    def left(self):
        """return self.__left"""
        return self.__left

    @property
    def right(self):
        """return self.__right"""
        return self.__right

    @property
    def parent(self):
        """return self.__parent"""
        return self.__parent

    # _________________________________Getters_________________________________

    # _________________________________Setters_________________________________

    @data.setter
    def data(self, data: object):
        """self.__data = data"""
        self.__data = data

    @left.setter
    def left(self, left: object):
        """self.__left = left"""
        self.__left = left

    @right.setter
    def right(self, right: object):
        """self.__right = right"""
        self.__right = right

    @parent.setter
    def parent(self, parent: object):
        """self.__parent = parent"""
        self.__parent = parent

    # _________________________________Setters_________________________________
