#include <sandstorm.h>

#define L1_STRAIGHT_ONE 136
#define L1_TURN_BEGIN -34
#define L1_STRAIGHT_TWO 23
#define L1_TURN_SECOND 43
#define L1_STRAIGHT_THREE 123

#define L2_STRAIGHT_BEGIN 187
#define L2_TURN_ONE -90
#define L2_STRAIGHT_END 0

#define L3_STRAIGHT_BEGIN (187 + 21)
#define L3_TURN_ONE -90
#define L3_STRAIGHT_END 0

#define L4_STRAIGHT_BEGIN (187 + (2 * 21))
#define L4_TURN_ONE -90
#define L4_STRAIGHT_END 0

int Sandstorm::path_one(){ //From Left Hab to L1
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L1_STRAIGHT_ONE);
	}
	if (mode == 3){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(-1, L1_TURN_BEGIN);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L1_STRAIGHT_TWO);
	}
	if (mode == 6){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 7){
		turn(1, L1_TURN_SECOND);
	}
	if (mode == 8){
		wipe();
	}
	if (mode == 9){
		straight_away(L1_STRAIGHT_THREE);
	}
	if (mode == 2){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_two(){ //From Left Hab to L2
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L2_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(-1, L2_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L2_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_three(){ //From Left Hab to L3
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L3_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(-1, L3_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L3_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_four(){ //From Left Hab to L4
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L4_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(-1, L4_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L4_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_five(){
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L1_STRAIGHT_ONE);
	}
	if (mode == 3){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(1, -1 * L1_TURN_BEGIN);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L1_STRAIGHT_TWO);
	}
	if (mode == 6){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 7){
		turn(-1, -1 * L1_TURN_SECOND);
	}
	if (mode == 8){
		wipe();
	}
	if (mode == 9){
		straight_away(L1_STRAIGHT_THREE);
	}
	if (mode == 2){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_six(){
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L2_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(1, -1 * L2_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L2_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_seven(){
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L3_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(1, -1 * L3_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L3_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

int Sandstorm::path_eight(){
	if (mode == 0){
		wipe();
	}
	if (mode == 1){
		straight_away(L4_STRAIGHT_BEGIN);
	}
	if (mode == 2){
		navx->ZeroYaw();
		mode++;
	}
	if (mode == 3){
		turn(1, -1 * L4_TURN_ONE);
	}
	if (mode == 4){
		wipe();
	}
	if (mode == 5){
		straight_away(L4_STRAIGHT_END);
	}
	if (mode == 6){
		std::cout<<"DONE"<<std::endl;
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		return 0;
	}
}

void Sandstorm::wipe(){
	talon_right->SetSelectedSensorPosition(0, 0, 10);
	talon_left->SetSelectedSensorPosition(0, 0, 10);
	mode++;
}

void Sandstorm::turn(int direction, float degrees_to_turn){
	std::cout<<"Direction: "<<direction<<std::endl;
	angle_bot_has_turned_begin = navx->GetYaw();

	if (abs(abs(angle_bot_has_turned_begin) - abs(degrees_to_turn)) <= max_angle && abs(abs(angle_bot_has_turned_begin) - abs(degrees_to_turn)) >= min_angle){
	std::cout<<"HIIIII"<<std::endl;
	velocity_turn = velocity_constant * (abs(degrees_to_turn) - abs(angle_bot_has_turned_begin));
	std::cout<<"Velocity of Turn: "<<velocity_turn * direction<<std::endl;	
		
		if (velocity_turn > max_turn_velocity){
			velocity_turn = max_turn_velocity;
			std::cout<<"I'm right here"<<std::endl;
		}
		if (velocity_turn < min_turn_velocity){
			velocity_turn = min_turn_velocity;
			std::cout<<"Now I'm here"<<std::endl;
		}
		
		if (abs(angle_bot_has_turned_begin) < abs(degrees_to_turn)){
			talon_left->Set(ControlMode::Velocity, velocity_turn * direction); 
			talon_right->Set(ControlMode::Velocity, velocity_turn * direction); 
			std::cout<<"Whoa, I'm here now"<<std::endl;
			std::cout<<"Velocity of Turn: "<<velocity_turn * direction<<std::endl;
		}
		else if (abs(angle_bot_has_turned_begin) > abs(degrees_to_turn)){
			talon_left->Set(ControlMode::Velocity, -velocity_turn * direction); 
			talon_right->Set(ControlMode::Velocity, -velocity_turn * direction);
			std::cout<<"I'm here with a pig"<<std::endl; 
			std::cout<<"Velocity of Turn: "<<velocity_turn * direction<<std::endl;
		}
			
		std::cout<<"Start turning"<<std::endl;
			
	}else if (abs(abs(angle_bot_has_turned_begin) - abs(degrees_to_turn)) > max_angle){
			if (abs(angle_bot_has_turned_begin) < abs(degrees_to_turn)){
				talon_left->Set(ControlMode::Velocity, max_turn_velocity * direction); 
				talon_right->Set(ControlMode::Velocity, max_turn_velocity * direction);

				std::cout<<"Right here right now"<<std::endl;
			}else if (abs(angle_bot_has_turned_begin) > abs(degrees_to_turn)){
				talon_left->Set(ControlMode::Velocity, -max_turn_velocity * direction); 
				talon_right->Set(ControlMode::Velocity, -max_turn_velocity * direction); 
				std::cout<<"Down here see me"<<std::endl;
			}
			std::cout<<"More left?"<<std::endl;
			std::cout<<"Velocity of Turn: "<<velocity_turn * direction<<std::endl;	
		
	}else if (abs(abs(angle_bot_has_turned_begin) - abs(degrees_to_turn)) <= min_angle){
		pid->PID_drivebase10();
		talon_left->Set(ControlMode::Velocity, 0); //0% of max velocity
		talon_right->Set(ControlMode::Velocity, 0);
		mode ++;
		std::cout<<"Dun Dun"<<std::endl;
	}
		std::cout<<"Yaw: "<<navx->GetYaw()<<std::endl;
		std::cout<<"Max Turn Velocity: "<<max_turn_velocity<<std::endl;
		std::cout<<"Right Position: "<<talon_right->GetSelectedSensorPosition(0)<<std::endl;
		std::cout<<"Left Position: "<<talon_left->GetSelectedSensorPosition(0)<<std::endl;
		std::cout<<"Right Velocity: "<<talon_right->GetSelectedSensorVelocity(0)<<std::endl;
		std::cout<<"Left Velocity: "<<talon_left->GetSelectedSensorVelocity(0)<<std::endl;
		std::cout<<"Velocity of Turn: "<<velocity_turn * direction<<std::endl;

}

void Sandstorm::straight_away(float distance_to_travel_in){
	to_travel_distance_enc = encoder_counts_per_inch * distance_to_travel_in;
	talon_left->Set(ControlMode::Velocity, thirty_speed);
	talon_right->Set(ControlMode::Velocity, -thirty_speed);
	left_position_enc = talon_left->GetSelectedSensorPosition(0);
	right_position_enc = talon_right->GetSelectedSensorPosition(0);
	std::cout<<"Left Position: "<<left_position_enc<<std::endl;
	std::cout<<"Right Position: "<<right_position_enc<<std::endl;
	std::cout<<"Travel Distance: "<<to_travel_distance_enc<<std::endl;
	std::cout<<"Condition 1: "<<abs(abs(left_position_enc) - to_travel_distance_enc)<<std::endl;
	std::cout<<"Condition 2: "<<abs(abs(right_position_enc) - to_travel_distance_enc)<<std::endl;
	if ((abs(left_position_enc) >= to_travel_distance_enc) || (abs(right_position_enc) >= to_travel_distance_enc)){
		std::cout<<"Yay!"<<std::endl;
		talon_left->Set(ControlMode::Velocity, 0); //0% of max velocity
		talon_right->Set(ControlMode::Velocity, -0);
		wipe();
		mode ++;
	}
}