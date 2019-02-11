/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#include "ctre/Phoenix.h"
#include <frc/TimedRobot.h>
#include  "Encoder.h"
#include <PDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Preferences.h>
using namespace frc;
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
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  VictorSPX onAsansor{0};
  VictorSPX arkaAsansor{1};
  Encoder ec{0,1};
  PDController pdc{0.07,0.5};
};
