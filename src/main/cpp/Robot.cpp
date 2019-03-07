#include "Robot.h"
#include "frc/WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>//TESTED
#include <drivebase.h> //TESTED
#include <intake_wheels.h>
#include <intake_clamp.h>//TESTED
#include <intake_pivot.h>//TESTED
#include <elevator.h>
#include <climber.h>//TESTED
#include <diagnostic.h>
#include <PID.h>//TESTED

using namespace frc;

Joystick *joy0;
Joystick *joy1;

TalonSRX *talon_left_enc;
TalonSRX *talon_left_noenc;
TalonSRX *talon_right_enc; 
TalonSRX *talon_right_noenc;
TalonSRX *climber_talon_wheel;
TalonSRX *climber_talon_arm;
TalonSRX *claw_pivot_talon_enc;
TalonSRX *talon_wheels;
Servo *lock_servo;

DigitalInput * mag_switch_climber;
DigitalInput * mag_switch_claw;
DigitalInput *mag_switch_elevator;
TalonSRX *talon_clamp;
TalonSRX *talon_elevator_enc;

Drivebase *drivebase;
Intake_wheels *intake_wheels;
Climber *climber;
Intake_clamp *intake_clamp;
Intake_pivot *intake_pivot;
PID *pid;
Elevator *elevator;

void Robot::RobotInit() {
   





       joy0 = new Joystick(0);
       joy1 = new Joystick(1);

       talon_left_noenc = new TalonSRX(1);
       talon_left_enc = new TalonSRX(2);
       talon_right_noenc = new TalonSRX(3);
       talon_right_enc = new TalonSRX(4);
       claw_pivot_talon_enc = new TalonSRX(5);
       climber_talon_arm = new TalonSRX(6);
       climber_talon_wheel = new TalonSRX(7);
       talon_elevator_enc = new TalonSRX(8);
       talon_wheels = new TalonSRX(9);
       talon_clamp = new TalonSRX(10);

       talon_left_noenc->Set(ControlMode::Follower, 2);
       talon_right_noenc->Set(ControlMode::Follower, 4);
       
       lock_servo = new Servo(1);

       mag_switch_climber = new DigitalInput(2);
       mag_switch_elevator = new DigitalInput(4);
       mag_switch_claw = new DigitalInput (1);

       
       
       elevator = new Elevator(talon_elevator_enc, mag_switch_elevator, joy1);
       pid = new PID (talon_right_enc, talon_left_enc, claw_pivot_talon_enc, talon_elevator_enc);
       intake_pivot = new Intake_pivot(claw_pivot_talon_enc, joy1, mag_switch_claw);
       intake_clamp = new Intake_clamp(joy0, talon_clamp);
       drivebase = new Drivebase (joy0, talon_left_enc, talon_left_noenc, talon_right_enc, talon_right_noenc);
       climber = new Climber(joy0, mag_switch_climber, climber_talon_arm,climber_talon_wheel, lock_servo);
       intake_wheels= new Intake_wheels(joy1, talon_wheels);

       CameraServer::GetInstance()->StartAutomaticCapture();

       //TEMP CODE
       /*
       talon_left_enc->ConfigPeakOutputForward(.5, 10);
       talon_left_enc->ConfigPeakOutputReverse(-.5, 10);
       talon_left_noenc->ConfigPeakOutputForward(.5, 10);
       talon_left_noenc->ConfigPeakOutputReverse(-.5, 10);
       talon_right_noenc->ConfigPeakOutputForward(.5, 10);
       talon_right_noenc->ConfigPeakOutputReverse(-.5, 10);
       talon_right_enc->ConfigPeakOutputForward(.5, 10);
       talon_right_enc->ConfigPeakOutputReverse(-.5, 10);
       */
     //claw_pivot_talon_enc->ConfigPeakOutputForward(.75, 10);
     // claw_pivot_talon_enc->ConfigPeakOutputReverse(-.75, 10);
       climber_talon_arm->ConfigPeakOutputForward(.75, 10);
       climber_talon_arm->ConfigPeakOutputReverse(-.75, 10);
       climber_talon_wheel->ConfigPeakOutputForward(1, 10);
       climber_talon_wheel->ConfigPeakOutputReverse(-1, 10);
       talon_elevator_enc->ConfigPeakOutputForward(.25, 10);
       talon_elevator_enc->ConfigPeakOutputReverse(-.55, 10);
       talon_wheels->ConfigPeakOutputForward(1, 10);
       talon_wheels->ConfigPeakOutputReverse(-1, 10);
       talon_clamp->ConfigPeakOutputForward(1, 10);
       talon_clamp->ConfigPeakOutputReverse(-1, 10);




        pid->PID_claw_elevator();
        std::cout<<"Full Teleop v29"<<std::endl;




}

 
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
 
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    drivebase->update();
        climber->run_climber(.75); 
       
        intake_wheels->update();
        intake_clamp->update();
         
        intake_pivot->run_intake_pivot(0, -220, -820, -1250, -1000);
 
       elevator->run_elevator(-6250,-22000, -27500 );
       if (auto_align==1) {
        //do auto align
       }
       if (joy0->GetRawButton(5)==1 and auto_toggle1 ==0 and auto_toggle2 ==0){
        auto_align= 1;
        auto_toggle1=1;
       }
       if (joy0->GetRawButton(5)==0 and auto_toggle1 ==1){
        auto_toggle2=1;
        auto_toggle1=0;
       }
       if(joy0->GetRawButton(5)==1 and auto_toggle2 ==1){
        auto_align =0;
        auto_toggle2 =2;
       }
       if (joy0->GetRawButton(5)==0 and auto_toggle2 ==2){
        auto_toggle2=0;
        auto_toggle1=0;
       }



}

void Robot::TestPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
