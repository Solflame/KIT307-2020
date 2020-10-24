/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Hat sweep for Assignment 2 - Task 1: Animated Movie
*/

#ifndef HAT_H
#define HAT_H

#include "GameObject.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Math.h"
#include <vector>

namespace T3D {
	using std::vector;

	class Hat : public GameObject {
	public:
		Hat(T3DApplication* app);
		~Hat(void);


		GameObject* hat;
		SweepPath hatsp;
		Transform t;
	};
}
#endif