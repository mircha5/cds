# cds
Program for storing and adding paths for navigating in Command Line. Name comes from command "cd" in Windows. \n 
Syntax for usage:
  cds --add or -a C:\User\user\some_dir 
      appends path to a file and returns index 
  cds index command1 command2 ... 
      executes cd dir_with_index && commmand1 && command2 ...
  cds --show or -s 
      shows content of txt
  cds --del or -d index 
      deletes specified index 
Examples:
  ⛳ Add new path to a program. All the paths are stored in cdsLog.txt file in the directory where program is located.
  command:
    cds -a "C:\Users\user\java programs"
  returns:
    New index: 1
  👀 You can now see your path by typing "cds -s". 
  command:
    cds -s
  returns:
    1 C:\Users\user\java programs
  💻 Lets execute some Windows commands.
  command:
    cds 1 dir
  returns:
   some_date   <DIR>          .
   some_date   <DIR>          ..
   some_date   119 HelloWorld.java
  🏃‍♂️ Now we can run java program by typing
  command:
    cds 1 "java HelloWorld"
  returns:
    Hello World!
  💣 If you want to delete path in program, type
  command:
    cds -d 1
  returns:
    *nothing*
   
    
  
      
