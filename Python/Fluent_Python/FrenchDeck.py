# 纸牌类

import collections

Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
  ranks = [str(n) for n in range(2, 11)] + list('JQKA')  # 纸牌大小
  suits = 'spades diamonds clubs hearts'.split()         # 纸牌样式

  def __init__(self):
    """创建一副牌"""
    self._cards = [Card(rank, suit) for suit in self.suits
                  for rank in self.ranks]

  def __len__(self):
    """返回牌的数量"""
    return len(self._cards)

  def __getitem__(self, position):
    """返回纸牌位置"""
    return self._cards[position]


deck = FrenchDeck()
print(len(deck))

print(deck[0])

from random import choice

print(choice(deck))

print(deck[:3])

print(deck[12::13])

for card in deck:           # 迭代 
  print(card)

for card in reversed(deck): # 反向迭代
  print(card)

  
    