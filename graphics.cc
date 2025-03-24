#include <iostream>
#include "/public/colors.h"
#include "graphics.h"

using namespace std;

void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(0);
}

void ParticleGraphics::drawPoint(int r, int c) {
	movecursor(r,c);
	setbgcolor(color.r,color.g,color.b);
	cout << " " << flush;
	resetcolor();
}

void ParticleGraphics::drawPoint(int r, int c, char ch) {
	movecursor(r,c);
	setbgcolor(color.r,color.g,color.b);
	cout << ch << flush;
	resetcolor();
}

void ParticleGraphics::drawRect(int r, int c, int w, int h) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
	  		drawPoint(i,j);
		}
	}
}

//give the center point row, center point column, total width, then total height
void ParticleGraphics::drawOval(int r, int c, int w, int h) {
	//double cx = c;
	//double cy = r;
	double a = static_cast<double>(w) / 2.0;
	double b = static_cast<double>(h) / 2.0;
	for (int i = r - (h / 2) - 1; i < r + (h / 2) + 1; i++) {
		for (int j = c - (w / 2) - 1; j < c + (w / 2) + 1; j++) {
			double di = i - r;
			double dj = j - c;
			if ((((di*di)/(b*b)) + ((dj*dj)/(a*a))) <= 1.001) {
				//setColor(Color{255,0,0});
				drawPoint(i,j);
			}
			else {
				//setColor(Color{0,255,0});
				//drawPoint(i,j);
			}
		}
	}
}

void ParticleGraphics::drawLine(int x1, int y1, int x2, int y2) {
    double a = x1;
    double b = y1;
    double c = x2;
    double d = y2;
    for (int i = min(y1,y2); i <= max(y1,y2); i++) {
        for (int j = min(x1,x2); j <= max(x1,x2); j++) {
            if (abs(((i - b) / (d - b)) - ((j - a) / (c - a))) <= 0.01) {
                //setColor(Color{255,0,0});
                drawPoint(i,j);
            }
            else {
                //setColor(Color{0,255,0});
                //drawPoint(i,j);
            }
        }
    }
}

bool isIn(int a, int b, bool up, int c, int d, int e, int f) {
	double x = a;
	double y = b;
	double x1 = c;
	double y1 = d;
	double x2 = e;
	double y2 = f;
	if (c == e) {
		//vertical line
		if (up) {
			if (a >= c) return true;
		}
		if (a <= c) return true;
		return false;
	}
	if (abs(y - ((((x - x1) / (x2 - x1)) * (y2 - y1)) + y1)) <= 0.001) {
		return true;
	}
	if (!up) {
		if (y - ((((x - x1) / (x2 - x1)) * (y2 - y1)) + y1) > 0) {
			return true;
		}
	}
	else {
		if (y - ((((x - x1) / (x2 - x1)) * (y2 - y1)) + y1) < 0) {
			return true;
		}
	}
	return false;
}

int findMax(vector<int> v,bool x) {
	int o = 0;
	if (!x) {
		o = 1;
	}
	int max = -1;
	for (int i = o; i < v.size()-1; i+=2) {
		if (v.at(i) > max) max = v.at(i);
	}
	return max;
}
int findMin(vector<int> v,bool x) {
	int o = 0;
	if (!x) {
		o = 1;
	}
	int min = 999;
	for (int i = o; i < v.size()-1; i+=2) {
		if (v.at(i) < min) min = v.at(i);
	}
	return min;
}

void ParticleGraphics::drawPolygon(vector<int> v) {
    //lines
	//	flat going left - up
	//	flat going right - down
	//	down slope going up - up
	//	down slope going down - down
	//	up slope going down - up
	//	up slope going up - down
	//	wall going up - up
	//	wall going down - down
	vector<bool> boo;
	v.push_back(v.at(0));
	v.push_back(v.at(1));
	for (int i = 2; i < v.size()-1; i+=2) {
		drawLine(v.at(i),v.at(i+1),v.at(i-2),v.at(i-1));
		bool bo = true;
		int x1 = v.at(i-2);
		int y1 = v.at(i-1);
		int x2 = v.at(i);
		int y2 = v.at(i+1);
		if (((y1 == y2) && (x2 > x1)) || ((y2 < y1) && (x2 > x1)) || ((y2 > y1) && (x2 > x1)) || ((y2 < y1) && (x1 == x2))) {
			bo = false;
		}
		boo.push_back(bo);
	}

	int a = findMin(v,false);
	int b = findMax(v,true);
	int c = findMax(v,false);
	int d = findMin(v,true);

	for (int i = a; i <= c; i++) {
		for (int j = d; j <= b; j++) {
	  		bool sp = true;
			for (int k = 2; k < v.size()-1; k+=2) {
				if (!isIn(j,i,boo.at((k / 2) - 1), v.at(k-2), v.at(k-1), v.at(k), v.at(k+1))) {
	  				sp = false;
					//setColor({0,0,255});
					//drawPoint(i,j);
				}
			}
			if (sp) {
				setColor({255,0,0});
				drawPoint(i,j);
			}
			else {
				setColor({0,255,0});
				drawPoint(i,j);
			}
		}
	}
}


Color::Color(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_b) {
	if(new_r < 0 || new_g < 0 || new_b < 0) die();
	else if(new_r > 255 || new_b > 255 || new_g > 255) die();
	//r, g, and b must be greater than or equal to 0 and less or equal to  255
}

