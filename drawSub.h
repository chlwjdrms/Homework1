#pragma once

const int width = 1500;
const int height = 480;


float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawCircle(const int& i4, const int& j4, const int& i5, const int& j5, const float& red, const float& green, const float& blue) {
	for (int i = i4; i <= i5; i++) {
		for (int j = j4; j <= j5; j++) {
			int r = (i5 - i4) / 2;
			int a = (i - (i4 + i5) / 2)*(i - (i4 + i5) / 2) + (j - (j4 + j5) / 2)*(j - (j4 + j5) / 2);
			if (a <= r*r && a >= (r - 3)*(r - 3)) {
				drawPixel(i, j, red, green, blue);
			}
		}
	}
}
void isCircle(int i1, int i2, int j1, int j2, double posx, double posy) {
	j1 = j1;
	j2 = j2;
	if (posx >= i1 && posx <= i2 && height - posy >= j1 && height - posy <= j2)
		drawCircle(i1, j1, i2, j2, 0.0f, 0.0f, 1.0f);
	else
		drawCircle(i1, j1, i2, j2, 1.0f, 0.0f, 0.0f);
}