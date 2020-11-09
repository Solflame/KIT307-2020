/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Task for drawing and animating shapes - Exam Content
*/

#ifndef DRAW_EXAM_TASK_H
#define DRAW_EXAM_TASK_H

#include "T3DApplication.h"
#include "Task.h"
#include "Texture.h"
#include <math.h>

namespace T3D {

	class DrawExamTask : public Task {

	public:
		DrawExamTask(T3DApplication* app, Texture* tex);
		~DrawExamTask(void);

		void init();


		/**
		 * Draws a line using the Bres algorithm.
		 */
		void drawBresLine(int x1, int y1, int x2, int y2, Colour c);


		/**
		 * Draws a border around the edges of a texture.
		 *
		 * @param top: Top edge value
		 * @param bot: Bottom edge value
		 * @param left: Left edge value
		 * @param right: Right edge value
		 * @param offset: Distance from the edges that the border will be drawn.
		 * @param c: Colour
		 */
		void drawBorder(int top, int bot, int left, int right, int offset, Colour c);


		/**
		 * Exam[2020] - Draws a filled unknown shape.
		 *
		 * @param c: Colour.
		 */
		void drawShape(Colour c);


		/**
		 * Exam[2017] - Draws a filled pie.
		 *
		 * @param cx: Center x.
		 * @param cy: Center y.
		 * @param r: Radius.
		 * @param degree: Degree of the angle.
		 * @param c: Colour.
		 */
		void drawPie(int cx, int cy, int r, double degree, Colour c);


		/**
		 * Exam[2016] - Draws a filled parallelogram.
		 *
		 * @param x1: Left.
		 * @param y1: Bottom.
		 * @param x2: Right.
		 * @param y2: Top.
		 * @param w: Base width.
		 * @param c: Colour.
		 */
		void drawParallelogram(int x1, int y1, int x2, int y2, int w, Colour c);


		/**
		 * Fills a polygon using horizontal lines.
		 *
		 * @param v: Vertex coordinates.
		 * @param xMin: Minimum X value.
		 * @param xMax: Maximum X value.
		 * @param yMin: Minimum Y value.
		 * @param yMax: Maximum Y value.
		 * @param c: Colour.
		 */
		void fillPolygon(vector<Vector3> v, int xMin, int xMax, int yMin, int yMax, Colour c);


		virtual void update(float dt);

	private:
		Texture* drawArea;

		// Window area bounds
		int wTop, wBot, wLeft, wRight;

		// Polygon coordinates
		Matrix3x3 polyCoords;
		vector<Vector3> polyVertices;
		Vector3 polyBL, polyTR;
	};
}
#endif