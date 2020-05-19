// Charles Kraemer
const int SIZE= 40;   // global variable- board size
const char ALIVE= 'X';  // global variable- alive character
const char DEAD= ' ';  // global variable- dead character

class Lifeboard
{
	public:
	  Lifeboard();
	  void display();
	  void add(int, int);
	  void remove(int, int);
	  void advance();
	private:
	  char board[SIZE][SIZE];
};
