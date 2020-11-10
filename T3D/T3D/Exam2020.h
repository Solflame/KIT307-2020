/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Exam content - 2020
*/

#ifndef EXAM2020_H
#define EXAM2020_H

#include "WinGLApplication.h"
#include "KeyboardController.h"
#include "PerfLogTask.h"
#include "Camera.h"
#include "Animation.h"
#include "DrawExamTask.h"
#include "ExamMesh.h"
#include "ExamQ3Mesh2.h"


namespace T3D {

	class Exam2020 :
		public WinGLApplication {

	public:
		Exam2020(void);
		~Exam2020(void);

		bool init();

	private:
		Texture* drawArea;
		DrawExamTask* drawExamTask;
		PerfLogTask* perfLogTask;
	};
}
#endif