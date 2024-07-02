"""
The game state and logic (model component) of 512, 
a game based on 2048 with a few changes. 
This is the 'model' part of the model-view-controller
construction plan.  It must NOT depend on any
particular view component, but it produces event 
notifications to trigger view updates. 
"""

from game_element import GameElement, GameEvent, EventKind
from typing import List, Tuple, Optional
import random

# Configuration constants
GRID_SIZE = 4


class Vec():
    """A Vec is an (x,y) or (row, column) pair that
    represents distance along two orthogonal axes.
    Interpreted as a position, a Vec represents
    distance from (0,0).  Interpreted as movement,
    it represents distance from another position.
    Thus we can add two Vecs to get a Vec.
    """

    def __init__(self, x, y):
        """Initializes x and y """
        self.x = x
        self.y = y

    def __eq__(self, other: "Vec") -> bool:
        """Magic method returns true if the x coord for one x is the same as the x coord for other or the y coord for
        one is the same as the y coord for other, else return false"""
        return self.x == other.x or self.y == other.x

    def __add__(self, other: "Vec") -> "Vec":
        """Magic method adds two vectors together"""
        return Vec(self.x + other.x, self.y + other.y)


class Tile(GameElement):
    """A slidy numbered thing."""

    def __init__(self, pos: Vec, value: int):
        """Initializes row as pos.x, col as pos.y, and value"""
        super().__init__()
        self.row = pos.x
        self.col = pos.y
        self.value = value

    def __eq__(self, other: "Tile"):
        """Returns true if one tile value is the same as another tile value"""
        return self.value == other.value

    def __repr__(self):
        """Not like constructor --- more useful for debugging"""
        return f"Tile[{self.row},{self.col}]:{self.value}"

    def __str__(self):
        """Useful for debugging"""
        return str(self.value)

    def move_to(self, new_pos: Vec):
        """Updates the GameEvent"""
        self.row = new_pos.x
        self.col = new_pos.y
        self.notify_all(GameEvent(EventKind.tile_updated, self))

    def merge(self, other: "Tile"):
        """Merges two tiles and notifies the GameEvent"""
        # This tile incorporates the value of the other tile
        self.value = self.value + other.value
        self.notify_all(GameEvent(EventKind.tile_updated, self))
        # The other tile has been absorbed.  Resistance was futile.
        other.notify_all(GameEvent(EventKind.tile_removed, other))


class Board(GameElement):
    """The game grid.  Inherits 'add_listener' and 'notify_all'
    methods from game_element.GameElement so that the game
    can be displayed graphically.
    """

    def __init__(self, rows=4, cols=4):
        """Initializes rows, cols, and list of tiles"""
        super().__init__()
        self.rows = rows
        self.cols = cols
        self.tiles = []
        for row in range(rows):
            row_tiles = []
            for col in range(cols):
                row_tiles.append(None)
            self.tiles.append(row_tiles)

    def __getitem__(self, pos: Vec) -> Tile:
        """Returns the x and y coords"""
        return self.tiles[pos.x][pos.y]

    def __setitem__(self, pos: Vec, tile: Tile):
        """Sets a tile"""
        self.tiles[pos.x][pos.y] = tile

    def _empty_positions(self) -> List[Vec]:
        """Return a list of positions of None values,
        i.e., unoccupied spaces.
        """
        empties = []
        for row in range(len(self.tiles)):
            for col in range(len(self.tiles[row])):
                if self.tiles[row][col] is None:
                    empties.append(Vec(row, col))

        return empties

    def has_empty(self) -> bool:
        """Is there at least one grid element without a tile?"""
        return self._empty_positions() is not None

    def place_tile(self, value=None):
        """Place a tile on a randomly chosen empty square."""
        empties = self._empty_positions()
        assert len(empties) > 0
        choice = random.choice(empties)
        row, col = choice.x, choice.y
        if value is None:
            # 0.1 probability of 4
            if random.random() > 0.1:
                value = 2
            else:
                value = 4
        new_tile = Tile(Vec(row, col), value)
        self.tiles[row][col] = new_tile
        self.notify_all(GameEvent(EventKind.tile_created, new_tile))

    def to_list(self) -> List[List[int]]:
        """Test scaffolding: represent each Tile by its
        integer value and empty positions as 0
        """
        result = []
        for row in self.tiles:
            row_values = []
            for col in row:
                if col is None:
                    row_values.append(0)
                else:
                    row_values.append(col.value)
            result.append(row_values)
        return result

    def from_list(self, values: List[List[int]]):
        """Test scaffolding: set board tiles to the
        given values, where 0 represents an empty space.
        """
        for row in range(len(values)):
            for col in range(len(values[0])):
                tile_test = Tile(Vec(row, col), values[row][col])
                self.tiles[row][col] = tile_test
                if self.tiles[row][col].value == 0:
                    self.tiles[row][col] = None

    def in_bounds(self, pos: Vec) -> bool:
        """Is position (pos.x, pos.y) a legal position on the board?"""
        if pos.x in range(self.rows):
            if pos.y in range(self.cols):
                return True
        return False

    def _move_tile(self, old_pos: Vec, new_pos: Vec):
        """Moves tiles from the old position to a new position. The new position becomes the old position and the
        old position becomes None"""
        self[old_pos].move_to(new_pos)
        self[new_pos] = self[old_pos]
        self[old_pos] = None

    def slide(self, pos: Vec, dir: Vec):
        """Slide tile at pos.x, pos.y (if any)
        in direction (dir.x, dir.y) until it bumps into
        another tile or the edge of the board.
        """
        if self[pos] is None:
            return
        while True:
            new_pos = pos + dir
            if not self.in_bounds(new_pos):
                break
            if self[new_pos] is None:
                self._move_tile(pos, new_pos)
            elif self[pos] == self[new_pos]:
                self[pos].merge(self[new_pos])
                self._move_tile(pos, new_pos)
                break  # Stop moving when we merge with another tile
            else:
                # Stuck against another tile
                break
            pos = new_pos

    def right(self):
        """Slides everything right in the direction of (0, 1)"""
        for row in range(self.rows):
            for col in reversed(range(self.cols)):
                self.slide(Vec(row, col), Vec(0, 1))

    def left(self):
        """Slides everything left in the direction of (0, -1)"""
        for row in range(0, self.rows):
            for col in range(0, self.cols):
                self.slide(Vec(row, col), Vec(0, -1))

    def up(self):
        """Slides everything up in the direction of (-1, 0)"""
        for row in range(0, self.rows):
            for col in range(0, self.cols):
                self.slide(Vec(row, col), Vec(-1, 0))

    def down(self):
        """Slides everything down in the direction of (1,0)"""
        for row in reversed(range(self.rows)):
            for col in range(self.cols):
                self.slide(Vec(row, col), Vec(1, 0))

    def score(self) -> int:
        """Calculate a score from the board.
        (Differs from classic 1024, which calculates score
        based on sequence of moves rather than state of
        board.
        """
        values = 0
        for row in range(self.rows):
            for col in range(self.cols):
                if self.tiles[row][col] is not None:
                    values += self.tiles[row][col].value
        return values
