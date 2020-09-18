/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * 'hole-in-the-wall' Key Mesh for Assignment 1 - Task 3: Key
*/

#pragma once
#include "Mesh.h"
#include "Math.h"
#include <vector>

namespace T3D {
	using std::vector;

	class Key :
		public Mesh
	{
	public:
		Key(
			int d,				// Density of the key head (outer and inner cylinder)
			float r1,			// Radius of the hole in the key head
			float r2,			// Outer radius of the key head (r1 < r2)
			float offset,		// Displacement of the hole in the key head
			float depth,		// Uniform thickness of the key
			float seglength,	// Length of each segment of the key stem
			float segwidth,		// Maximum width of the key stem
			vector<float> code	// Width % for each segment of the key
		);

		~Key(void);
	};
}