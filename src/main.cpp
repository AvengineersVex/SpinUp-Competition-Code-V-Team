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

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

void autonomous(void) {

}

void usercontrol(void) {
  Controller.ButtonA.pressed(shoot);
  setupExpansion(Controller.ButtonL2);
  setupIntake(Controller.ButtonR1);
  setupRoller(Controller.ButtonR2);
  setupFlywheel(Controller.ButtonL1);
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