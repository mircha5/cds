# cds (upgraded Change Directory) 
Program for storing and adding paths for navigating in Command Prompt. Name comes from command "cd" in Windows.  
Program was tested on Windows 10 and probably will work only on Windows OS.
### Syntax for usage:
```
      cds --add or -a C:\User\user\some_dir
            # appends path to a file and returns index
      cds index command1 command2 ...
            # executes cd dir_with_index && commmand1 && command2 ...
      cds --show or -s
            # shows content of txt
      cds --del or -d index
            # deletes specified index
```
### Examples:  
⛳ Add new path to a program. All the paths are stored in **cdsLog.txt** file in the directory where program is located. In the following examples, it is assumed that cds.exe is in PATH in environment variables.   

```
  cds -a "C:\Users\user\java programs"  
  New index: 1
```
👀 You can now see your path by typing "cds -s".
```
  cds -s
  1 C:\Users\user\java programs
```
💻 Lets execute some Windows commands.
```
  cds 1 dir
  some_date <DIR> .
  some_date <DIR> ..
  some_date <DIR> 119 HelloWorld.java
```
🏃‍♂️ Now we can run java program by typing:
```
  cds 1 "java HelloWorld"
  Hello World!
```
💣 If you want to delete path in program, type:
```
  cds -d 1 
```
### Contact me
If you have suggestions, please contact me by my email(mircha849@gmail.com).
