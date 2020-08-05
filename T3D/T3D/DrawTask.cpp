// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#include <math.h>
#include "DrawTask.h"

namespace T3D {

	DrawTask::DrawTask(T3DApplication* app, Texture* tex) : Task(app) {
		drawArea = tex;
		init();
	}


	DrawTask::~DrawTask(void) {
	}


	void DrawTask::init() {
		drawArea->clear(Colour(0, 0, 0, 255));
		//drawDDALine(100,100,200,200,Colour(0,0,0,255));

		int lineBase = 10;
		int lineLength = 600 + lineBase;
		int lineRepeats = 12;
		int x = lineBase;
		int y = lineLength;

		// Console debug header
		std::cout << "|   X\t Y\t" << "i  |" << "\n";
		std::cout << "|------------------|" << "\n";

		// Draw DDA lines
		for (int i = 0; i <= lineRepeats; i++) {
			drawDDALine(lineBase, lineBase, x, y, Colour(255, 0, 0, 255));
			std::cout << "  " << x << "\t" << y << "\t" << i << "\n";

			x = x + (lineLength / lineRepeats);
			y = y - (lineLength / lineRepeats);
		}

		// Reset coords
		x = lineBase;
		y = lineLength;

		// Draw Bres lines
		for (int i = 0; i <= lineRepeats; i++) {
			drawBresLine(lineBase, lineBase, x, y, Colour(0, 255, 0, 255));
			std::cout << "  " << x << "\t" << y << "\t" << i << "\n";

			x = x + (lineLength / lineRepeats);
			y = y - (lineLength / lineRepeats);
		}
	}


	void DrawTask::drawDDALine(int x1, int y1, int x2, int y2, Colour c) {
		// Calculate delta
		int deltaX = (x2 - x1);
		int deltaY = (y2 - y1);

		// Calculate steps
		int steps = abs(deltaX) > abs(deltaY) ? abs(deltaX) : abs(deltaY);

		// Calculate increments for each step
		float incX = deltaX / (float)steps;
		float incY = deltaY / (float)steps;

		// Draw pixels for each step
		float x = (float)x1;
		float y = (float)y1;

		for (int i = 0; i <= steps; i++) {
			drawArea->plotPixel((int)x, (int)y, c);
			x += incX;
			y += incY;
		}
	}


	void DrawTask::drawBresLine(int x1, int y1, int x2, int y2, Colour c) {
		// Calculate delta
		int deltaX = x2 - x1;
		int deltaY = y2 - y1;
		int error = deltaX - deltaY;

		// Calculate steps
		int stepX = x1 < x2 ? 1 : -1;
		int stepY = y1 < y2 ? 1 : -1;

		// Draw pixels for each step
		int x = x1;
		int y = y1;

		while (x != x2 || y != y2) {
			drawArea->plotPixel(x, y, c);

			int err = error;

			if (err < deltaX) {
				error += deltaX;
				y += stepY;
			}

			if (err > -deltaY) {
				error -= deltaY;
				x += stepX;
			}
		}
	}


	void DrawTask::update(float dt) {
		//drawArea->clear(Colour(255,255,255,255));

		app->getRenderer()->reloadTexture(drawArea);
	}
}