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

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::Joystick js{1};
  frc::Joystick surus_j{0};

  VictorSPX onAsansor{0};
  VictorSPX arkaAsansor{1};
  frc::Victor intakeSol{0};
  frc::Victor intakeSag{1};

  int ref;
  double baseSpeed;
  float kp,kd;
  
  void setLiftforHatchAndCargo();
  void manualLiftControl();
  void intake();
  void hatchStuff();
  void extension();
  int vision_proc();
  
  frc::Encoder asansor_ec{0,1};
  PDController pdc{0.07,0.5};
  frc::Timer timer;

  frc::DoubleSolenoid intakeIndirme{4,5};
  frc::DoubleSolenoid hatchAtis{6,7};
  frc::Compressor comp{};

  frc::Talon sagOn{2};
  frc::Talon sagArka{3};
  frc::Talon solOn{4};
  frc::Talon solArka{4};
  
  frc::SpeedControllerGroup sag{sagOn,sagArka}; frc::SpeedControllerGroup sol{solOn,solArka};
  frc::DifferentialDrive rd{sag,sol};

  cs::UsbCamera kamera;
};
