#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Sudoku {
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
	private:
	int num[81]={9,2,0,0,0,0,0,0,0,5,0,0,8,7,0,0,0,0,0,3,8,6,9,1,0,0,0,0,5,2,9,3,0,1,6,0,0,9,0,0,0,0,0,3,0,0,7,3,0,6,4,9,8,0,0,0,0,4,1,0,2,5,0,0,0,0,0,5,3,0,0,1,0,0,0,0,0,0,0,7,3};
	int problem[81];
	bool pos[81][9];
	int i, j, k, l, empty=81, tempt=0, count, answer;
};
