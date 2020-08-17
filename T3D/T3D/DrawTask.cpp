// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#define _USE_MATH_DEFINES
#include <math.h>
#include "DrawTask.h"

namespace T3D {

	DrawTask::DrawTask(T3DApplication* app, Texture* tex) : Task(app) {
		drawArea = tex;
		debug = true;
		init();
	}


	DrawTask::~DrawTask(void) {
	}


	void DrawTask::init() {
		drawArea->clear(Colour(0, 0, 0, 255));

		int offset = 10;

		/* ============
		*	Draw lines
		*  ============*/
		int lineBaseX = offset;
		int lineBaseY = offset;
		int lineLength = 300;
		int lineNum = 12;

		// Draw DDA lines
		int x = lineBaseX + lineLength;
		int y = lineBaseY;

		if (debug) // Console debug header
			std::cout << "\nDEBUG\tDDA lines" << "\n" << "\t[X]\t[Y]\t[I]" << "\n";

		for (int i = 0; i <= lineNum; i++) {
			if (debug) // Console debug values
				std::cout << ">>\t" << x << "\t" << y << "\t" << i + 1 << "\n";

			drawDDALine(lineBaseX, lineBaseY, x, y, Colour(255, 0, 0, 255));

			x -= (lineLength / lineNum);
			y += (lineLength / lineNum);
		}

		// Draw Bres lines
		x = lineBaseX + lineLength;
		y = lineBaseY;

		if (debug) // Console debug header
			std::cout << "\nDEBUG\tBres lines" << "\n" << "\t[X]\t[Y]\t[I]" << "\n";

		for (int i = 0; i <= lineNum; i++) {
			if (debug) // Console debug values
				std::cout << ">>\t" << x << "\t" << y << "\t" << i + 1 << "\n";

			drawBresLine(x, y, lineBaseX + lineLength, lineBaseY + lineLength, Colour(0, 255, 0, 255));

			x -= (lineLength / lineNum);
			y += (lineLength / lineNum);
		}


		/* ==============
		*	Draw circles
		*  ==============*/
		int circleBaseX = offset;
		int circleBaseY = offset;
		int circleSize = 150;
		int circleNum = 12;

		// Draw trigonometry circles
		x = circleBaseX + 450 + offset;
		y = circleBaseY + 150;
		int r = circleSize;

		if (debug) // Console debug header
			std::cout << "\nDEBUG\tTrig circles" << "\n" << "\t[X]\t[Y]\t[R]\t[I]" << "\n";

		for (int i = 0; i < circleNum; i++) {
			if (debug) // Console debug values
				std::cout << ">>\t" << x << "\t" << y << "\t" << r << "\t" << i + 1 << "\n";

			drawTrigCircle(x, y, r, Colour(0, 255, 255, 255));

			r -= (circleSize / circleNum);
		}

		// Draw pythagoras circles
		x = circleBaseX + 150;
		y = circleBaseY + 450 + offset;
		r = circleSize;

		if (debug) // Console debug header
			std::cout << "\nDEBUG\tPyth circles" << "\n" << "\t[X]\t[Y]\t[R]\t[I]" << "\n";

		for (int i = 0; i < circleNum; i++) {
			if (debug) // Console debug values
				std::cout << ">>\t" << x << "\t" << y << "\t" << r << "\t" << i + 1 << "\n";

			drawPythCircle(x, y, r, Colour(255, 0, 255, 255));

			r -= (circleSize / circleNum);
		}

		// Draw bres circles
		x = circleBaseX + 450 + offset;
		y = circleBaseY + 450 + offset;
		r = circleSize;

		if (debug) // Console debug header
			std::cout << "\nDEBUG\tBres circles" << "\n" << "\t[X]\t[Y]\t[R]\t[I]" << "\n";

		for (int i = 0; i < circleNum; i++) {
			if (debug) // Console debug values
				std::cout << ">>\t" << x << "\t" << y << "\t" << r << "\t" << i + 1 << "\n";

			drawBresCircle(x, y, r, Colour(255, 255, 0, 255));

			r -= (circleSize / circleNum);
		}


		/* ==================
		*	In-Semester Test
		*  ==================*/

		// Draw Triangles
		vector<Vector3> points = {
			{Vector3(100, 100, 0)}, {Vector3(200, 100, 0)}, {Vector3(100, 200, 0)},
			{Vector3(500, 500, 0)}, {Vector3(520, 520, 0)}, {Vector3(500, 520, 0)},
			{Vector3(300, 300, 0)}, {Vector3(500, 500, 0)}
		};
		drawTriangles(points);

		// Draw Arrow
		int arrowOffset = 25;
		int arrowPointX = 500;
		int arrowPointY = 400;
		int arrowEdgeX = arrowPointX + arrowOffset;
		int arrowEdgeY = arrowPointY - (arrowOffset * 2);
		int arrowHeight = 200;

		drawArrow1(arrowPointX, arrowPointY, arrowEdgeX, arrowEdgeY, arrowOffset, arrowHeight);
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


	void DrawTask::drawTrigCircle(int cx, int cy, int r, Colour c) {
		double theta;

		// Calculate steps
		double step = 2 * M_PI / 750;

		// Draw pixels for each step
		int x = cx;
		int y = cy;

		for (theta = 0; theta < M_PI / 4; theta += step) {
			x = (int)(r * cos(theta));
			y = (int)(r * sin(theta));

			// Mirror for each segment
			drawArea->plotPixel(cx + x, cy + y, c);
			drawArea->plotPixel(cx + y, cy + x, c);
			drawArea->plotPixel(cx + x, cy - y, c);
			drawArea->plotPixel(cx + y, cy - x, c);
			drawArea->plotPixel(cx - x, cy + y, c);
			drawArea->plotPixel(cx - y, cy + x, c);
			drawArea->plotPixel(cx - x, cy - y, c);
			drawArea->plotPixel(cx - y, cy - x, c);
		}
	}


	void DrawTask::drawPythCircle(int cx, int cy, int r, Colour c) {
		// Draw pixels for each step
		int x = cx;

		for (int y = 0; y <= r / sqrt(2); y++) {
			x = (int)sqrt(r * r - y * y);

			// Mirror for each segment
			drawArea->plotPixel(cx + x, cy + y, c);
			drawArea->plotPixel(cx + y, cy + x, c);
			drawArea->plotPixel(cx + x, cy - y, c);
			drawArea->plotPixel(cx + y, cy - x, c);
			drawArea->plotPixel(cx - x, cy + y, c);
			drawArea->plotPixel(cx - y, cy + x, c);
			drawArea->plotPixel(cx - x, cy - y, c);
			drawArea->plotPixel(cx - y, cy - x, c);
		}
	}


	void DrawTask::drawBresCircle(int cx, int cy, int r, Colour c) {
		// Draw pixels for each step
		int x = 0;
		int y = r;
		int d = 3 - (2 * r);

		while (y >= x) {
			x++;

			// Find next decision
			if (d > 0) {
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else {
				d = d + 4 * x + 6;
			}

			// Mirror for each segment
			drawArea->plotPixel(cx + x, cy + y, c);
			drawArea->plotPixel(cx + y, cy + x, c);
			drawArea->plotPixel(cx + x, cy - y, c);
			drawArea->plotPixel(cx + y, cy - x, c);
			drawArea->plotPixel(cx - x, cy + y, c);
			drawArea->plotPixel(cx - y, cy + x, c);
			drawArea->plotPixel(cx - x, cy - y, c);
			drawArea->plotPixel(cx - y, cy - x, c);
		}
	}


	void DrawTask::drawTriangles(vector<Vector3> points) {
		// Caluculate the number of triangles to draw
		int n = points.size() / 3;

		// Draw triangle for each triplet of points
		std::cout << "\nDEBUG\tTriangles" << "\n" << "\t| I |\t[A]\t\t[B]\t\t[C]" << "\n";

		for (int i = 0; i < n * 3; i += 3) {
			// Console debug values
			std::cout << "\t| " << i << " |";
			std::cout << "\t(" << points[i].x << ", " << points[i].y << ")";
			std::cout << "\t(" << points[i + 1].x << ", " << points[i + 1].y << ")";
			std::cout << "\t(" << points[i + 2].x << ", " << points[i + 2].y << ")";
			std::cout << "\n";

			drawDDALine((int)points[i].x, (int)points[i].y, (int)points[i + 1].x, (int)points[i + 1].y, Colour(0, 255, 0, 255));
			drawDDALine((int)points[i + 1].x, (int)points[i + 1].y, (int)points[i + 2].x, (int)points[i + 2].y, Colour(0, 255, 0, 255));
			drawDDALine((int)points[i + 2].x, (int)points[i + 2].y, (int)points[i].x, (int)points[i].y, Colour(0, 255, 0, 255));
		}
	}


	void DrawTask::drawArrow1(int x1, int y1, int x2, int y2, int r, int d) {
		// Define arrow colour
		Colour c = Colour(255, 0, 0, 255);

		// Draw arrow point
		int offset = x2 - x1;

		for (int i = 0; i < offset; i++) {
			drawDDALine(x1, y1, x1 + i, y2, c);
			drawDDALine(x1, y1, x1 - i, y2, c);
		}

		// Draw arrow shaft and curve
		int x = x1;
		int h = y1 - d;

		for (int y = 0; y <= r / sqrt(2); y++) {
			x = (int)sqrt(r * r - y * y);

			drawDDALine(x1 + x, y2, x1 + x, h + y, c);
			drawDDALine(x1 + y, y2, x1 + y, h + x, c);
			drawDDALine(x1 - x, y2, x1 - x, h + y, c);
			drawDDALine(x1 - y, y2, x1 - y, h + x, c);
		}
	}


	void DrawTask::update(float dt) {
		//drawArea->clear(Colour(255,255,255,255));

		app->getRenderer()->reloadTexture(drawArea);
	}
}