#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAZE_W 5
#define MAZE_H 5

int maze[MAZE_H][MAZE_W][5];

void printMaze(void) {
	for(int i = 0; i < MAZE_H; i++) {
		for(int j = 0; j < MAZE_W; j++) {
			printf("(%d,%d) %d %d %d %d %d\n", 
				i, 
				j, 
				maze[i][j][0],
				maze[i][j][1], 
				maze[i][j][2], 
				maze[i][j][3],
				maze[i][j][4]);
		}
	}
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void step(int i, int j) {
	maze[i][j][4] = 1;

	system("cls");
	printMaze();
	system("pause");

	int dir[] = {0, 1, 2, 3};
	shuffle(dir, 4);

	for(int k = 0; k < 4; k++) {
		if(dir[k] == 0) {
			if(i == 0 || maze[i-1][j][4]) continue;
			else {
				maze[i][j][0] = 1;
				maze[i-1][j][2] = 1;
				step(i-1, j);
			}
		}
		else if(dir[k] == 1) {
			if(j == MAZE_W-1 || maze[i][j+1][4]) continue;
			else {
				maze[i][j][1] = 1;
				maze[i][j+1][3] = 1;
				step(i, j+1);
			}
		}
		else if(dir[k] == 2) {
			if(i == MAZE_H-1 || maze[i+1][j][4]) continue;
			else {
				maze[i][j][2] = 1;
				maze[i+1][j][0] = 1;
				step(i+1, j);
			}
		}
		else if(dir[k] == 3) {
			if(j == 0 || maze[i][j-1][4]) continue;
			else {
				maze[i][j][3] = 1;
				maze[i][j-1][1] = 1;
				step(i, j-1);
			}
		}
	}
}

void generateMaze(void) {
	srand(time(NULL));
	int i = rand()%MAZE_H;
	int j = rand()%MAZE_W;

	step(i, j);
}

int main(int argc, char const *argv[])
{
	generateMaze();

	return 0;
}