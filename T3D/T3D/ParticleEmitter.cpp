// Author: David Pentecost
//
// ParticleEmitter.cpp
//
// Particle emitter and controller
// This is a generic particle creator that can be used with any particles that have the
// ParticleBehaviour component.

#include <stdlib.h>

#include "Math.h"
#include "GameObject.h"
#include "Renderer.h"
#include "T3DApplication.h"
#include "Transform.h"
#include "ParticleEmitter.h"
#include "ParticleBehaviour.h"


namespace T3D
{
	// Constructor
	ParticleEmitter::ParticleEmitter(float duration, float startRate, float emitRate, float endRate,
		float startUpTime, float windDownTime)
	{
		this->emitted = 0;							// no particles emitted
		this->elapsed = 0;							// starting

		this->duration = duration;					// total run time (particle emission stops when this reached)

		this->startRate = startRate;				// particles per second at time 0
		this->emitRate = emitRate;					// normal particles per second emit rate
		this->endRate = endRate;					// particles per second when duration time reached

		this->rampUpDuration = startUpTime;			// ramp up time from startRate to emitRate
		this->rampDownDuration = windDownTime;		// wind down time from emitRate to endRate
	}

	// Destructor
	// deletes all particles
	ParticleEmitter::~ParticleEmitter()
	{
		for (unsigned int i=0; i<particles.size(); i++)
		{
			// NOTE: delete gameObjects by deleting their Transform
			delete particles[i]->gameObject->getTransform();		
		}
	}

	// addParticle
	// Adds a particle to the available pool.
	// Particles can be started (emitted) immediately if required
	void ParticleEmitter::addParticle(ParticleBehaviour *particle, bool start)
	{
		particles.push_back(particle);			// add to pool

		if (start) {
			particle->start(this->gameObject->getTransform());	// start relative to emitter
		}
		else {
			particle->stop();	// particle will be added to particlesInactive
		}
	}

	// addInactiveList
	//  Adds particle to inactive list for reuse
	// This is intended only to be used by particles
	// to add themselves back into the inactive list for reuse
	void ParticleEmitter::addInactiveList(ParticleBehaviour *particle)
	{
		particlesInactive.push(particle);
	}

	// stop
	// Stop particle system (moves elapsed time to full duration)
	//   param clear	stops and hide all active particles immediately
	void ParticleEmitter::stop(bool clear)
	{
		elapsed = duration;			// no more particles will be emitted

		if (clear)					// stop and remove all active particles?
		{
			for (unsigned int i=0; i<particles.size(); i++)
			{
				if (!particles[i]->isActive())
					particles[i]->stop();
			}
		}

	}

	// emit particles immediately
	//    param n		number of particles to emit
	// Note the total number of particles is limited by the particle pool size
	void ParticleEmitter::emit(int n)
	{
		ParticleBehaviour *particle;

		// Emit required number of particles but only up to what is available
		while (n > 0 && !particlesInactive.empty())
		{
			particle = particlesInactive.front();
			particlesInactive.pop();		// remove from inactive list
			particle->start(this->gameObject->getTransform());
			n--;
		}
	}

	// update
	// regular system update, generate particles as required
	//   param dt	elapsed time since last frame
	void ParticleEmitter::update(float dt)
	{
		float count;
		std::list<ParticleBehaviour *>::iterator i;

		elapsed += dt;			// total particle system run time

		if (elapsed < duration)
		{
			// work out how many particles should have been emitted for the current elapsed time
			// Includes ramp up, run and wind down as appropriate

			// Get expected particles for initial ramp up
			count = emitRamp(startRate, emitRate, rampUpDuration, elapsed, 0.1f);

			// Plus particles for constant run
			count += emitRamp(emitRate, emitRate, duration - (rampUpDuration+rampDownDuration), elapsed - rampUpDuration, 0.1f);

			// Plus particles for wind down
			count += emitRamp(emitRate, endRate, rampDownDuration, elapsed - (duration - rampDownDuration), 0.1f);

			//std::cout << "expected particles for time " << elapsed << " is " << count << ", particles emitted so far " << emitted << std::endl;

			// count is now the total number of particles (with some random variability) that should have
			// been generated by this time in the particles systems life. 
			count -= emitted;	// minus the number already emitted to give how many we need to emit now

			int e = (int)(count + 0.5f);	// emit rounded up output count
			emit(e);						// emit particles
			emitted += e;					// total emitted so far
		}
	}

	/*! emitRamp
	  get total expected particle count for a time position along an acceleration ramp
	  \param start		particles per second at start
	  \param end		particles per second at end
	  \param duration	duration of ramp
	  \param time		time pos (no particles if < 0 or max particles if > duration)
	  \param			random varaibility (+/- fraction)
	  */
	float ParticleEmitter::emitRamp(float start, float end, float duration, float time, float variability)
	{
		float accel;		// calculated acceration rate for ramp
		float count;		// expected number of particles produced to the given time

		if (time < 0 || duration <= 0) return 0;		// not in ramp or no ramp

		if (time > duration) time = duration;	// clamp time to max duration of ramp

		accel = (end - start) / duration;		// particles per second per second
		count = start * time + (accel * time * time) / 2.0f;
		count += count * (Math::randRange(0, variability*2) - variability);

		return count;
	}



}