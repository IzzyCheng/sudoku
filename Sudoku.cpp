#include "Sudoku.h"
void Sudoku::giveQuestion() {
	for (i=0; i<81; i++) {
		cout << num[i];
		if ((i+1)%9==0)
			cout << endl;
		else
			cout << " ";
	}
}
void Sudoku::readIn() {
	for (i=0; i<81; i++) {
		cin >> problem[i];
	}
}
void Sudoku::solve() {
	for (i=0; i<81; i++) {
		if (problem[i]!=0) {
			for (j=0; j<9; j++)
				pos[i][j]=false;
			pos[i][problem[i]-1]=true;
		}
		else
			for (j=0; j<9; j++)
				pos[i][j]=true;
	}
	while (empty!=tempt && empty!=0) {
		tempt=empty;
		for (i=0; i<81; i++) {
			if (problem[i]==0) {
				for (j=i%9; j<81; j+=9)
					if (problem[j]!=0)
						pos[i][problem[j]-1]=false;
				for (j=i-i%9; j<i-i%9+9; j++)
					if (problem[j]!=0)
						pos[i][problem[j]-1]=false;
				for (j=1, k=((i%9)*3+(i-i%9)/9-4*((i%9)%3)); j<10; j++) {
					if (problem[k]!=0)
						pos[i][problem[k]-1]=false;
					if ((j%3)==0)	k+=7;
					else			k++;
				}
				count=0;
				for (j=0; j<9; j++)
					if (pos[i][j]) {
						count++;
						answer=k+1;
					}
				if (count==1) problem[i]=answer;
			}
		}

		empty=0;
		for (i=0; i<81; i++)
			if (problem[i]!=0)	empty++;

		for (i=0; i<81; i++)
			if (problem[i]!=0) {
				for (j=i%9; j<81; j+=9)
					if (problem[i]==problem[j] && i!=j) {
						cout << "0" << endl;
						return;
					}
				for (j=i-i%9; j<i-i%9+9; j++)
					if (problem[i]==problem[j] && i!=j) {
						cout << "0" << endl;
						return;
					}
				for (j=1, k=((i%9)*3+(i-i%9)/9-4*((i%9)%3)); j<10; j++) {
					if (problem[i]==problem[k] && i!=k) {
						cout << "0" << endl;
						return;
					}
					if ((j%3)==0)	k+=7;
					else			k++;
				}
			}
	}

	if (empty!=0) {
		cout << "2" << endl;
		return;
	}
	else	cout << "1" << endl;

	for (i=0; i<81; i++) {
		cout << problem[i];
		if ((i+1)%9==0)	cout << endl;
		else			cout << " ";
		cout << endl;
	}
}
void Sudoku::changeNum(int a, int b) {
	for (i=0; i<81; i++) {
		if (problem[i]==a)
			problem[i]=b;
		else if (problem[i]==b)
			problem[i]=a;
	}
}
void Sudoku::changeRow(int a, int b) {
	int tmp[27];
	for (i=27*a, j=0; i<27*a+27; i++, j++)
		tmp[j]=problem[i];
	for (i=27*a, j=27*b; i<27*a+27; i++, j++)
		problem[i]=problem[j];
	for (i=0, j=27*b; i<27; i++, j++)
		problem[j]=tmp[i];
}
void Sudoku::changeCol(int a, int b) {
	int tmp[27];
	for (i=0, j=3*a; i<27; i++) {
		tmp[i]=problem[j];
		if (j%3==2)	j+=7;
		else 		j++;
	}
	for (i=3*a, j=3*b; i<3*a+75; ) {
		problem[i]=problem[j];
		if (i%3==2) { i+=7;	j+=7; }
		else 		{ i++;	j++; }
	}
	for (i=0, j=3*b; i<27; i++) {
		problem[j]=tmp[i];
		if (j%3==2)	j+=7;
		else		j++;
	}
}
void Sudoku::rotate(int n) {
	int tmp[81];
	for (i=0; i<n; i++) {
		k=8;
		for (j=0; j<81; j++) {
			tmp[k+(j%9)*9]=problem[j];
			if ((j+1)%9==0)	k--;
		}
		for (i=0; i<81; i++)
			problem[i]=tmp[i];
	}
}
void Sudoku::flip(int n) {
	int tmp[9];
	if (n==0) {
		for (i=0; i<36; i+=9) {
			for (j=i, k=0, l=72-i; k<9; j++, l++, k++) {
				tmp[k]=problem[j];
				problem[j]=problem[l];
				problem[l]=tmp[k];
			}
		}
	}
	else {
		for (i=0; i<4; i++) {
			for (j=i, k=0, l=8-i; k<9; j+=9, k++, l+=9) {
				tmp[k]=problem[j];
				problem[j]=problem[l];
				problem[l]=tmp[j];
			}
		}
	}
}
void Sudoku::transform() {
	srand(time(NULL));
	readIn();
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for (i=0; i<81; i++) {
		cout << problem[i];
		if ((i+1)%9==0)	cout << endl;
		else			cout << " ";
	}
}

