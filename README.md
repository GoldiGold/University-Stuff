# Flight Simulator Project- Advanced1 hw3
The project is a tool to deal with the Flight Simulator in effective way. The main gets a name of code file, interpret the code inside it, and execute it. The code can change the variables of the Flight Simulator, and also get values from it. For example we can write a simple file that contains code that makes an airplain take off.

##Link to gihub: https://github.com/GoldiGold/University-Stuff

##Usage
First we will make sure that all the files are in the same directory (including the code file).
In order to compile the program we will use this command in the terminal: 
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

and in order to run:
./a.out code_file.txt

when code_file.txt is the file with the code that control the simulator.

Important!!! when you open the simulator go to: settings->Additional Settings  and write there: ‫‪--telnet=socket,in,10,127.0.0.1,5402,tcp‬‬
This command open a server which our program will conect while run time.

##Code File (code_file.txt)
In this file you write yor commands for the simulator. In order to connect the simulator use in the begining of the code file this two commands:
openDataServer(5400)
connectControlClient("127.0.0.1",5402)

We are connecting! Now we can use more commands:
-Define variables that contains value, and can get and put values in the simulator
-Print to the consule
-Sleep for milliseconds
-Use if and while commands
and more...

Good Luck!!!
