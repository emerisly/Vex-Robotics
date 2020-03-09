/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Emerald Liu                                               */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftF                motor         3               
// LeftB                motor         1               
// RightF               motor         5               
// RightB               motor         2               
// ArmL                 motor         9               
// Stacker              motor         6               
// IntakeL              motor         10              
// IntakeR              motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void fw(int x,int v){
  RightF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
  RightB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
  LeftF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
  LeftB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}
void bw(int x,int v){
  RightF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
  RightB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
  LeftF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
  LeftB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
}
void intake(int x,int v){
  IntakeL.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
  IntakeR.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}
void lift(int x,int v){
  ArmL.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}
void stack(int x,int v){
  Stacker.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
}
void moveLeft(int x,int v){
LeftF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
LeftB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
RightF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
RightB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
}
void moveRight(int x,int v){
LeftF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
LeftB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
RightF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
RightB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}
void turnLeft(int x,int v){
LeftF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
LeftB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
RightF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
RightB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
}
void turnRight(int x,int v){
LeftF.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
LeftB.startRotateFor(-x,rotationUnits::deg,v,velocityUnits::pct);
RightF.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
RightB.startRotateFor(x,rotationUnits::deg,v,velocityUnits::pct);
}


void autonomous(void) {

/*
moveLeft(600,100);
task::sleep(2000);
moveRight(500,60);
task::sleep(1000);
fw(300,60);
task::sleep(1000);
*/


lift(2500,70);
task::sleep(1500);
//stack(400,50);
//task::sleep(1000);
//lift(850,60);
//task::sleep(2000);
//stack(-300,60);
lift(-1500,70);
//stack(-400,50);
//task::sleep(2000);

intake(3000,100); 
fw(1100,20);
task::sleep(6000);

bw(1000,50);
task::sleep(2000);

fw(200,20);
task::sleep(400);

turnLeft(500,50);
task::sleep(1000);

}

void usercontrol(void) {
vexcodeInit();
IntakeL.setStopping(hold);
IntakeR.setStopping(hold);
ArmL.setStopping(hold);
Stacker.setStopping(hold);

  // User control code here, inside the loop
  while (1) {


      LeftF.spin(directionType::fwd,-0.9*Controller1.Axis3.value(),velocityUnits::pct);
      LeftB.spin(directionType::fwd,-0.9*Controller1.Axis3.value(),velocityUnits::pct);
      RightF.spin(directionType::fwd,-0.9*Controller1.Axis2.value(),velocityUnits::pct);
      RightB.spin(directionType::fwd,-0.9*Controller1.Axis2.value(),velocityUnits::pct);

/*
      LeftF.spin(directionType::rev,-0.4*Controller1.Axis4.value()+0.8*Controller1.Axis3.value()+0.4*Controller1.Axis1.value(),velocityUnits::pct);
      LeftB.spin(directionType::fwd,-0.4*Controller1.Axis4.value()-0.8*Controller1.Axis3.value()-0.4*Controller1.Axis1.value(),velocityUnits::pct);
      RightF.spin(directionType::rev,-0.4*Controller1.Axis4.value()+0.8*Controller1.Axis3.value()-0.4*Controller1.Axis1.value(),velocityUnits::pct);
      RightB.spin(directionType::fwd,-0.4*Controller1.Axis4.value()-0.8*Controller1.Axis3.value()+0.4*Controller1.Axis1.value(),velocityUnits::pct);
*/

/// Arm
    if (Controller1.ButtonUp.pressing()) {
      ArmL.spin(reverse,80,percent);
    }
    else if (Controller1.ButtonDown.pressing()) {
      ArmL.spin(forward,80,percent);
    }   
    else{
      ArmL.stop();
    }

/// Stacker
    if (Controller1.ButtonX.pressing()){
      Stacker.spin(forward,10,percent);
    }
    else if(Controller1.ButtonB.pressing()){
      Stacker.spin(reverse);
    }
    else{
      Stacker.stop();
    }

///  Intake
    if(Controller1.ButtonL2.pressing()){
      IntakeR.spin(forward,100,percent);
      IntakeL.spin(forward,100,percent);
    }
    else if(Controller1.ButtonL1.pressing()){
      IntakeR.spin(reverse,100,percent);
      IntakeL.spin(reverse,100,percent);
    }
    else{
      IntakeL.stop();
      IntakeR.stop();
    }

/// Horizontal Movement
    if(Controller1.ButtonY.pressing()){
      LeftF.spin(directionType::rev,50,velocityUnits::pct);
      LeftB.spin(directionType::fwd,50,velocityUnits::pct);
      RightF.spin(directionType::rev,50,velocityUnits::pct);
      RightB.spin(directionType::fwd,50,velocityUnits::pct);
    }
    else if(Controller1.ButtonA.pressing()){
      LeftF.spin(directionType::fwd,50,velocityUnits::pct);
      LeftB.spin(directionType::rev,50,velocityUnits::pct);
      RightF.spin(directionType::fwd,50,velocityUnits::pct);
      RightB.spin(directionType::rev,50,velocityUnits::pct);
    }
    
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
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
