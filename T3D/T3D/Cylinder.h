/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Cylinder mesh
*/

#pragma once
#include "Mesh.h"
#include "Math.h"

namespace T3D {
	class Cylinder :
		public Mesh
	{
	public:
		Cylinder(float radius, float height, int density);
		~Cylinder(void);
	};
}