#ifndef _PNEUMATICS_H_
#define _PNEUMATICS_H_

/**
 * \file pneumatics.h
 *
 * Pneumatics subsystem declarations
 */

// Pneumatics actuator states
struct PneumaticsState {
	bool matchloader;
	bool pto;
	bool park;
	bool score_mid;
	bool score_low;
};

void pneumatics_init();
void pneumatics_actuate(bool extend);
void pneumatics_retract();
void pneumatics_set_state(const PneumaticsState& state);
PneumaticsState pneumatics_get_state();

// Convenience functions for individual actuators
void pneumatics_set_matchloader(bool enable);
void pneumatics_set_pto(bool enable);
void pneumatics_set_park(bool enable);
void pneumatics_set_score_mid(bool enable);
void pneumatics_set_score_low(bool enable);

#endif // _PNEUMATICS_H_
