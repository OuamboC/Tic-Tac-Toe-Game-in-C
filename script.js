const board = document.querySelector(".board");
const cells = document.querySelectorAll(".cell");
const resetButton = document.getElementById("reset");
let currentPlayer = "X";
let gameBoard = Array(9).fill("");

// Function to check for a win
function checkWin(player) {
  const winConditions = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];
  return winConditions.some((condition) =>
    condition.every((index) => gameBoard[index] === player)
  );
}

// Function to check for a draw
function checkDraw() {
  return gameBoard.every((cell) => cell !== "");
}

// Function to handle cell clicks
function handleCellClick(event) {
  const cell = event.target;
  const index = cell.getAttribute("data-index");

  if (gameBoard[index] !== "") return;

  gameBoard[index] = currentPlayer;
  cell.textContent = currentPlayer;

  if (checkWin(currentPlayer)) {
    setTimeout(() => alert(`Player ${currentPlayer} wins!`), 100);
    resetBoard();
    return;
  }

  if (checkDraw()) {
    setTimeout(() => alert("The game is a draw!"), 100);
    resetBoard();
    return;
  }

  currentPlayer = currentPlayer === "X" ? "O" : "X";
}

// Function to reset the board
function resetBoard() {
  gameBoard.fill("");
  cells.forEach((cell) => (cell.textContent = ""));
  currentPlayer = "X";
}

// Add event listeners
board.addEventListener("click", handleCellClick);
resetButton.addEventListener("click", resetBoard);
