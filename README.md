# Desk-time-tracker
tracks how much time you spend at your desk and gives a graphical report in excel

# Arduino components
1) Uno board
2) HC-SR04 (ultrasonic sensor)
3) MicroSD card module
4) MicroSD card for logging data
5) Breadboard
6) Jumperwires

# About Excel file
You will only need to import the data once from the file in the sd card (here "final.txt"). Then because of the premade connection set the data import settings to automatic refresh such that the logged data gets added to your excel sheet.
In other sheet, I have used pivot tables to create filters to make weekly graphs.(If there is any other easier approach please let me know)

# About the code
You will need to install <DS3231.h> library [here](http://www.rinkydinkelectronics.com/library.php?id=73). And then set the current time and date.

