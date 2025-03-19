#include "graphics.h"

using namespace std;

void ParticleGraphics::drawPoint(int r, int c) {
	movecursor(r,c);
	setbgcolor(color.r,color.g,color.b);
	cout << " " << flush;
}
