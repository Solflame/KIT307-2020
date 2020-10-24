/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * T3D Application for Assignment 2
*/

#pragma once
#include "WinGLApplication.h"
#include "Camera.h"
//#include "KeyboardController.h"
#include "Animation.h"
#include "Music.h"
#include "Hat.h"
#include "Robot.h"
#include "Dumpster.h"
#include "Drone.h"
#include "Shop.h"


namespace T3D {

	class Assignment2Test :
		public WinGLApplication {
	public:
		Assignment2Test(void);
		~Assignment2Test(void);

		bool init();

	private:
		Music* backgroundMusic;

		const float DEG_0 = 0;
		const float DEG_45 = Math::HALF_PI / 2;
		const float DEG_90 = Math::HALF_PI;
		const float DEG_135 = Math::HALF_PI + Math::HALF_PI / 2;
		const float DEG_180 = Math::PI;
		const float DEG_270 = Math::PI + Math::HALF_PI;
		const float DEG_360 = Math::TWO_PI;
	};
}