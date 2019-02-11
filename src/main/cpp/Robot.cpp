/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Robot.h>

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

float Robot::getLiftHeight(){
  float ecRotation = (float)ec.Get()/600.0;
  return ecRotation * 2.0 * 3.14159265 * 1.25 * 3.0*1.15;
}
void Robot::RobotInit() {
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  kp=Preferences::GetInstance()->GetFloat("Kp");
  kd=Preferences::GetInstance()->GetFloat("Kd");
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
  
}

void Robot::TeleopInit() {
  double baseSpeed = 0.8;
  ec.Reset();
  pdc.kP=this->kp;
  pdc.kD=this->kd;
}

void Robot::TeleopPeriodic() {
  int ref = 60;
  int error = ref-getLiftHeight();
  pdc.setError(error);
  float output = pdc.getOutput();
  
  baseSpeed += output;
  if(baseSpeed >= 1){
    baseSpeed = 1;
  }
  if(baseSpeed<-1){
    baseSpeed = -1;
  }
  double speed = baseSpeed;
  onAsansor.Set(ControlMode::PercentOutput,speed);
  arkaAsansor.Set(ControlMode::PercentOutput,speed);
  std::cout<<getLiftHeight()<<std::endl;
  std::cout<<error<<std::endl;

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
