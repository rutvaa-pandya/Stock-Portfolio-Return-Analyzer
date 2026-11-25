#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Stock
{
    int id;
    char name[30];
    float purchasePrice;
    float currentPrice;
    int quantity;
};

struct Stock s[100];
int count = 0;

void loadData();
void saveData();
void addStock();
void viewStocks();
void showSummary();
void bestStock();
float totalInvestment(int n);
float totalCurrentValue(int n);
void calculateValues(float *investment, float *current);

void main()
{
    int choice;

    loadData();

    do
    {
        clrscr();

        printf("====================================\n");
        printf("     STOCK PORTFOLIO RETURN ANALYZER\n");
        printf("====================================\n");
        printf("1. Add Stock\n");
        printf("2. View All Stocks\n");
        printf("3. Portfolio Summary\n");
        printf("4. Best Performing Stock\n");
        printf("5. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStock();
                break;

            case 2:
                viewStocks();
                break;

            case 3:
                showSummary();
                break;

            case 4:
                bestStock();
                break;

            case 5:
                saveData();
                printf("\nThank you for using the program!");
                getch();
                break;

            default:
                printf("\nInvalid choice!");
                getch();
        }

    } while(choice != 5);
}

void loadData()
{
    FILE *fp;

    fp = fopen("stocks.txt", "rb");

    if(fp == NULL)
        return;

    count = 0;

    while(count < 100 &&
          fread(&s[count], sizeof(struct Stock), 1, fp) == 1)
    {
        count++;
    }

    fclose(fp);
}

void saveData()
{
    FILE *fp;

    fp = fopen("stocks.txt", "wb");

    if(fp == NULL)
    {
        printf("\nError saving records!");
        return;
    }

    fwrite(s, sizeof(struct Stock), count, fp);

    fclose(fp);
}

void addStock()
{
    clrscr();

    if(count >= 100)
    {
        printf("Stock record limit reached!");
        getch();
        return;
    }

    printf("       ADD STOCK DETAILS\n");
    printf("--------------------------------\n");

    printf("Enter stock name (one word): ");
    scanf("%29s", s[count].name);

    printf("Enter purchase price: Rs. ");
    scanf("%f", &s[count].purchasePrice);

    if(s[count].purchasePrice <= 0)
    {
        printf("\nPurchase price must be greater than zero!");
        getch();
        return;
    }

    printf("Enter current price: Rs. ");
    scanf("%f", &s[count].currentPrice);

    if(s[count].currentPrice < 0)
    {
        printf("\nCurrent price cannot be negative!");
        getch();
        return;
    }

    printf("Enter quantity purchased: ");
    scanf("%d", &s[count].quantity);

    if(s[count].quantity <= 0)
    {
        printf("\nQuantity must be greater than zero!");
        getch();
        return;
    }

    s[count].id = count + 1;

    count++;

    saveData();

    printf("\nStock added successfully!");
    getch();
}

void viewStocks()
{
    int i;
    float investment, current, profit, returns;

    clrscr();

    printf("          STOCK DETAILS\n");
    printf("----------------------------------------\n");

    if(count == 0)
    {
        printf("No stocks recorded yet.");
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            investment = s[i].purchasePrice * s[i].quantity;

            current = s[i].currentPrice * s[i].quantity;

            profit = current - investment;

            returns = (profit / investment) * 100;

            printf("\nID: %d", s[i].id);
            printf("\nStock: %s", s[i].name);
            printf("\nPurchase Price: Rs. %.2f",
                   s[i].purchasePrice);
            printf("\nCurrent Price: Rs. %.2f",
                   s[i].currentPrice);
            printf("\nQuantity: %d", s[i].quantity);
            printf("\nInvestment: Rs. %.2f", investment);
            printf("\nCurrent Value: Rs. %.2f", current);
            printf("\nProfit/Loss: Rs. %.2f", profit);
            printf("\nReturn: %.2f%%", returns);
            printf("\n----------------------------------------\n");
        }
    }

    getch();
}

float totalInvestment(int n)
{
    if(n == 0)
        return 0;

    return s[n - 1].purchasePrice * s[n - 1].quantity
           + totalInvestment(n - 1);
}

float totalCurrentValue(int n)
{
    if(n == 0)
        return 0;

    return s[n - 1].currentPrice * s[n - 1].quantity
           + totalCurrentValue(n - 1);
}

void calculateValues(float *investment, float *current)
{
    *investment = totalInvestment(count);
    *current = totalCurrentValue(count);
}

void showSummary()
{
    float investment, current, profit, returns;

    clrscr();

    calculateValues(&investment, &current);

    profit = current - investment;

    printf("      PORTFOLIO SUMMARY\n");
    printf("-----------------------------------\n");
    printf("Number of Stocks: %d\n", count);
    printf("Total Investment: Rs. %.2f\n", investment);
    printf("Current Value: Rs. %.2f\n", current);
    printf("-----------------------------------\n");

    printf("Total Profit/Loss: Rs. %.2f\n", profit);

    if(investment > 0)
    {
        returns = (profit / investment) * 100;

        printf("Overall Return: %.2f%%\n", returns);
    }
    else
    {
        printf("Overall Return: 0.00%%\n");
    }

    if(profit > 0)
        printf("\nYour portfolio has a profit.");
    else if(profit < 0)
        printf("\nYour portfolio has a loss.");
    else
        printf("\nYour portfolio is at break-even.");

    getch();
}

void bestStock()
{
    int i, best = 0;
    float investment, current, returns, bestReturn;

    clrscr();

    if(count == 0)
    {
        printf("No stocks recorded yet.");
        getch();
        return;
    }

    investment = s[0].purchasePrice * s[0].quantity;
    current = s[0].currentPrice * s[0].quantity;

    bestReturn = ((current - investment) / investment) * 100;

    for(i = 1; i < count; i++)
    {
        investment = s[i].purchasePrice * s[i].quantity;
        current = s[i].currentPrice * s[i].quantity;

        returns = ((current - investment) / investment) * 100;

        if(returns > bestReturn)
        {
            bestReturn = returns;
            best = i;
        }
    }

    printf("     BEST PERFORMING STOCK\n");
    printf("-----------------------------------\n");
    printf("Stock Name: %s\n", s[best].name);
    printf("Purchase Price: Rs. %.2f\n",
           s[best].purchasePrice);
    printf("Current Price: Rs. %.2f\n",
           s[best].currentPrice);
    printf("Quantity: %d\n", s[best].quantity);
    printf("Return: %.2f%%\n", bestReturn);

    getch();
}
