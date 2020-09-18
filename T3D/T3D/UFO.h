/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * UFO Sweep for Assignment 1 - Task 1: Sweep
*/

#pragma once
#include "GameObject.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Math.h"
#include <vector>

namespace T3D {
	using std::vector;

	class UFO :
		public GameObject
	{
	public:
		UFO(T3DApplication* app);
		~UFO(void);

		GameObject* ufo;
		SweepPath ufosp;
		Transform t;
	};
}