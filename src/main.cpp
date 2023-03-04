/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Avengineers                                               */
/*    Created:      Tue Oct 11 2022                                           */
/*    Description:  Avengineers V Team Spin Up Competition Code Main          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// LeftDrive         motor           1
// RightDrive        motor           2
// Storage           motor           3
// Intake            motor           4
// Flywheel1         motor           5
// Flywheel2         motor           6
// Roller            motor           7
// Expansion         motor           8
// Controller        controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "control.h"
#include "auton.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

void autonomous(void) {
  // RightDrive.setVelocity(100, velocityUnits::pct);
  // LeftDrive.setVelocity(100, velocityUnits::pct);
  // RightDrive.spin(directionType::fwd);
  // LeftDrive.spin(directionType::fwd);
  // Intake.setVelocity(50, velocityUnits::pct);
  // Intake.spin(directionType::fwd);
  // wait(250, msec);
  // Intake.setVelocity(0, velocityUnits::pct);
  // Intake.stop();
  // RightDrive.stop();
  // LeftDrive.stop();
  RightDrive.setVelocity(100, velocityUnits::pct);
  LeftDrive.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(directionType::fwd);
  LeftDrive.spin(directionType::fwd);
  wait(1000, msec);
  RightDrive.stop();
  LeftDrive.stop();
  Intake.spin(directionType::fwd);
  wait(2000, msec);
  Intake.stop();
  RightDrive.spin(directionType::rev);
  LeftDrive.spin(directionType::rev);
  wait(1975, msec);
  RightDrive.stop();
  LeftDrive.stop();
  wait(500, msec);
  RightDrive.spin(directionType::fwd);
  LeftDrive.spin(directionType::rev);
  wait(800, msec);
  LeftDrive.spin(directionType::fwd);
  wait(1000, msec);
  Intake.setVelocity(50, velocityUnits::pct);
  Intake.spin(directionType::fwd);
  wait(500, msec);
  Intake.setVelocity(0, velocityUnits::pct);
  Intake.stop();
  // RightDrive.setVelocity(0, velocityUnits::pct);
  // LeftDrive.setVelocity(0, velocityUnits::pct);
  // RightDrive.stop();
  // LeftDrive.stop();
}

void usercontrol(void) {
  setupIntake(Controller.ButtonR1);
  setupRoller(Controller.ButtonR2);
  setupFlywheel(Controller.ButtonL1);
  setupExpansion(Controller.ButtonL2);
  Controller.ButtonX.pressed(longHighGoal);
  Controller.ButtonA.pressed(shortHighGoal);
  Controller.ButtonB.pressed(lowGoal);
  while (true) {
    mainDrive();
    wait(20, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}