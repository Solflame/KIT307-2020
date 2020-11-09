/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Exam content - 2020
*/

#include "Exam2020.h"

namespace T3D {

	Exam2020::Exam2020(void) {
		//drawArea = new Texture(1024, 640, false);
		drawArea = new Texture(1024, 512, false);
		drawArea->clear(Colour(255, 255, 255, 255));

		// Initialise
		drawExamTask = NULL;
		perfLogTask = NULL;
	}


	Exam2020::~Exam2020(void) {

	}


	bool Exam2020::init() {
		WinGLApplication::init();

		renderer->loadTexture(drawArea, false);
		renderer->add2DOverlay(drawArea, 0, 0);

		drawExamTask = new DrawExamTask(this, drawArea);
		addTask(drawExamTask);

		perfLogTask = new PerfLogTask(this);
		addTask(perfLogTask);

		return true;
	}
}