#pragma once

struct Vector3 {
	int x;
	int y;
	int z;
	Vector3(int xx, int yy, int zz) {
		x = xx;
		y = yy;
		z = zz;
	}
	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}
};

struct GameMap {
	Vector3 row1;
	Vector3 row2;
	Vector3 row3;
	GameMap(Vector3 first, Vector3 second, Vector3 third) {
		row1 = first;
		row2 = second;
		row3 = third;
	}
	GameMap() {
		Vector3 first, second, third;
		row1 = first;
		row2 = second;
		row3 = third;
	}
};
