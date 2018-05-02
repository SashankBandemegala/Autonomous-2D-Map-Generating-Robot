# Autonomous 2D Map Generating Robot
This autonomous 2D map generating robot was created for the purpose of the ELEC 3907 third year open-ended project course at Carleton University. This project was created by a group of 6 keen individiuals who have a passion for designing and working on projects. The way this robot works is that it uses 4 ultrasonic sensors, one on each side, to detect obstacles in front of it. If the distance is below the value set through Ardino IDE coding, the robot will turn a different direction using its dual motoro system controlled by a quadruple H-Bridge motor driver. The entire robot is powered through 6 AAA batteries and uses a Bluetooth module to communicate the on board Arduino microcontroller with the main computer for mapping purposes.   
The robots body is shown below. Each individual side is shown as well as the finished project.

## Part 1 - Robots Body


## Part 2 - Autonomous Driving 
Using ultrasonic sensors, an Arduino microcontroller was used to make decisions on the go whether to turn depending on the distance of the object in front of the rotbot. The result of the robot being autonomous is shown in the video.(Autonomous Driving.mp4)

## Part 3 - Mapping 
The mapping of the robot was done through MATLAB since saving the ultrasonic sensors information was necessary to plot it onto a graph. The output of the information is shown in the image (Mapping.png) where the magnitude of the line determines the distance of an object from the corresponding sensor. 
