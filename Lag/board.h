#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>


class Object {
private:
	int length, width;//���ȡ����
	int **last, **next;
	int stepx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int stepy[8] = { -1, 0, 1, 1, -1, -1, 0, 1 };
public:
	Object(int, int);

	~Object();

	void fecth();

	void reshape();

	int **show();
};
