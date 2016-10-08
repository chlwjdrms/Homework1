#pragma once

#include "drawSub.h"
#include "Geometric.h"

// Class A
class A : public Geometric {
public:
	int start_x, start_y;
	int end_x, end_y;
	double xpos, ypos;

public:
	A() {}

	A(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y, double _xpos, double _ypos) {
		initialize(_start_x, _start_y, _end_x, _end_y, _xpos, _ypos);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y, double _xpos, double _ypos) {
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
		xpos = _xpos;
		ypos = _ypos;
	}
	void draw() {
		drawCircleInA(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f, xpos, ypos);
	}
	void drawCircleInA(const int& i4, const int& j4, const int& i5, const int& j5, const float& red, const float& green, const float& blue, double xpos, double ypos) {
		isCircle(i4, i5, j4, j5, xpos, ypos);

		int k1 = i4 + (i5 - i4) / 4;
		int k2 = i5 - (i5 - i4) / 4;
		int l1 = j4 + (j5 - j4) / 4;
		int l2 = j5 - (j5 - j4) / 4;

		for (int i = k1 + (k2 - k1) / 4; i < k2 - (k2 - k1) / 4; i++) { // 가로 직선
			drawPixel(i, (l1 + l2) / 2, red, green, blue);
		}
		// 화살표 끝
		drawLine((k1 + k2) / 2, l2, k2, l1, 1.0f, 0.0f, 0.0f);
		drawLine(k1, l1, (k1 + k2) / 2, l2, 1.0f, 0.0f, 0.0f);
	}
};