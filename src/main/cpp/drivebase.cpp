#include <iostream>
#include <drivebase.h>

using namespace frc;


// run this in TeleopPeriodic
void Drivebase :: update () {

	//std::cout<<"updating drivebase";

	// collect values from joystick
	move = -1 *joy0->GetRawAxis( drivebase_move_joynum );
	turn = joy0->GetRawAxis( drivebase_turn_joynum );

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	move = signedpow(move,drivebase_move_exp);
	turn = signedpow(turn,drivebase_turn_exp);

	//std::cout<<"\tskewed move = "<<move<<"\tskewed turn = "<<turn;

	// scale the values based on the max allowed speed
	move *= drivebase_max_speed;
	turn *= drivebase_max_speed;

	// write to motors
	talon_left_enc->Set(ControlMode::PercentOutput,  move+turn);
	talon_right_enc->Set(ControlMode::PercentOutput, -move+turn);

	//std::cout<<"\tleft moving at speed "<<move-turn<<"\tright moving at speed "<<move+turn<<std::endl;
};
