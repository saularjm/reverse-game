#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);
void fillBoard(int arr[], int len);
void printBoard(int arr[], int len);
void shuffleBoard(int arr[], int len);
void reverse(int arr[], int len);
int isSorted(int arr[], int len);

int main()
{
    // Seed the random number generator
    srandom(time(NULL));
        
    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board: ", 3, 20);
    
    // Create board. Shuffle numbers.
    int board[boardLength];
    
    // Fill board with numbers 1-boardLength
    fillBoard(board, boardLength);
    
    // Shuffle board
    while (isSorted(board, boardLength))
    {
        shuffleBoard(board, boardLength);
    }
    
    // Print board
    printBoard(board, boardLength);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers
        reverse(board, amt);
        
        // Print the board
        printBoard(board, boardLength);
        
        // Check to see if the game is over
        gameOver = isSorted(board, boardLength);
        
        moves++;
    }
    printf("You won in %d moves!\n", moves);
}

// Functions
int getInt(char prompt[], int min, int max)
{
    int start;
    do
    {
        printf("%s", prompt);
        scanf("%d", &start);
        if (start < min || start > max)
        {
            printf("Value must be in the range %d-%d\n", min, max);
        }
    }
    while(start < min || start > max);
    
    return start;
}

void fillBoard(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = i+1;
    }
}

void printBoard(int arr[], int len)
{
    printf("Board: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shuffleBoard(int arr[], int len)
{
    int temp; 
    
    for (int i = len - 1; i > 0; i--)
    {
        int j = random() % len;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

void reverse(int arr[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

int isSorted(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return 0;
        }
    }
    return 1;
}
