/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * T3D Application for Assignment 1
*/

#pragma once
#include "WinGLApplication.h"
#include "Camera.h"
#include "KeyboardController.h"
#include "UFO.h"
#include "Robot.h"
#include "Key.h"

namespace T3D {

	class Assignment1Test :
		public WinGLApplication {
	public:
		Assignment1Test(void);
		~Assignment1Test(void);

		bool init();

	private:

	};
}