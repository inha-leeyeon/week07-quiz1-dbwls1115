#include <iostream>
#include <vector>
#include "Square.h"
using namespace std;

Point::Point(int px, int py) { x = px; y = py; }
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

Square::Square()
	:Point() { side = 0; area = 0; name = ""; }

Square::Square(const string name, int x, int y, unsigned int side)
	:Point(x, y) {
	this->name = name;
	this->side = side;
}
unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int side) { this->side = side; setArea(side); }
void Square::setArea(unsigned int side) { this->area = side * side; }
void Square::setName(string name) { this->name = name; }

int main() {
	int num;
	cin >> num;

	vector<Square> squares(num);

	for (int i = 0; i < num; i++) {
		string name;
		int x, y;
		unsigned int side;

		cin >> name >> x >> y >> side;

		squares[i] = Square(name, x, y, side);
	}

	cout << "\nSquares in increasing order of area" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (squares[j].getArea() > squares[j + 1].getArea()) {
				Square temp(squares[j]);
				squares[j] = squares[j + 1];
				squares[j + 1] = temp;
			}
		}

		cout << squares[i].getName() << "(" << squares[i].getX() << "," << squares[i].getY()
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	cout << "\nSquares in increasing order of max x-coordinate" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (squares[j].getX() > squares[j + 1].getX()) {
				Square temp(squares[j]);
				squares[j] = squares[j + 1];
				squares[j + 1] = temp;
			}
		}

		cout << squares[i].getName() << "(" << squares[i].getX() << "," << squares[i].getY()
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	cout << "\nSquares in increasing order of max y-coordinate" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (squares[j].getY() > squares[j + 1].getY()) {
				Square temp(squares[j]);
				squares[j] = squares[j + 1];
				squares[j + 1] = temp;
			}
		}

		cout << squares[i].getName() << "(" << squares[i].getX() << "," << squares[i].getY()
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	return 0;
}