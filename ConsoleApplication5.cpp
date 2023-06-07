#include<iostream>
#include <fstream>
using namespace std;

char conect4board[6][7] = {
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '}
};

int c1 = 6;
int c2 = 6;
int c3 = 6;
int c4 = 6;
int c5 = 6;
int c6 = 6;
int c7 = 6;

int insert(int x)
{

	if (x == 1) {
		if (c1 > 0) {
			c1--;
			return c1;
		}
		else
			return -1;
	}
	else if (x == 2) {
		if (c2 > 0) {
			c2--;
			return c2;
		}
		else
			return -1;
	}
	else if (x == 3) {
		if (c3 > 0) {
			c3--;
			return c3;
		}
		else
			return -1;
	}
	else if (x == 4) {
		if (c4 > 0)
		{
			c4--;
			return c4;
		}
		else
			return -1;
	}
	else if (x == 5) {
		if (c5 > 0) {
			c5--;
			return c5;
		}
		else
			return -1;
	}
	else if (x == 6) {
		if (c6 > 0) {
			c6--;
			return c6;
		}
		else
			return -1;
	}
	else if (x == 7) {
		if (c7 > 0) {
			c7--;
			return c7;
		}
		else
			return -1;
	}
	else
		return -1;

}

bool player1Row(int a)  //x için yanyana gelme durumu
{
	int count = 0;
	for (int j = 0; j < 7; j++) {
		if (conect4board[a][j] == 'X')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool player1Cross1(int a, int b)  //sol üstten sağ alta
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (conect4board[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (conect4board[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;

}

bool player1Cross2(int a, int b)  //sağ üstten sol alta
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (conect4board[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (conect4board[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;

}

bool player1Col(int a) //üstüste gelme durumu
{
	int count = 0;
	a--;
	for (int j = 0; j < 6; j++)
	{
		if (conect4board[j][a] == 'X')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool player2Row(int a)
{
	int count = 0;

	for (int j = 0; j < 7; j++)
	{
		if (conect4board[a][j] == 'O')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool player2Col(int a)
{
	int count = 0;
	a--;
	for (int j = 0; j < 6; j++)
	{
		if (conect4board[j][a] == 'O')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool player2Cross1(int a, int b)
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (conect4board[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (conect4board[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;

}

bool player2Cross2(int a, int b)
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (conect4board[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (conect4board[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;

}

void board(int a, int b, char x)  //Oyuncunun oynadığı hamleyi ekrana yazdırıyor.
{
	conect4board[a][b - 1] = x;
	for (int f = 1; f < 8; f++)
	{
		cout << f << '|';
	}
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << conect4board[i][j] << '|';
		}
		cout << endl;
	}
}
void saveBoardToFile() {
	ofstream file("Tahta.txt");

	if (file.is_open()) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				file << static_cast<int>(conect4board[i][j]) << " ";
			}
			file << std::endl;
		}

		file.close();
	}
	else {
		cout << "Unable to open file for board saving." << std::endl;
	}
}
void saveMoveToFile(int row, int col) {
	ofstream file("Hamle.txt", std::ios::app);

	if (file.is_open()) {
		file << row << ".satır " << col << ".sutün" << endl;
		file.close();
	}
	else {
		cout << "Unable to open file for move saving." << endl;
	}
}

int main()
{
	cout << " Connect4 Game" << endl;
	//Başlangıçta tahtayı yazdırıyoruz
	for (int f = 1; f < 8; f++) //başlık
	{
		cout << f << '|';
	}
	cout << endl;
	for (int i = 0; i < 6; i++)  //tahtanın devamı
	{
		for (int j = 0; j < 7; j++)
		{
			cout << conect4board[i][j] << '|';
		}
		cout << endl;
	}
	int c = 0;   //oynanılan tur sayısını tutacak
	while (c < 21)
	{
		int p1 = 0, p2 = 0;
		int col = 0;
		int k = 0;
		while (p1 < 1)
		{
			cout << "Player1" << endl << "Enter column: ";
			col = 0;
			cin >> col;
			k = insert(col);
			while (k == -1)
			{
				cout << "invalid place, Play Again: ";
				cin >> col;
				k = insert(col);
			}
			board(k, col, 'X');
			saveBoardToFile();
			saveMoveToFile(k, col);

			p1++;
		}
		if (player1Row(k) == true)
		{
			cout << "Player 1 is Winner" << endl << "Congratulations!!";
			break;
		}

		if (player1Col(col) == true)
		{
			cout << "Player 1 is Winner" << endl << "Congratulations!!";
			break;
		}

		if (player1Cross1(k, col) == true)
		{
			cout << "Player 1 is Winner" << endl << "Congratulations!!";
			break;
		}
		if (player1Cross2(k, col) == true)
		{
			cout << "Player 1 is Winner" << endl << "Congratulations!!";
			break;
		}

		while (p2 < 1)
		{
			cout << "Player2" << endl << "Enter column: ";
			col = 0;
			cin >> col;
			k = insert(col);
			while (k == -1)
			{
				cout << "invalid place, Play Again: ";
				cin >> col;
				k = insert(col);
			}
			board(k, col, 'O');
			p2++;
		}
		if (player2Row(k) == true)
		{
			cout << "Player 2 is Winner" << endl << "Congratulations!!";
			break;
		}
		if (player2Col(col) == true)
		{
			cout << "Player 2 is Winner" << endl << "Congratulations!!";
			break;
		}
		if (player2Cross1(k, col) == true)
		{
			cout << "Player 2 is Winner" << endl << "Congratulations!!";
			break;
		}
		if (player2Cross2(k, col) == true)
		{
			cout << "Player 2 is Winner" << endl << "Congratulations!!";
			break;
		}
		c++;
		if (c == 21)
		{
			cout << " No Winner";
		}
	}
}