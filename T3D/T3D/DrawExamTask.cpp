/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Task for drawing and animating shapes - Exam Content
*/

#define _USE_MATH_DEFINES
#include "DrawExamTask.h"

namespace T3D {

	DrawExamTask::DrawExamTask(T3DApplication* app, Texture* tex) : Task(app) {
		drawArea = tex;

		// Window area bounds
		wTop = 0;
		wBot = drawArea->getHeight();
		wLeft = 0;
		wRight = drawArea->getWidth();

		polyBL = { (float)wLeft + (wRight / 4), (float)wBot - (wBot / 3), 1 };
		polyTR = { (float)wRight - (wRight / 4), (float)wTop + (wBot / 3), 1 };

		polyVertices.push_back(polyBL);
		polyVertices.push_back(polyTR);

		//polyCoords = Matrix3x3::IDENTITY;

		init();
	}


	DrawExamTask::~DrawExamTask(void) {

	}


	void DrawExamTask::init() {
		drawArea->clear(Colour(0, 0, 0, 255));

		// Window border
		drawBorder(wTop, wBot, wLeft, wRight, 1, Colour(255, 255, 0, 255));

		// Center cross
		/*drawBresLine(0, 0, 1024, 512, Colour(255, 255, 0, 255));
		drawBresLine(0, 512, 1024, 0, Colour(255, 255, 0, 255));*/

		/*drawParallelogram(wLeft + 100, wBot - 150, wRight - 100, wTop + 150, (int)(wRight / 1.5), Colour(255, 0, 0, 255));*/

		//drawPie(512, 256, 100, 45, Colour(0, 255, 0, 255));
	}


	void DrawExamTask::drawBresLine(int x1, int y1, int x2, int y2, Colour c) {
		// Calculate delta
		int deltaX = abs(x2 - x1);
		int deltaY = abs(y2 - y1);
		int error = deltaX - deltaY;

		// Calculate steps
		int stepX = x1 < x2 ? 1 : -1;
		int stepY = y1 < y2 ? 1 : -1;

		// Draw pixels for each step
		int x = x1;
		int y = y1;

		while (x != x2 || y != y2) {
			// Ensure pixel is within bounds
			if (x < drawArea->getWidth() && y < drawArea->getHeight()) {
				drawArea->plotPixel(x, y, c);
			}

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


	void DrawExamTask::drawBorder(int top, int bot, int left, int right, int offset, Colour c) {
		// Draw a line for each edge
		drawBresLine(left + offset, top + offset, right - offset, top + offset, c);		// Top edge
		drawBresLine(left + offset, bot - offset, right - offset, bot - offset, c);		// Bottom edge
		drawBresLine(left + offset, top + offset, left + offset, bot - offset, c);		// Left edge
		drawBresLine(right - offset, top + offset, right - offset, bot - offset, c);	// Right edge
	}


	void DrawExamTask::drawShape(Colour c) {

	}


	void DrawExamTask::drawPie(int cx, int cy, int r, double degree, Colour c) {
		double range = degree * Math::DEG2RAD;
		double step = range / (180 / M_PI);
		double x = 0;
		double y = r;

		// Draw first line
		drawBresLine(cx, cy, cx + (int)y, cy + (int)x, c);

		// Draw arc and fill
		for (double angle = 0; angle < range; angle += step) {
			x = (r * cos(angle));
			y = (r * sin(angle));

			drawArea->plotPixel(cx + (int)x, cy - (int)y, c);
			drawBresLine(cx, cy, cx + (int)x, cy - (int)y, c);
		}

		// Draw second line
		drawBresLine(cx, cy, cx + (int)y, cy - (int)x, c);
	}


	void DrawExamTask::drawParallelogram(int x1, int y1, int x2, int y2, int w, Colour c) {
		// Edge limits
		int xMin, xMax, yMin, yMax;

		// Number of vertices
		int vertices = 4;
		int count = 0;

		// Vertex coordinates
		vector<Vector3> v;
		v.resize(vertices + 1);

		// Define vertices
		v[count].x = (float)x1, v[count].y = (float)y1;	// Bottom Left
		count++;
		v[count].x = (float)x1 + w, v[count].y = (float)y1;	// Bottom Right
		count++;
		v[count].x = (float)x2, v[count].y = (float)y2;	// Top Right
		count++;
		v[count].x = (float)x2 - w, v[count].y = (float)y2;	// Top Left

		// Vertex for ease of connecting the last and first vertices
		count++;
		v[count].x = v[0].x, v[count].y = v[0].y;

		// Initialise edge limits
		xMin = xMax = (int)v[0].x;
		yMin = yMax = (int)v[0].y;

		// Calculate the edge limits
		for (int i = 0; i < vertices; i++) {
			if (xMin > v[i].x)
				xMin = (int)v[i].x;
			if (xMax < v[i].x)
				xMax = (int)v[i].x;
			if (yMin > v[i].y)
				yMin = (int)v[i].y;
			if (yMax < v[i].y)
				yMax = (int)v[i].y;
		}

		// Draw the outline
		for (int i = 0; i < vertices; i++) {
			drawBresLine((int)v[i].x, (int)v[i].y, (int)v[i + 1].x, (int)v[i + 1].y, c);
		}

		// Fill the polygon using horizontal lines
		fillPolygon(v, xMin, xMax, yMin, yMax, c);
	}


	void DrawExamTask::fillPolygon(vector<Vector3> v, int xMin, int xMax, int yMin, int yMax, Colour c) {
		float step = yMin + 0.01f;	// Inital step value
		int vertices = v.size() - 1;	// Number of vertices
		int count;	// Counter
		int x;	// X coordinate

		// Calculate the fill range
		while (step <= yMax) {
			int x1, x2, y1, y2, temp;
			count = 0;

			// Fill coordinates
			vector<int> f;
			f.resize(vertices + 1);

			// Define fill coordinates
			for (int i = 0; i < vertices; i++) {
				x1 = (int)v[i].x;
				y1 = (int)v[i].y;
				x2 = (int)v[i + 1].x;
				y2 = (int)v[i + 1].y;

				if (y2 < y1) {
					temp = x1;
					x1 = x2;
					x2 = temp;
					temp = y1;
					y1 = y2;
					y2 = temp;
				}

				// Check that the step value is within bounds
				if (step <= y2 && step >= y1) {
					// Calculate the X value
					if ((y1 - y2) == 0) {
						x = x1;
					}
					else {
						x = (int)(((x2 - x1) * (step - y1)) / (y2 - y1));
						x += x1;
					}

					// Check that the X value is within bounds
					if (x <= xMax && x >= xMin) {
						f[count++] = x;
					}
				}
			}

			// Draw horizontal fill
			for (int i = 0; i < count; i += 2) {
				drawBresLine(f[i], (int)step, f[i + 1], (int)step, c);
			}

			step++;
		}
	}


	void DrawExamTask::update(float dt) {
		drawArea->clear(Colour(0, 0, 0, 255));


		polyVertices[0].x += 0.5;

		drawParallelogram(
			(int)polyVertices[0].x,		// Left
			(int)polyVertices[0].y,		// Bottom
			(int)polyVertices[1].x,		// Right
			(int)polyVertices[1].y,		// Top
			(int)(polyVertices[1].x / 2),	// Width
			Colour(255, 0, 0, 255));		// Colour


		//drawParallelogram(wLeft + 100, wBot - 150, wRight - 100, wTop + 150, (int)(wRight / 1.5), Colour(255, 0, 0, 255));

		app->getRenderer()->reloadTexture(drawArea);
	}
}