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

std::vector<float> Robot::vision_proc()
{
  cvSink.GrabFrame(frame);
  std::vector<float> values=initialProcess(frame);
  float dist_left=values[0]; float dist_right=values[1];
  float targetMiddleOffset = values[2];
  float angle=getAngle(dist_left,dist_right);
  float radius=calculateRadius((dist_left + dist_right) / 2 - CAM_INTAKE_DIST, angle, targetMiddleOffset);//radius = 
  
  std::vector<float> retVector;
  retVector.push_back(dist_left);
  retVector.push_back(dist_right);
  retVector.push_back(radius);
  retVector.push_back(angle);
  return retVector;
}

void Robot::intake()
{
  if(js.GetPOV()==180)
  {
    intakeSag.Set(-1);
    intakeSol.Set(1);
  }
  else if(js.GetPOV()==0)
  {
    intakeSag.Set(1);
    intakeSol.Set(-1);
  } 
  else
  {
   intakeSag.Set(0.0);
   intakeSol.Set(0.0);
  } 
}

void Robot::manualLiftControl()
{
  if(js.GetRawButton(3))//*yukarı
   ref +=1.25;
  else if(js.GetRawButton(4))//*aşağı
   ref -=1.25;
}

void Robot::setLiftforHatchAndCargo()
{
  //TODO tam pozisyonlar belirlenmeli
  if(surus_j.GetRawButtonPressed(5))
    ref=0;
  else if(js.GetRawButtonPressed(5))//*Cargo 3
    ref=210+10;
  else if(js.GetRawButtonPressed(6))//*Cargo 2
    ref=140+10;
  else if(js.GetRawButtonPressed(7))//*Cargo 1
    ref=70+10;
  else if(js.GetRawButtonPressed(8))//*Hatch 3
    ref=188;
  else if(js.GetRawButtonPressed(9))//*Hatch 2
    ref=118;
  else if(js.GetRawButtonPressed(10))//*Hatch 1
    ref=32;
}

void Robot::hatchStuff()
{
  if(js.GetRawButtonPressed(11))
  {
    hatchAtis.Set(frc::DoubleSolenoid::Value::kForward);
    frc::Wait(0.1);
  }
  else if(js.GetRawButtonPressed(12))
  {
    hatchAtis.Set(frc::DoubleSolenoid::Value::kReverse);
    frc::Wait(0.1);
  }
  else
  {
   hatchAtis.Set(frc::DoubleSolenoid::Value::kOff);
  }

}

float Robot::getLiftHeight(){
  float ecRotation = (float)asansor_ec.Get()/600.0;
  return ecRotation * 2.0 * 3.14159265 * 1.25 * 3.0*1.15;
}

void Robot::extension(){
  if(js.GetRawButton(1)){
    intakeIndirme.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else if(js.GetRawButton(2)){
    intakeIndirme.Set(frc::DoubleSolenoid::Value::kForward);
  }
}


void Robot::RobotInit() {
  kamera=frc::CameraServer::GetInstance()->StartAutomaticCapture();
  cvSink=frc::CameraServer::GetInstance()->GetVideo(kamera); 
}

void Robot::RobotPeriodic() {
  kp=frc::Preferences::GetInstance()->GetFloat("Kp");
  kd=frc::Preferences::GetInstance()->GetFloat("Kd");
  auto_kP=frc::Preferences::GetInstance()->GetFloat("Auto Kp");
}

void Robot::AutonomousInit() {
  onAsansor.Set(ControlMode::PercentOutput,0);
  arkaAsansor.Set(ControlMode::PercentOutput,0);

  baseSpeed = 1;
  asansor_ec.Reset();

  pdc.setkP(this->kp);
  pdc.setkD(this->kd);
  ref = 0;

  runPControl = false;
}
void Robot::AutonomousPeriodic() {
  TeleopPeriodic();
}

void Robot::TeleopInit() {
 
}

void Robot::TeleopPeriodic() {
  
  manualLiftControl();
  setLiftforHatchAndCargo();
  intake();
  hatchStuff();
  extension();

  if(surus_j.GetAxis(frc::Joystick::AxisType::kThrottleAxis)<-0.05 || surus_j.GetAxis(frc::Joystick::AxisType::kThrottleAxis)>0.05){
    runPControl = false;
  }

  if(surus_j.GetRawButtonPressed(4))
  {
    std::vector<float> values= vision_proc();
    leftDist = values[0];
    rightDist = values[1];
    radius = values[2];
    angle = values[3];
    if(leftDist > rightDist){
      leftTargetDistance = angle*(radius+32.5);
      rightTargetDistance = angle*(radius-32.5);
    }
    else{
      rightTargetDistance = angle*(radius+32.5);
      leftTargetDistance = angle*(radius-32.5);
    }
    ecDrive_left.Reset();
    ecDrive_right.Reset();
    runPControl = true;
  }

  if(runPControl){
    if(leftTargetDistance > rightTargetDistance){
      float current = ecDrive_left.Get()/1024*48;
      float leftSet = (leftTargetDistance-current)*auto_kP;
      if(leftSet > 1){
        leftSet = 1;
      }
      float rightSet = rightTargetDistance/leftTargetDistance * leftSet;
      
      solOn.Set(leftSet);
      solArka.Set(leftSet);
      sagOn.Set(rightSet*-1.0);
      sagArka.Set(rightSet*-1.0);
    }
    if(rightTargetDistance > leftTargetDistance){
      float current = ecDrive_right.Get()/1024*48;
      float rightSet = (rightTargetDistance-current)*auto_kP;
      if(rightSet > 1){
        rightSet = 1;
      }
      float leftSet = leftTargetDistance/rightTargetDistance * rightSet;
      
      solOn.Set(leftSet);
      solArka.Set(leftSet);
      sagOn.Set(rightSet*-1.0);
      sagArka.Set(rightSet*-1.0);
    }
  }
  else{
    rd.CurvatureDrive(surus_j.GetRawAxis(1),surus_j.GetRawAxis(4)*0.75,7);
  }
  float error = ref-getLiftHeight();
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

  std::cout<<"lift height="<<getLiftHeight()<<std::endl;
  std::cout<<"error="<<error<<std::endl;
}

void Robot::TestPeriodic() {
  std::cout<<js.GetPOV()<<std::endl;
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif