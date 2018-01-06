# MachineProject2018
check read me in web-app to learn more about how to run the web-app
## Commands
Here is a short list of all the availible commands:
| Key     | Command                   | Description                                                          |
|---------|---------------------------|----------------------------------------------------------------------|
| w,a,s,d | driving                   | just like COD                                                        |
| 1       | storageTakeIncompleteFlag | Grabs the first incomplete flag assembly from storage                |
| 2       | storageReturnCompleteFlag | Places completed flag assembly in first empty storage                |
| 3       | storageTakeCompleteFlag   | Grabs the first completed flag assembly from storage                 |
| /       | dropBridge                | Drops the bridge, tyler if you accidently hit this I will murder you |
| c       | printArmState             | Prints the current state of the arm                                  |
| r       | armReset                  | moves the arm to its initial state                                   |
| i, k    | armUpDown                 | moved the arm up and down without affecting the wrist                |
| [, ]    | armPivot                  | pivots the arm counterclockwise and clockwise                        |
| n, m    | armShoulder               | rotates the arm shoulder up and down                                 |
| g, h    | armElbow                  | rotates the arm elbow up and down                                    |
| y, u    | armWrist                  | rotates the arm wrist clockwise and counterclockwise                 |
| t       | armFlipWrist              | flips the wrist 180 Dégrise                                          |
| v,b     | armClawReleaseGrab        | releases or grabs with the claw by steps                             |
| o, p    | armClawOpenClose          | explicitly opens or closes the arm                                   |

## Using Terminal to control Arduino
1. Run the following command to connect terminal to Arduino
>stty -f /dev/ttyACM0 cs8 9600 ignbrk -brkint -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

2. Then Run
> screen /dev/cu.usbmodem1421 9600
To be able to run serial commands through terminal

"ARDUINO_USB_PORT" is replaced with actual Arduino port it is found under Tools > Port in Arduino IDE
