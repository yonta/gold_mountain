#!/usr/bin/env python
# -*- coding: utf-8 -*-

import functools

world_x = 10
world_y = 10
x_length = 5
y_length = 5


def calcGold(x, y, world):  # [['G', 'w'], ['G', 'w']] -> [1, 1] -> 2
    golds = [1 for i in range(x, x + x_length)
             for j in range(y, y + y_length) if world[j][i] == 'G']
    gold = functools.reduce(lambda x, y: x + y, golds) if golds != [] else 0
    return gold

if __name__ == '__main__':
    world = [input() for i in range(world_y)]
    # world = ["wwGwwwwwGG",
    #          "Gwwwwwwwww",
    #          "wwwwwwwwww",
    #          "Gwwwwwwwww",
    #          "wwwwGwwGww",
    #          "wGwwwwwwww",
    #          "wwwGGwwwww",
    #          "wwwwwwGwww",
    #          "wwwwGGwwww",
    #          "GwwwGGwGwG"]
    gold_points = [(x, y, calcGold(x, y, world))
                   for x in range(world_x - x_length + 1)
                   for y in range(world_y - y_length + 1)]
    max_gold = functools.reduce(lambda acc, item: acc if acc[
                                2] > item[2] else item, gold_points)
    print('{{"x":{0},"y":{1},"g":{2}}}'.format(
        max_gold[0], max_gold[1], max_gold[2]))
