#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#include "Grid.h"

G_Grid G_createGrid(char *arrayParameters[G_LENGTH]) {

  G_Grid grid;
  S_SQUARE *square = S_createSquare();
  int i;

  for (i = 0; i < G_LENGTH; i++) {
    S_defineSquare(c, arrayParameters[i], i);
    grille.arraySquares[i] = *square;
  }

  S_delete(c);
  return grille;
}

S_SQUARE G_getSquare(G_Grid grid, int squareNumber) {
  return g.arraySquares[squareNumber];
}

LL_LinkedList G_getNeighbours(G_Grid grid, S_SQUARE square) {

  int squareNumber = S_getPosition(c);
  LL_LinkedList linkedList = LL_createLinkedList();
  int neighbours[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
  int i;
  S_SQUARE *neighbour = S_createSquare();
  if (squareNumber % 4 == 0) { // left column of the grid
    neighbours[1] = squareNumber - G_COTE;
    neighbours[2] = squareNumber - G_COTE + 1;
    neighbours[4] = squareNumber + 1;
    neighbours[6] = squareNumber + G_COTE;
    neighbours[7] = squareNumber + G_COTE + 1;
  } else if ((squareNumber + 1 % 4) == 0) { // 0 is excluded thanks to the first
                                            // if (right column of the grid)
    neighbours[0] = squareNumber - G_COTE - 1;
    neighbours[1] = squareNumber - G_COTE;
    neighbours[3] = squareNumber - 1;
    neighbours[5] = squareNumber + G_COTE - 1;
    neighbours[6] = squareNumber + G_COTE;
  } else {
    neighbours[0] = squareNumber - G_COTE - 1;
    neighbours[1] = squareNumber - G_COTE;
    neighbours[2] = squareNumber - G_COTE + 1;
    neighbours[3] = squareNumber - 1;
    neighbours[4] = squareNumber + 1;
    neighbours[5] = squareNumber + G_COTE - 1;
    neighbours[6] = squareNumber + G_COTE;
    neighbours[7] = squareNumber + G_COTE + 1;
  }

  for (i = 0; i < 8; i++) {
    if ((neighbours[i] >= 0) && (neighbours[i] < G_LENGTH)) {
      *neighbour = G_getSquare(g, neighbours[i]);
      LL_add(&linkedList, neighbour, S_copy);
    }
  }
  S_delete(neighbour);
  return linkedList;
}

void G_deleteGrid(G_Grid grid) {
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    free(S_getValue(G_getSquare(grid, i)));
  }
}
