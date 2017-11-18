# MachineProject2018
check read me in web-app to learn more about how to run the web-app

## Using Terminal to control Arduino
1. Run the following command to connect terminal to Arduino
>stty -f "ARDUINO_USB_PORT" cs8 9600 ignbrk -brkint -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

2. Then Run
> screen "ARDUINO_USB_PORT" 9600
To be able to run serial commands through terminal

"ARDUINO_USB_PORT" is replaced with actual Arduino port it is found under Tools > Port in Arduino IDE