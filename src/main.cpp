/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Avengineers                                               */
/*    Created:      Tue Oct 11 2022                                           */
/*    Description:  Avengineers V Team Spin Up Competition Code Main          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// LeftDrive            motor         1               
// RightDrive           motor         2
// Storage              motor         3
// Intake               motor         4
// Controller           controller
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
  while (true) {
    setupStorage(Controller.ButtonR1);
    setupFlywheel(Controller.ButtonL1);
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