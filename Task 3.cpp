#include <iostream>
#include <vector>
using namespace std;
void drawBoard(const vector<vector<char>> &board)
{
  for(const auto &row: board){
      for(char cell:row){
    	cout<<cell<<" ";
    	}
      cout<<endl;
  }
}

bool checkWin(const vector<vector<char>> &board,char player){
  // Check rows, columns, and diagonals for a win
  for(int i = 0; i < 3; ++i){
      if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
          (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
          return true;
      }
  }

  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player)){
      return true;
  }
  return false;
}

bool checkDraw(const vector<vector<char>> &board){
  for(const auto &row : board){
      for (char cell : row){
          if (cell == ' '){
              return false;
          }
      }
  }
  return true;
}

void playGame()
{
  vector<vector<char>> board(3, vector<char>(3, ' '));
  char currentPlayer = 'X';
  int row, col;
  bool gameOver = false;

  while (!gameOver){
      drawBoard(board);
      cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
      cin >> row >> col;

      if (board[row][col] == ' ')
      {
          board[row][col] = currentPlayer;
          gameOver = checkWin(board, currentPlayer);

          if (gameOver)
          {
              drawBoard(board);
              cout << "Player " << currentPlayer << " wins!" << endl;
          }
          else if (checkDraw(board))
          {
              drawBoard(board);
              cout << "It's a draw!"<< endl;
              gameOver = true;
          }

          currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
      }
      else
      {
          cout << "That spot is already taken. Try again." << endl;
      }
  }
}

int main()
{
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y')
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}
