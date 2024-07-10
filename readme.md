# COP 1334 Assignment - Introduction to C++

## Chapter 6: Challenge 10

## Title: Future Value

### Exercise Description:

Suppose you have a certain amount of money in a savings account that earns compound monthly interest, and you want to calculate the amount that you will have after a specific number of months. The formula, which is known as the future value formula, is

𝐹 = 𝑃 × 1 + 𝑖<sup>𝑡</sup>

The terms in the formula are as follows:

• _F_ is the **future value** of the account after the specified time period.

• _P_ is the **present value** of the account.

• _i_ is the **monthly interest rate**.

• _t_ is the **number of months**.

Write a program that prompts the user to enter the account’s present value, monthly interest rate, and the number of months that the money will be left in the account. The program should pass these values to a function named`futureValue`that returns the future value of the account, after the
specified number of months. The program should display the account’s future value.

**Note:**

The Future Value Formula shown on the mandatory Pearson ebook is wrong:

𝐹 = 𝑃 × 1 + 𝑖<sup>𝑡</sup>

That's mathematically equivalent to:

𝐹 = 𝑃 + 𝑖<sup>𝑡</sup>

And that's also **not** the Future Value Formula.

The real Future Value Formula (using Compound interest) is:

𝐹 = 𝑃 × (1 + 𝑖)<sup>𝑡</sup>

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

  Enter the account's Present Value: 1250.57
  Enter the monthly interest rate: 0.245
  Enter the number of months that the money will be left in the account: 10

  The Future Value of the account, starting with an initial capital of $ 1,250.57, 
  with a monthly interest rate of 0.24 (24.50 %),
  and after 10 months, is equal to: $ 11,189.26
  And that figure can be broken down month by month as follows:

  --------------------------
  | Month |  Future Value  |
  --------------------------
  |     1 |   1,556.96 USD |
  --------------------------
  |     2 |   1,938.41 USD |
  --------------------------
  |     3 |   2,413.33 USD |
  --------------------------
  |     4 |   3,004.59 USD |
  --------------------------
  |     5 |   3,740.72 USD |
  --------------------------
  |     6 |   4,657.19 USD |
  --------------------------
  |     7 |   5,798.20 USD |
  --------------------------
  |     8 |   7,218.76 USD |
  --------------------------
  |     9 |   8,987.36 USD |
  --------------------------
  |    10 |  11,189.26 USD |
  --------------------------

  Would you like to keep calculating the Future Value (y/n)? y

  Enter the account's Present Value: 1268.99
  Enter the monthly interest rate: 0.34
  Enter the number of months that the money will be left in the account: 6

  The Future Value of the account, starting with an initial capital of $ 1,268.99, 
  with a monthly interest rate of 0.34 (34.00 %),
  and after 6 months, is equal to: $ 7,346.61
  And that figure can be broken down month by month as follows:

  --------------------------
  | Month |  Future Value  |
  --------------------------
  |     1 |   1,700.45 USD |
  --------------------------
  |     2 |   2,278.60 USD |
  --------------------------
  |     3 |   3,053.32 USD |
  --------------------------
  |     4 |   4,091.45 USD |
  --------------------------
  |     5 |   5,482.54 USD |
  --------------------------
  |     6 |   7,346.61 USD |
  --------------------------

  Would you like to keep calculating the Future Value (y/n)? n
  
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


