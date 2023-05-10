# cds
<pre>
Program for storing and adding paths for navigating in Command Line. Name comes from command "cd" in Windows. <br />
Syntax for usage: <br />
&nbsp  cds --add or -a C:\User\user\some_dir <br /> 
      appends path to a file and returns index <br /> 
  cds index command1 command2 ... <br />
      executes cd dir_with_index && commmand1 && command2 ... <br />
  cds --show or -s <br />
      shows content of txt <br />
  cds --del or -d index <br />
      deletes specified index <br />
Examples: <br />
  ⛳ Add new path to a program. All the paths are stored in cdsLog.txt file in the directory where program is located. <br />
  command: <br />
    cds -a "C:\Users\user\java programs" <br />
  returns: <br />
    New index: 1 <br />
  👀 You can now see your path by typing "cds -s". <br />
  command: <br />
    cds -s <br />
  returns: <br />
    1 C:\Users\user\java programs <br />
  💻 Lets execute some Windows commands. <br />
  command: <br />
    cds 1 dir <br />
  returns: <br />
   some_date   <DIR>          . <br />
   some_date   <DIR>          .. <br />
   some_date   119 HelloWorld.java <br />
  🏃‍♂️ Now we can run java program by typing <br />
  command: <br />
    cds 1 "java HelloWorld" <br />
  returns: <br />
    Hello World! <br />
  💣 If you want to delete path in program, type <br />
  command: <br />
    cds -d 1 <br />
  returns: <br />
    *nothing* <br />
</pre>
    
  
      
