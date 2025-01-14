#include <stdio.h> // Include standard input-output library

#define SIZE 3 // Define the size of the board

// Function to initialize the board with empty spaces
void initializeBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) // Loop through each row
    {
        for (int j = 0; j < SIZE; j++) // Loop through each column
        {
            board[i][j] = ' '; // Set each cell to an empty space
        }
    }
}

// Function to print the current state of the board
void printBoard(char board[SIZE][SIZE])
{
    printf("  0 1 2\n");           // Print the column indices
    for (int i = 0; i < SIZE; i++) // Loop through each row
    {
        printf("%d ", i);              // Print the row index
        for (int j = 0; j < SIZE; j++) // Loop through each column
        {
            printf("%c", board[i][j]); // Print the cell content
            if (j < SIZE - 1)          // If not the last column, print a separator
                printf("|");
        }
        printf("\n");     // Move to the next line after each row
        if (i < SIZE - 1) // If not the last row, print a row separator
            printf("  -+-+-\n");
    }
}

// Function to check if the current player has won
int checkWin(char board[SIZE][SIZE], char player)
{
    // Check rows (horizontally)
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Return 1 if the player has won horizontally
    }
    // Check columns (vertically)
    for (int i = 0; i < SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Return 1 if the player has won vertically
    }
    // Check diagonals (diagonally)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Return 1 if the player has won on the main diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Return 1 if the player has won on the secondary diagonal

    return 0; // Return 0 if the player has not won
}

// Function to check if the game is a draw
int checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) // Loop through each row
    {
        for (int j = 0; j < SIZE; j++) // Loop through each column
        {
            if (board[i][j] == ' ')
                return 0; // Return 0 if there is still an empty cell
        }
    }
    return 1; // Return 1 if there are no empty cells (draw)
}

// Function to handle a player's move
void playerMove(char board[SIZE][SIZE], char player)
{
    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (row and column): ", player); // Prompt player for move
        scanf("%d %d", &row, &col);                                      // Read the row and column
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ')
        {
            board[row][col] = player; // If the move is valid, place the player's mark
            break;                    // Exit the loop
        }
        else
        {
            printf("Invalid move. Try again.\n"); // If the move is invalid, prompt again
        }
    }
}

int main()
{
    char board[SIZE][SIZE];   // Declare the board
    char currentPlayer = 'X'; // Set the first player to 'X'
    initializeBoard(board);   // Initialize the board

    while (1) // Main game loop
    {
        printBoard(board);                  // Print the current state of the board
        playerMove(board, currentPlayer);   // Get the current player's move
        if (checkWin(board, currentPlayer)) // Check if the current player has won
        {
            printBoard(board);                          // Print the board one last time
            printf("Player %c wins!\n", currentPlayer); // Announce the winner
            break;                                      // Exit the loop
        }
        if (checkDraw(board)) // Check if the game is a draw
        {
            printBoard(board);               // Print the board one last time
            printf("The game is a draw!\n"); // Announce the draw
            break;                           // Exit the loop
        }
        // Switch player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0; // End the program
}
