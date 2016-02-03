#pragma config(Motor,  port1,           driveright,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           shootertopleft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           shooterbottomleft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           shootertopright, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           shooterbottomright, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           motor6,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           motor7,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           intakefront,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           intakeback,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          driveleft,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 ____           ______ _ _
| __ ) _ __ ___|__  (_) | | __ _
|  _ \| '__/ _ \ / /| | | |/ _` |
| |_) | | | (_) / /_| | | | (_| |
|____/|_|  \___/____|_|_|_|\__,_|.c
Team Error 404
Weston Middle School
*/

task main()	{

	while (true) {

		int shooterButtonToggleState = 0;
		int shooterButtonPressed = 0;


		int shooterSpeed = 100;

		// Used to filter out joystick abberations
		int threshold = 10;

		//////////////////////////////////////////////////////////
		//
		// DRIVE
		//
		// This code has filtering in place
		// Because the joystick returns a value that is not always
		// exactly zero.
		//
		// Because of this, the Cortex makes a whining sound
		// because the drive motors are being triggered
		// with values less than 10
		//
		// By testing if the joystick is within the threshold
		// We can turn off the motors and stop the noise
		// and power drain

		if(abs(vexRT[Ch3]) > threshold)         // If the left joystick is greater than or less than the threshold:
		{
			motor[driveleft]  = (vexRT[Ch3]);
		}
		else                                    // If the left joystick is within the threshold:
		{
			motor[driveleft]  = 0;                // Stop the left motor (cancel noise)
		}

		if(abs(vexRT[Ch2]) > threshold)         // If the right joystick is greater than or less than the threshold:
		{
			motor[driveright] = (vexRT[Ch2]);
		}
		else                                    // If the right joystick is within the threshold:
		{
			motor[driveright] = 0;                // Stop the right motor (cancel noise)
		}

		// SHOOTERS

		if( vexRT[ Btn6U ] == 1 )
		{
			if( ! shooterButtonPressed )
			{
				// change the toggle state
				shooterButtonToggleState = 1 - shooterButtonToggleState;

				// Note the button is pressed
				shooterButtonPressed = 1;
			}
		}
		else
		{
			// the button is not pressed
			shooterButtonPressed = 0;
		}

		if (shooterButtonToggleState) {
			motor[shootertopleft] = shooterSpeed;
			motor[shooterbottomleft] = shooterSpeed;
			motor[shootertopright] = shooterSpeed;
			motor[shooterbottomright] = shooterSpeed;
			} else {
			motor[shootertopleft] = 0;
			motor[shooterbottomleft] = 0;
			motor[shootertopright] = 0;
			motor[shooterbottomright] = 0;
		}

		/*
		//NON TOGGLE
		if (vexRT[Btn6U] == 1) {
		motor[shootertopleft] = shooterSpeed;
		motor[shooterbottomleft] = shooterSpeed;
		motor[shootertopright] = shooterSpeed;
		motor[shooterbottomright] = shooterSpeed;
		} else {
		motor[shootertopleft] = 0;
		motor[shooterbottomleft] = 0;
		motor[shootertopright] = 0;
		motor[shooterbottomright] = 0;
		}
		*/




		// Hold 5U to drive elevator

		if (vexRT[Btn5U] == 1) {
			motor[intakefront] = 127;
			motor[intakeback] = 127;
			} else {

			// If 5U isn't pressed
			// check for 5D which is
			// reverse. If neither, turn off.

			if (vexRT[Btn5D] == 1) {
				motor[intakefront] = -127;
				motor[intakefront] = -127;
				} else {
				motor[intakefront] = 0;
				motor[intakefront] = 0;
			}
		}
	}
}
