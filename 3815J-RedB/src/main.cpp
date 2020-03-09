/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RightB               motor         20              
// LeftB                motor         12              
// Controller1          controller                    
// ArmR                 motor         9               
// ArmL                 motor         2               
// IntakeR              motor         10              
// IntakeL              motor         1               
// Stacker              motor         19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void fw(int x,int v){
  RightB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
  LeftB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
}
void bw(int x,int v){
  RightB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
  LeftB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}

void autonomous(void) {
  fw(500,90);
  task::sleep(1000);
  bw(300,90);
  task::sleep(1000);

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    

    ArmL.setStopping(hold);
    ArmR.setStopping(hold);
    Stacker.setStopping(hold);
    
    LeftB.spin(directionType::fwd,0.2*Controller1.Axis1.value()+0.7*Controller1.Axis3.value(),velocityUnits::pct);
    RightB.spin(directionType::fwd,0.2*Controller1.Axis1.value()-0.7*Controller1.Axis3.value(),velocityUnits::pct);

    if(Controller1.ButtonR1.pressing()){
      IntakeL.spin(forward,100,percent);
      IntakeR.spin(reverse,100,percent);
    }
    else if(Controller1.ButtonR2.pressing()){
      IntakeL.spin(reverse,100,percent);
      IntakeR.spin(forward,100,percent);
    }
    else{
      IntakeL.setStopping(hold);
      IntakeR.setStopping(hold);
      IntakeL.stop();
      IntakeR.stop();
    }
    

    if(Controller1.ButtonL1.pressing()){
      ArmL.spin(forward);
      ArmR.spin(reverse);
    }
    else if(Controller1.ButtonL2.pressing()){
      ArmL.spin(reverse);
      ArmR.spin(forward);
    }
    else{
      ArmL.stop();
      ArmR.stop();
    }

    if(Controller1.ButtonX.pressing()){
      Stacker.spin(reverse);
    }
    else if(Controller1.ButtonB.pressing()){
      Stacker.spin(forward);
    }
    else{
      Stacker.stop();
    }


  }

    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
}

//
// Main will set up the competition functions and callbacks.
//
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
