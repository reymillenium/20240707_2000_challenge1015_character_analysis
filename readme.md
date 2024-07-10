# COP 1334 Assignment - Introduction to C++

## Chapter 10: Challenge 15

## Title: Character Analysis

### Exercise Description:

Write a program that reads a file’s contents and determines the following:

• The number of uppercase letters in the file

• The number of lowercase letters in the file

• The number of digits in the file

It must also determine the same from a constant string object.

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

Welcome to Character Analysis Pro

1. Simple & boring character analysis from a string object.
2. Save some text to a file, so we can analyse it later.
3. Quit the program.

Type your selection please: 1

Character Analysis Results:
The string contains 2 digits, 3 uppercase letters & 33 lowercase letters.

1. Simple & boring character analysis from a string object.
2. Save some text to a file, so we can analyse it later.
3. Quit the program.

Type your selection please: 2
Write a single line of text please: Oh yeah, this is way better

1. Simple & boring character analysis from a string object.
2. Add more text to our file, so we can analyse it later.
3. Fun Y Cool Character Analysis of our text file.
4. Quit the program.

Type your selection please: 3

Character Analysis Results:
The file contains 0 digits, 1 uppercase letters & 20 lowercase letters.

1. Simple & boring character analysis from a string object.
2. Add more text to our file, so we can analyse it later.
3. Fun Y Cool Character Analysis of our text file.
4. Quit the program.

Type your selection please: 2
Write a single line of text please: And what about now? 305 forever man! Biden was not elected!!

1. Simple & boring character analysis from a string object.
2. Add more text to our file, so we can analyse it later.
3. Fun Y Cool Character Analysis of our text file.
4. Quit the program.

Type your selection please: 3

Character Analysis Results:
The file contains 3 digits, 3 uppercase letters & 61 lowercase letters.

1. Simple & boring character analysis from a string object.
2. Add more text to our file, so we can analyse it later.
3. Fun Y Cool Character Analysis of our text file.
4. Quit the program.

Type your selection please: 4
  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


