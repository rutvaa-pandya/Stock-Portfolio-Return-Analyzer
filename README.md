# Stock Portfolio Return Analyzer

A beginner-friendly C programming mini-project that calculates stock investment values, profit or loss, and portfolio returns.

## About the Project

The **Stock Portfolio Return Analyzer** is a console-based application developed as a mini-project for the Programming for Problem Solving course.

It allows users to enter stock details, compare purchase prices with current prices, and understand the overall performance of their stock portfolio.

The program uses manually entered prices. It does not connect to a live stock market service.

## Features

- **Add Stock:** Enter the stock name, purchase price, current price, and quantity.
- **View All Stocks:** Display saved stock records and their individual performance.
- **Portfolio Summary:** Calculate total investment, current portfolio value, total profit or loss, and overall return.
- **Best Performing Stock:** Identify the stock with the highest percentage return.
- **File Handling:** Save stock records to a local file and load them when the program starts.
- **Data Validation:** Check basic input conditions, such as positive purchase prices and quantities.

## Technologies Used

- Programming Language: C
- Concepts: Structures, arrays, strings, functions, recursion, pointers, conditional statements, loops, and file handling
- Interface: Console-based menu
- Data Storage: Local binary file (`stocks.dat`)

## How It Works

The program calculates the performance of each stock using these formulas:

**1. Total Investment**

`Purchase Price × Quantity`

**2. Current Value**

`Current Price × Quantity`

**3. Profit or Loss**

`Current Value − Total Investment`

**4. Return Percentage**

`(Profit or Loss ÷ Total Investment) × 100`

A positive result indicates a profit, while a negative result indicates a loss.

## Sample Input

Enter the following values when the program asks for the stock details:

```text
TCS
3000
3300
10
```

The values represent:

- Stock Name: TCS
- Purchase Price: ₹3,000
- Current Price: ₹3,300
- Quantity: 10 shares

## Expected Calculation

| Detail | Value |
|---|---:|
| Total Investment | ₹30,000 |
| Current Value | ₹33,000 |
| Profit | ₹3,000 |
| Return | 10.00% |

These values are illustrative test data, not live market prices.

## How to Run the Program

1. Download or clone this repository.
2. Open the C source file in a compatible C compiler.
3. Compile and run the program.
4. Select an option from the menu.
5. Enter stock details when prompted.

### Compiler Compatibility

The current version uses `conio.h`, which is supported by some older DOS-based C environments, including Turbo C. It may require modifications to run in modern compilers such as GCC.

If you are using GCC, first check whether your source code uses `conio.h` or functions such as `clrscr()` and `getch()`. Replace or remove these environment-specific functions before compiling.

## Project Limitations

- Stock prices must be entered manually.
- The program does not retrieve live market prices.
- The analysis does not predict future stock prices.
- Dividends, taxes, brokerage fees, and other charges are not included.
- Records are stored locally rather than in an online database.

## Future Improvements

- Integrate a reliable stock market data API.
- Add graphical charts for portfolio performance.
- Support stock names containing spaces.
- Add more advanced portfolio analysis.
- Create a graphical user interface.
- Add export options for reports.

## Team Members

- Rutva Pandya
- Kush Bhandari
- Khanak Raval
- Akshat Shah

**Faculty Guide:** Dr. Reena Patel  
**Department:** Unitedworld Institute of Technology (UIT)  
**University:** Karnavati University  
**Course:** Programming for Problem Solving (C)

## Learning Outcomes

This project provides practical experience with:

- Designing a menu-driven C program.
- Working with structures and arrays.
- Writing reusable functions.
- Applying recursion and pointers.
- Performing calculations using user input.
- Saving and retrieving records through file handling.

## Disclaimer

This project is intended for educational purposes only. It is not a financial advisory tool, and its calculations should not be used as the sole basis for investment decisions.

## License

No license has been added yet. Reuse and redistribution permissions should be specified by the project owner.

---

**Developed as a first-year CSE mini-project.**
