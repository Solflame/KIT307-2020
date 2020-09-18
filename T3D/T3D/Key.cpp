/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * 'hole-in-the-wall' Key Mesh for Assignment 1 - Task 3: Key
*/

#include "Key.h"

namespace T3D {

	Key::Key(
		int d,				// Density of the key head (outer and inner cylinder)
		float r1,			// Radius of the hole in the key head
		float r2,			// Outer radius of the key head (r1 < r2)
		float offset,		// Displacement of the hole in the key head
		float depth,		// Uniform thickness of the key
		float seglength,	// Length of each segment of the key stem
		float segwidth,		// Maximum width of the key stem
		vector<float> code	// Width % for each segment of the key
	) {

		int segCount = code.size();	// Number of key stem segments

		// Set total variable count for the whole key
		int vHeadTotal = (d * 4) * 2;	// Total vertices for the key head
		int vStemTotal = (segCount * 4) * 2;	// Total vertices for the key stem
		int vJoinTotal = 0;	// Total vertices for the key join

		int qHeadTotal = d * 4;	// Total quads for the key head
		int qStemTotal = ((segCount - 1) * 4) + 1;	// Total quads for the key stem
		int qJoinTotal = 2;	// Total quads for the key join

		int tJoinTotal = 6 * 2; // Total triangles for the key join


		// Initiate vertex and index arrays
		initArrays(
			vHeadTotal + vStemTotal + vJoinTotal,	// Number of vertices
			tJoinTotal,	// Number of triangles
			qHeadTotal + qStemTotal + qJoinTotal	// Number of quads
		);

		float dTheta = Math::TWO_PI / d;

		// Set vertices - KEY HEAD
		for (int i = 0; i < d; i++) {
			float theta = i * dTheta;
			float holeX = r1 * cos(theta);
			float holeZ = r1 * sin(theta);
			float headX = r2 * cos(theta);
			float headZ = r2 * sin(theta);

			// Inner edge
			setVertex(i, holeX - offset, depth, holeZ);		// Top edge
			setVertex(d + i, holeX - offset, -depth, holeZ);	// Bottom edge

			// Outer edge
			setVertex((d * 2) + i, headX, depth, headZ);	// Top edge
			setVertex((d * 3) + i, headX, -depth, headZ);	// Bottom edge

			// Duplicate vertices for flat texturing

			// Inner edge
			setVertex((d * 4) + i, holeX - offset, depth, holeZ);	// Top edge
			setVertex((d * 5) + i, holeX - offset, -depth, holeZ);	// Bottom edge

			// Outer edge
			setVertex((d * 6) + i, headX, depth, headZ);	// Top edge
			setVertex((d * 7) + i, headX, -depth, headZ);	// Bottom edge
		}

		// Set vertices - KEY STEM
		for (int i = 0; i < segCount; i++) {
			int vPos = vHeadTotal + i;		// Vertex ID
			float stemX = r2 + (seglength * i);	// X position
			float backZ = -(segwidth / 2);		// Z- position
			float toothZ = (segwidth / 2);		// Z+ position

			// Back edges
			setVertex(vPos, stemX, depth, backZ);			// Top edge
			setVertex(segCount + vPos, stemX, -depth, backZ);	// Bottom edge

			// Tooth edges
			setVertex((segCount * 2) + vPos, stemX, depth, toothZ * code[i]);	// Top edge
			setVertex((segCount * 3) + vPos, stemX, -depth, toothZ * code[i]);	// Bottom edge

			// Duplicate vertices for flat texturing

			// Back edges
			setVertex((segCount * 4) + vPos, stemX, depth, backZ);	// Top edge
			setVertex((segCount * 5) + vPos, stemX, -depth, backZ);	// Bottom edge

			// Tooth edges
			setVertex((segCount * 6) + vPos, stemX, depth, toothZ * code[i]);	// Top edge
			setVertex((segCount * 7) + vPos, stemX, -depth, toothZ * code[i]);	// Bottom edge
		}


		// Set Quads - KEY HEAD
		for (int i = 0; i < d; i++) {
			int o = d + i;	// Outer count
			int t = d + o;	// Top count
			int b = d + t;	// Bottom count

			// Inner faces
			setFace(
				i,
				(i + 1) % d,
				i,
				d + i,
				d + (i + 1) % d
			);

			// Outer faces
			setFace(
				o,
				d + o,
				(d * 2) + (o + 1) % d,
				(d * 3) + (o + 1) % d,
				(d * 2) + o
			);

			// Top faces
			setFace(
				t,
				(d * 4) + i,
				(d * 4) + (i + 1) % d,
				(d * 6) + (o + 1) % d,
				(d * 5) + o
			);

			// Bottom faces
			setFace(
				b,
				(d * 5) + (i + 1) % d,
				(d * 5) + i,
				(d * 6) + o,
				(d * 7) + (o + 1) % d
			);
		}

		// Set Quads - KEY STEM
		for (int i = 0; i < segCount - 1; i++) {
			int qStemID = qHeadTotal + i;
			int vStemID = vHeadTotal + i;

			// Back faces
			setFace(
				qStemID,
				vStemID,
				vStemID + 1,
				vStemID + 1 + segCount,
				vStemID + segCount
			);

			// Tooth faces
			setFace(
				qStemID + segCount - 1,
				vStemID + 1 + (segCount * 2),
				vStemID + (segCount * 2),
				vStemID + (segCount * 3),
				vStemID + 1 + (segCount * 3)
			);

			// Top faces
			setFace(
				qStemID + ((segCount - 1) * 2),
				vStemID + (segCount * 6),
				vStemID + 1 + (segCount * 6),
				vStemID + 1 + (segCount * 4),
				vStemID + (segCount * 4)
			);

			// Bottom faces
			setFace(
				qStemID + ((segCount - 1) * 3),
				vStemID + 1 + (segCount * 7),
				vStemID + (segCount * 7),
				vStemID + (segCount * 5),
				vStemID + 1 + (segCount * 5)
			);

			// Check for end of the key stem
			if (qStemID + ((segCount - 1) * 3 + 1) == qHeadTotal + qStemTotal - 1) {
				// Tip face
				setFace(
					qStemID + ((segCount - 1) * 3) + 1,
					vStemID + 1,
					vStemID + 1 + (segCount * 2),
					vStemID + 1 + (segCount * 3),
					vStemID + 1 + segCount
				);
			}
		}

		// Set Quads - KEY JOIN
		for (int i = 0; i < qJoinTotal - 1; i++) {
			int qJoinID = qHeadTotal + qStemTotal + i;
			int vHeadID = d * 2;
			int vStemID = vHeadTotal;

			// Back faces
			setFace(
				qJoinID,
				vHeadID + i + d - 3,
				vStemID,
				vStemID + segCount,
				vHeadID + i + (d * 2) - 3
			);

			// Tooth faces
			setFace(
				qJoinID + 1,
				vStemID + (segCount * 2),
				vHeadID + i + 3,
				vHeadID + i + 3 + d,
				vStemID + (segCount * 3)
			);
		}

		// Set Triangles - KEY JOIN
		for (int i = 0; i < tJoinTotal / 4; i++) {
			int tJoinID = i;
			int vHeadID = vHeadTotal - (d * 2);
			int vStemID = vHeadTotal + (segCount * 4);

			// Top back faces
			if (tJoinID == 0) {
				setFace(
					tJoinID,
					vStemID,
					vHeadID - i - 1 + d,
					vHeadID
				);
			}
			else {
				setFace(
					tJoinID,
					vStemID,
					vHeadID - i - 1 + d,
					vHeadID - i + d
				);
			}

			// Top tooth faces
			setFace(
				tJoinID + (tJoinTotal / 4),
				vStemID + (segCount * 2),
				vHeadID + i,
				vHeadID + i + 1
			);

			// Bottom back faces
			if (tJoinID + ((tJoinTotal / 4) * 2) == tJoinTotal / 2) {
				setFace(
					tJoinID + ((tJoinTotal / 4) * 2),
					vStemID + segCount,
					vHeadID + d,
					vHeadID - i - 1 + (d * 2)
				);
			}
			else {
				setFace(
					tJoinID + ((tJoinTotal / 4) * 2),
					vStemID + segCount,
					vHeadID - i + (d * 2),
					vHeadID - i - 1 + (d * 2)
				);
			}

			// Bottom tooth faces
			setFace(
				tJoinID + ((tJoinTotal / 4) * 3),
				vStemID + (segCount * 3),
				vHeadID + i + 1 + d,
				vHeadID + i + d
			);
		}


		checkArrays();
		calcNormals();

	}


	Key::~Key(void) {

	}
}