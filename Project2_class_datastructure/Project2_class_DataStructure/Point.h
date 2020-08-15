#ifndef _POINT_H
#define _POINT_H
class Point {
public:
	Point();
	virtual ~Point();
	void initPoint(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void move(int offx, int offy) {
		x += offx;
		y += offy;
	}
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x, y;
	const static int z = 2;
	static int p;
};
int Point::p = 2;

class Rectangle :private Point {
public:
	void initRectangle(int x, int y, int w, int h) {
		initPoint(x, y);
		this->w = w;
		this->h = h;
	}
	void move(int offx, int offy) {
		Point::move(offx, offy);   //同名处理
	}
private:
	int w, h;
};
#endif
