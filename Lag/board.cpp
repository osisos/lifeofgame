#include "board.h"

Object::Object(int _n, int _m) : length(_n), width(_m) {
	last = new int *[length + 2];
	for (int i = 0; i < length + 2; i++)
		last[i] = new int[width + 2];

	next = new int *[length + 2];
	for (int i = 0; i < length + 2; i++)
		next[i] = new int[width + 2];

	for (int i = 0; i < length + 2; i++)
		for (int j = 0; j < width + 2; j++)
			next[i][j] = 0;

	for (int i = 0; i < length + 2; i++)
		for (int j = 0; j < width + 2; j++)
			last[i][j] = 0;
}

Object::~Object() {
	for (int i = 0; i < length + 2; i++)
		delete[]last[i];
	delete[]last;


	for (int i = 0; i < length + 2; i++)
		delete[]next[i];
	delete[]next;
}

void Object::fecth() {
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= width; j++) {
			int sum = 0;
			for (int k = 0; k < 8; k++) {
				int tx = i + stepx[k];
				int ty = j + stepy[k];

				sum += last[tx][ty];
			}

			if (last[i][j] == 1) {
				if (sum < 2)
					next[i][j] = 0;
				else if (sum >= 2 && sum <= 2)
					next[i][j] = 1;
				else
					next[i][j] = 0;
			}
			else {
				if (sum == 3)
					next[i][j] = 1;
			}

		}
	}

	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= width; j++) {
			last[i][j] = next[i][j];
		}
	}
}


int **Object::show() {
	return last;
}

void Object::reshape() {
	srand((unsigned)time(NULL));
	for (int i = 1; i <= length; i++)
		for (int j = 1; j <= width; j++) {
			int num = rand() % 2;
			last[i][j] = num;
			next[i][j] = num;
		}
}
