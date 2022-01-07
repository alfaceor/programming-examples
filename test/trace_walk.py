#!/usr/bin/env python3

"""
Author:Carlos Olivares
 Here's a little game for you. In the following grid :
- Black cells are obstacles.
- You can walk on all the yellow cells
- You need to write an algorithm that gets you from a start cell to a stop cell.

For example, how would you reach the cell R:0, C:4 if you started from R: 4, C:0 ? 

TODO:
Choose a good data structure. I think that the best atteempt could be  a binary triee or a trie.
"""
class Cell:
  def __init__(self, data, matrix, previous=None):
    """
    :param data: tuple with (x, y) coordinates.
    :param matrix: Grid matrix where 0 is an allow cell and 1 is forbidden.
    """
    self.r = data[0]
    self.c = data[1]
    self.neighbors = None
    self.step = None
    self.next_cell = None
    self.previous_cell = previous
    # self.next_r = None
    # self.next_c = None
    # So get the possible places to jump
    self._get_neighbors(matrix)

  def __str__(self):
    return "("+str(self.r) + ", " + str(self.c) +")"

  def __repr__(self):
    return self.__str__()
  
  def __eq__(self, other):
    if other is None:
        return False
    return ( (self.r == other.r) and (self.c == other.c) )

  def _get_neighbors(self, matrix):
    """
    Generate a list of jump to neighbors to be use as a queue to explore the paths.
    :param matrix: Grid matrix where 0 is an allow cell and 1 is forbidden.
    """
    self.neighbors = list() # FIXME: name refactor to step_queue instead of neighbors
    
    matrix_Nrows = len(matrix)
    matrix_Ncols = len(matrix[0]) # FIXME: no numpy array shape to help us to validate this.

    # FIXME: use a doble loop with + and - instead or define the jump vectors maybe more general
    steps_list = [ (1, 0), (-1, 0), (0, 1), (0, -1)]
    if self.previous_cell is None:
        # TODO: ADD EVERYTHING
        # No previous step
        for step in steps_list:
            next_r = self.r + step[0] 
            next_c = self.c + step[1] 
            b_rows = (next_r < matrix_Nrows) and (next_r >= 0)
            b_cols = (next_c < matrix_Ncols) and (next_c >= 0)
            if b_rows and b_cols:
                if matrix[next_r][next_c] == 0:
                    self.neighbors.append(step)
    else:
        # Append first the step back
        previous_step = (self.previous_cell.r - self.r, self.previous_cell.c - self.c)
        self.neighbors.append(previous_step)
        for step in steps_list:
            if step != previous_step:
                next_r = self.r + step[0] 
                next_c = self.c + step[1] 
                b_rows = (next_r < matrix_Nrows) and (next_r >= 0)
                b_cols = (next_c < matrix_Ncols) and (next_c >= 0)
                if b_rows and b_cols:
                    if matrix[next_r][next_c] == 0:
                        #print(" aaa: ", step, matrix[next_r][next_c], next_r, next_c) 
                        self.neighbors.append(step)

  
  def get_next_cell(self, matrix):
    """
    Get a new cell from stack.
    :param matrix: Grid matrix where 0 is an allow cell and 1 is forbidden.
    """
    if len(self.neighbors) > 0 :
      # FIXME: REMOVE last neighbors and put it at the begining of the list
      self.step = self.neighbors.pop()
      next_data = (self.r + self.step[0], self.c + self.step[1])
      if self.previous_cell is not None:
        if next_data == (self.previous_cell.r, self.previous_cell.c):
          return self.previous_cell
      new_cell = Cell(next_data, matrix, previous=self)
      #new_cell.previous_cell = self
      return new_cell
      # if (new_cell == self) and len(self.neighbors) > 1:
      #   self.neighbors = [self.step] + self.neighbors # FIXME: BETTER USE COLLECTIONS DEQUE
      #   self.step = self.neighbors.pop()
      #   next_data = (self.r + self.step[0], self.c + self.step[1])
      #   new_cell = Cell(next_data, matrix, previous=self)
      #   return new_cell
      # else:
      #   return new_cell
    else:
      return None
      # raise Exception("No more neighbors for this cell")
  
class Path:
  """
  Class to link the cell with possibles paths.
  """
  def __init__(self, start_cell, stop_cell, matrix):
    self.head = start_cell # None # to point to the first cell.
    self.end = stop_cell
    self.matrix = matrix
    self.previous_cell = None
    
  
  # def __iter__(self):
  #   cell = self.head
  #   # This will find only one path, not the minimum path
  #   self.previous_cell = None
  #   while cell is not None: #(cell.r != self.end.r) and (cell.c != self.end.c) :
  #     yield cell
  #     self.previous_cell = cell
  #     cell = cell.next_cell


def myPathPlanning (matrix, start, stop):
  """
  - grid : List of Lists : Row[Col[]]. Possible values : 0 or 1
  - start : Couple representing start cell coordinates. For example (4,0)
  - stop : Couple representing stop cell coordinates. For example (0,4)
  """ 
  r0, c0 = start
  rf, cf = stop
  # check if start and stop are not obstacles
  if (matrix[r0][c0] == 1) or (matrix[rf][cf] == 1):
    raise Exception("obstacles can not be use as start or stop cell")
  else:
    camino = list()
    cell = Cell(start, matrix)
    stop_cell = Cell(stop, matrix)
    cell.next_cell = cell.get_next_cell(matrix)

    # Forward path
    while cell != stop_cell:
      cell = cell.next_cell
      cell.next_cell = cell.get_next_cell(matrix)
  
    # Backward path
    cell_prev = cell.previous_cell
    while cell_prev != None:
        camino.append(cell_prev.step)
        cell_prev = cell_prev.previous_cell
  
    return camino[::-1]


def main():
  # Can I use a numpy array? XD
  matrix = [
      [
        1,0,1,0,0
      ],
      [
        0,0,0,0,1
      ],
      [
        1,0,1,1,0
      ],
      [
        0,0,0,0,0
      ],
      [
        0,1,0,1,0
      ]]

  """
  cell = cell.next_cell
  print("curr: ", cell)
  print(cell.neighbors)
  print("prev: ", cell.previous_cell)
  cell.next_cell = cell.get_next_cell(matrix)
  print("next: ", cell.next_cell)
  print("-"*10)


  # Antes de generar el next cell verificar que no es el previo, si lo es retorna None
  #if cell.next_cell == cell.previous_cell:
  print("="*50)
  for i in range(16):
      cell = cell.next_cell
      print("curr: ", cell)
      print(cell.neighbors)
      print("prev: ", cell.previous_cell)
      cell.next_cell = cell.get_next_cell(matrix)
      print("next: ", cell.next_cell)
      print("-"*10)
  
  cell = Cell((4,0), matrix)
  stop_cell = Cell((0,4), matrix)
  cell.next_cell = cell.get_next_cell(matrix)
  while cell != stop_cell:
    cell = cell.next_cell
    cell.next_cell = cell.get_next_cell(matrix)

  cell_prev = cell.previous_cell
  print("cell_prev ", cell_prev)
  while cell_prev != None:
      print("back: ", cell_prev, cell_prev.step)
      cell_prev = cell_prev.previous_cell




  """

  camino = myPathPlanning (matrix, (4,0), (0,4))
  print(camino)


if __name__ == '__main__':
  main()
