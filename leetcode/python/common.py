"""
"""

class ListNode(object):
  """
    @class ListNode
    @brief Definition for singly-linked list.
  """
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

  def __str__(self):
    return str(self.val)

  def __repr__(self):
    return str(self.val)

  def __eq__(self, other):
    if isinstance(other, ListNode):
      return self.val == other.val
    return False

  def __ne__(self, other):
    return not self.__eq__(other)
