#include "graphics.h"

using namespace std;

void ParticleGraphics::drawPoint(int x, int y) {
	movecursor(y,x);
	setbgcolor(color.r,color.g,color.b);
	cout << " " << flush;
}
