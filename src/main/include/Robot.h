/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <string>
#include <frc/WPILib.h>
#include "ctre/Phoenix.h"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Preferences.h>
#include <frc/Encoder.h>
#include "PDController.h"
#include <frc/MotorSafety.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  float getLiftHeight();
  double baseSpeed;
  float kp,kd;
  
 private:
  int ref;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::Joystick js{1};
  frc::Joystick surus_j{0};
  VictorSPX onAsansor{0};
  VictorSPX arkaAsansor{1};
  
  void setLiftforHatchAndCargo();
  void manualLiftControl(bool up,bool down);
  frc::Encoder asansor_ec{0,1};
  PDController pdc{0.07,0.5};
  frc::Talon sagOn{8};
  frc::Talon sagArka{8};
  frc::Talon solOn{6};
  frc::Talon solArka{7};
  frc::SpeedControllerGroup sag{sagOn,sagArka}; frc::SpeedControllerGroup sol{solOn,solArka};
  frc::DifferentialDrive rd{sag,sol};
};
