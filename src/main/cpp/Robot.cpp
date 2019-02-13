/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/* 2019 Deep Space Robot Code by KelRot #5655                                                                           */
/*----------------------------------------------------------------------------*/
#include <Robot.h>
#include <math.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::manualLiftControl(bool up,bool down)
{
  if(up)
   ref +=1.25;
  else if(down)
  {
   ref -=1.25;
  }
}
void Robot::setLiftforHatchAndCargo(bool cargo_top,bool cargo_mid,bool cargo_low,bool hatch_top,bool hatch_mid,bool hatch_low)
{
  //TODO tam pozisyonlar belirlenmeli
  if(cargo_top)
  ref=162;
  else if(cargo_mid)
  ref=92;
  else if(cargo_low)
  ref=20;
  else if(hatch_top)
  ref=5;
  else if(hatch_mid)
  ref=5;
  else if(hatch_low)
  ref=5;
}

float Robot::getLiftHeight(){
  float ecRotation = (float)asansor_ec.Get()/600.0;
  return ecRotation * 2.0 * 3.14159265 * 1.25 * 3.0*1.15;
}
void Robot::RobotInit() {}

void Robot::RobotPeriodic() {
  kp=frc::Preferences::GetInstance()->GetFloat("Kp");
  kd=frc::Preferences::GetInstance()->GetFloat("Kd");
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  onAsansor.Set(ControlMode::PercentOutput,0);
  arkaAsansor.Set(ControlMode::PercentOutput,0);
  baseSpeed = 1;
  asansor_ec.Reset();
  pdc.setkP(this->kp);
  pdc.setkD(this->kd);
  ref = 5;
}

void Robot::TeleopPeriodic() {

  std::cout<<getLiftHeight()<<std::endl;
  rd.CurvatureDrive(surus_j.GetRawAxis(1),surus_j.GetRawAxis(4),7);
  manualLiftControl(js.GetRawButton(3),js.GetRawButton(4));
  setLiftforHatchAndCargo(js.GetRawButton(5),js.GetRawButton(6),js.GetRawButton(7),js.GetRawButton(8),js.GetRawButton(9),js.GetRawButton(10));

  ref = (js.GetRawAxis(0)-(-1))/(1-(-1)) * (150-30) + 30;
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
  std::cout<<"error="<<error<<std::endl;
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif