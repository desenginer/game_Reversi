/* ____________________________________________________________________________
 * Abstract: Main module. A simple C++ console program.
 * Description: This program is a solution to a study task.
 * Creation Date: 2021/12/14
 * Author: Pogonov Dmitry
 * Platform: MS Windows / UNIX / Linux
 * ____________________________________________________________________________
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <iostream>

//Оценочная функция состояния
int grade(int (*board)[10]) //в функцию передаётся массив, в  
{					//каждой ячейке которого - состояние 
	int result {};		       //соответствующей клетки игрового поля
	int white {};		   //0 - клетка пустая, 1-белая фишка,
	int black {};		   //2 - чёрная фишка
	int k = 7;				   //коэффициент важности угла 
	for (int i = 1; i < 9; i++) //подсчёт кол-ва фишек
	{
		for (int j = 1; j < 9; j++)
		{
			if (board[i][j] == 1) white++;
			if (board[i][j] == 2) black++;
		}
	}
	if (white == 0) return 999;
	if (black == 0) return -999;
	if (board[1][1] != 0)	//проверяем, заняты ли углы доски
	{
		if (board[1][1] == 1) white += k;
		else black += k;  //соответствующему игроку добавляем k
	}
	if (board[1][8] != 0)
	{
		if (board[1][8] == 1) white += k;
		else black += k;
	}
	if (board[8][1] != 0)
	{
		if (board[8][1] == 1) white += k;
		else black += k;
	}
	if (board[8][8] != 0)
	{
		if (board[8][8] == 1) white += k;
		else black += k;
	}
	result = black - white;		//расчёт разности фишек
	return result;
}

//изменение поля после хода
void change(int(*board)[10], bool player, int i, int j)
{                      //i, j - координаты точки, в которую ставится шашка
	int ii = i;		   //для временного хранения положения
	int jj = j;
	if (player == 0)   //если ход делает белый игрок
	{
		board[i][j] = 1;
		if (board[i + 1][j] == 2)
		{
			i += 1;
			while (board[i][j] == 2) i++;           //пока фишки противника стоят в ряд
			if (i < 9 && i > 0 && board[i][j] == 1) //если мы не вышли за поле и данная фишка наша
			{
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][j] = 1;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j] == 2)
		{
			i -= 1;
			while (board[i][j] == 2) i--;
			if (i < 9 && i > 0 && board[i][j] == 1)
			{
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][j] = 1;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i][j + 1] == 2)
		{
			j += 1;
			while (board[i][j] == 2) j++;
			if (j < 9 && j > 0 && board[i][j] == 1)
			{
				for (int m = jj + 1; m <= j; m++)
				{
					board[i][m] = 1;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i][j - 1] == 2)
		{
			j -= 1;
			while (board[i][j] == 2) j--;
			if (j < 9 && j > 0 && board[i][j] == 1)
			{
				for (int m = jj - 1; m >= j; m--)
				{
					board[i][m] = 1;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i + 1][j + 1] == 2)
		{
			i += 1;
			j += 1;
			while (board[i][j] == 2)
			{
				i++;
				j++;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 1)
			{
				int m = jj + 1;
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][m] = 1;
					m++;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j + 1] == 2)
		{
			i -= 1;
			j += 1;
			while (board[i][j] == 2)
			{
				i--;
				j++;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 1)
			{
				int m = jj + 1;
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][m] = 1;
					m++;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i + 1][j - 1] == 2)
		{
			i += 1;
			j -= 1;
			while (board[i][j] == 2)
			{
				i++;
				j--;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 1)
			{
				int m = jj - 1;
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][m] = 1;
					m--;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j - 1] == 2)
		{
			i -= 1;
			j -= 1;
			while (board[i][j] == 2)
			{
				i--;
				j--;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 1)
			{
				int m = jj - 1;
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][m] = 1;
					m--;
				}
			}
			i = ii;
			j = jj;
		}
	}
	else			   //если ход делает чёрный игрок
	{
		board[i][j] = 2;
		if (board[i + 1][j] == 1)
		{
			i += 1;
			while (board[i][j] == 1) i++;           //пока фишки противника стоят в ряд
			if (i < 9 && i > 0 && board[i][j] == 2) //если мы не вышли за поле и данная фишка наша
			{
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][j] = 2;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j] == 1)
		{
			i -= 1;
			while (board[i][j] == 1) i--;
			if (i < 9 && i > 0 && board[i][j] == 2)
			{
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][j] = 2;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i][j + 1] == 1)
		{
			j += 1;
			while (board[i][j] == 1) j++;
			if (j < 9 && j > 0 && board[i][j] == 2)
			{
				for (int m = jj + 1; m <= j; m++)
				{
					board[i][m] = 2;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i][j - 1] == 1)
		{
			j -= 1;
			while (board[i][j] == 1) j--;
			if (j < 9 && j > 0 && board[i][j] == 2)
			{
				for (int m = jj - 1; m >= j; m--)
				{
					board[i][m] = 2;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i + 1][j + 1] == 1)
		{
			i += 1;
			j += 1;
			while (board[i][j] == 1)
			{
				i++;
				j++;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 2)
			{
				int m = jj + 1;
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][m] = 2;
					m++;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j + 1] == 1)
		{
			i -= 1;
			j += 1;
			while (board[i][j] == 1)
			{
				i--;
				j++;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 2)
			{
				int m = jj + 1;
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][m] = 2;
					m++;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i + 1][j - 1] == 1)
		{
			i += 1;
			j -= 1;
			while (board[i][j] == 1)
			{
				i++;
				j--;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 2)
			{
				int m = jj - 1;
				for (int n = ii + 1; n <= i; n++)
				{
					board[n][m] = 2;
					m--;
				}
			}
			i = ii;
			j = jj;
		}
		if (board[i - 1][j - 1] == 1)
		{
			i -= 1;
			j -= 1;
			while (board[i][j] == 1)
			{
				i--;
				j--;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 2)
			{
				int m = jj - 1;
				for (int n = ii - 1; n >= i; n--)
				{
					board[n][m] = 2;
					m--;
				}
			}
			i = ii;
			j = jj;
		}
	}
}

//Второстепенная функция для MoveOption
bool preMove(int(*board)[10], int y, int x, int i, int j, bool player) //проверяет одно направление от шашки
{																		 //x, y - задают направление
	bool result{};
	if (player == 0)
	{
		if (board[i + y][j + x] == 2)
		{
			i += y;
			j += x;
			while (board[i][j] == 2)
			{
				i += y;
				j += x;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 1) result = 1;
		}
	}
	else
	{
		if (board[i + y][j + x] == 1)
		{
			i += y;
			j += x;
			while (board[i][j] == 1)
			{
				i += y;
				j += x;
			}
			if (j < 9 && j > 0 && i < 9 && i > 0 && board[i][j] == 2) result = 1;
		}
	}
	return result;
}

//есть ли возможность поставить фишку в данную клетку
bool MoveOption(int(*board)[10], bool player, int i, int j)
{   //если клетка свободна и по правилам игры в неё можно сходить 
	if (board[i][j] == 0 && preMove(board, 0, 1, i, j, player) == 1) return 1; 
	if (board[i][j] == 0 && preMove(board, 0, -1, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, 1, 1, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, 1, 0, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, 1, -1, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, -1, 1, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, -1, 0, i, j, player) == 1) return 1;
	if (board[i][j] == 0 && preMove(board, -1, -1, i, j, player) == 1) return 1;
	return 0;
}

//Выводит количество возможных ходов
int numOption(int(*board)[10], bool player)
{
	int count{};
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (MoveOption(board, player, i, j) == 1) count++;
		}
	}
	return count;
}
//Основная функция для работы "Бота"
int minmax(int(*board)[10], int lavel, int alpha, int beta)
{
	if (numOption(board, lavel % 2) == 0 || lavel == 6) return grade(board); 
	//Если ходов нет или мы дошли до 5 уровня, то возвращаем оценку

	if (lavel % 2 == 1) //Уровень max
	{
		if (lavel == 1) //если находимся на первом уровне 
		{
			int* arrG = new int[64]; //создаём массив значений g
			for (int i = 0; i < 64; i++) arrG[i] = -999; //заполнение дин. массива 
			int k{};  //счётчик для дин. массива
			for (int i = 1; i < 9; i++)
			{
				for (int j = 1; j < 9; j++)
				{
					if (MoveOption(board, lavel % 2, i, j) == 1)
					{
						int cboard[10][10];
						memcpy(cboard, board, sizeof(int) * 100);
						change(cboard, lavel % 2, i, j);
						arrG[k] = i*(-100);		//записываем координаты каждого хода
						arrG[k+1] = j*(-100);	//чтобы понять, какой конкретно ход дал наилучшее значение
						arrG[k+2] = minmax(cboard, lavel + 1, alpha, beta);
						k += 3;
					}
				}
			}
			int max{-99};
			int ii{};
			for (int i = 0; i < 64; i++)
			{
				if (arrG[i] > max)
				{
					max = arrG[i];
					ii = i;
				}
			}
			int result{};
			result = (arrG[ii - 1] / (-10)) + (arrG[ii - 2] / (-100));
			//результат - двузначное число, первый символ которого j, второй - i
			delete[] arrG;
			return result;
		}
		else
		{
			int g{ -9999 };
			for (int i = 1; i < 9; i++)
			{									//проходим по всем клеткам поля
				for (int j = 1; j < 9; j++)
				{							//если нашли ту, в которой можно сделать ход
					if (MoveOption(board, lavel % 2, i, j) == 1)
					{
						int cboard[10][10];
						memcpy(cboard, board, sizeof(int) * 100);
						change(cboard, lavel % 2, i, j);				//делаем "мнимый" ход
						g = std::max(g, (minmax(cboard, lavel + 1, alpha, beta)));	//вызываем рекурсию
						alpha = std::max(g, alpha);
						if (g < beta) return g;
					}
				}
			}
			return g;
		}
	}
	else				//Уровень min
	{
		int g{ 9999 };
		for (int i = 1; i < 9; i++)
		{									//проходим по всем клеткам поля
			for (int j = 1; j < 9; j++)
			{							//если нашли ту, в которой можно сделать ход
				if (MoveOption(board, lavel % 2, i, j) == 1)
				{
					int cboard[10][10];
					memcpy(cboard, board, sizeof(int) * 100);
					change(cboard, lavel % 2, i, j);				//делаем "мнимый" ход
					g = std::min(g, (minmax(cboard, lavel + 1, alpha, beta)));	//вызываем рекурсию
					beta = std::min(g, beta);
					if (g > alpha) return g;
				}
			}
		}
		return g;
	}
}

//функция вывода поля
void print(int(*board)[10])
{
	std::cout << "\n\x1b[1m   A   B   C   D   E   F   G   H  \x1b[0m \n";
	std::cout << " ---------------------------------\n";
	for (int i = 1; i < 9; i++)
	{
		std::cout << "\x1b[1m" << i << "\x1b[0m|";
		for (int j = 1; j < 9; j++)
		{
			if (board[i][j] == 0) std::cout << "   |";
			else 
			{
				if (board[i][j] == 1) std::cout << " \x1b[93mo\x1b[0m |";
				else std::cout << " \x1b[94mo\x1b[0m |";
			}
		}
		std::cout << "\n ---------------------------------\n";
	}
}

//функция проверки окончания игры
bool gameover(int(*board)[10])
{
	int pc{};		//счётчики
	int man{};
	int voidCell{};
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (board[i][j] == 0) voidCell++;
			if (board[i][j] == 1) man++;
			if (board[i][j] == 2) pc++;
		}
	}
	if (numOption(board, 0) == 0 && numOption(board, 0) == 1)
	{
		std::cout << "Ходов больше нет. ";
		if (man > pc) std::cout << "\x1b[93m Человек выиграл! \x1b[0m\n";
		if (man < pc) std::cout << "\x1b[94m Компьютер выиграл! \x1b[0m\n";
		if (man == pc)  std::cout << " Конец игры. Боевая ничья!! \n";
		return 1;
	}
	if (pc == 0 || man == 0 || voidCell == 0)
	{
		if (pc == 0) 
		{
			std::cout << "\x1b[93m Конец игры. Человек выиграл!! \x1b[0m\n";
			exit(1);
		}
		if (man == 0)
		{
			std::cout << "\x1b[94m Конец игры. Компьютер выиграл!! \x1b[0m\n";
			exit(1);
		}
		if (voidCell == 0)
		{
			if (man > pc)
			{
				std::cout << "\x1b[93m Конец игры. Человек выиграл!! \x1b[0m\n";
				exit(1);
			}
			if (man < pc)
			{
				std::cout << "\x1b[94m Конец игры. Компьютер выиграл!! \x1b[0m\n";
				exit(1);
			}
			if (man == pc)
			{
				std::cout << " Конец игры. Боевая ничья!! \n";
				exit(1);
			}
		}
		return 1;
	}
	else return 0;
}

//функции проверки верности введённых значений
int inrows()
{
	int num{}; //поле ввода
	int k{};  //счётчик
	while (k < 3)
	{
		std::cout << "Введите номер строки (1-8): ";
		std::cin >> num; 
		if (!std::cin.good() || num < 1 || num>8)
		{
			if (k == 2)
			{
				std::cout << "\x1b[31mСлишком много попыток ввода, завершение работы игры!\x1b[0m\n";
				exit(-1);
			}
			std::cout << "\x1b[31mОшибка. Введён неверный параметр, попробуйте ввести значение ещё раз.\x1b[0m" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			k++;
		}
		else return num;
	}
}

int incolumns()
{
	char col{}; //поле ввода
	int k{};  //счётчик
	while (k < 3)
	{
		std::cout << "Введите букву столбца (A-H): ";
		std::cin >> col;
		col = tolower(col);				//переводим в нижний регистр
		if (!std::cin.good() || ((int)col - 96) < 1 || ((int)col - 96) > 8)
		{
			if (k == 2)
			{
				std::cout << "\x1b[31mСлишком много попыток ввода, завершение работы игры!\x1b[0m\n";
				exit(-1);
			}
			std::cout << "\x1b[31mОшибка. Введён неверный параметр, попробуйте ввести значение ещё раз.\x1b[0m" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			k++;
		}
		else return (int)col - 96;
	}
}

int prov(int(*board)[10])
{
	int rows{};
	int columns{};
	int k{};
	while (k < 3)
	{
		if (k == 2)
		{
			std::cout << "\x1b[31mСлишком много попыток ввода, завершение работы игры!\x1b[0m\n";
			exit(-1);
		}
		columns = incolumns();
		rows = inrows();
		if (MoveOption(board, 0, rows, columns) == 0)
		{
			std::cout << "\x1b[31mОшибка. В данную клетку нельзя сходить. Попробуйте ещё раз.\x1b[0m" << std::endl;
			k++;
		}
		else return (columns * 10) + rows;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int board[10][10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 1, 2, 0, 0, 0, 0,
					  0, 0, 0, 0, 2, 1, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool player1 = 0;  //человек
	bool player2 = 1;  //компьютер

	std::cout << "  _________________________________________________\n";
	std::cout << " |       Nizhniy Novgorod Technical University     |\n";
	std::cout << " |                Study course work.               |\n";
	std::cout << " |       Performed student 20-IVT-2 Pogonov D.     |\n";
	std::cout << " |_________________________________________________|\n";
	std::cout << "Игра Реверси (Отелло)\n";
	std::cout << "\x1b[93mo\x1b[0m - фишки человека\n";
	std::cout << "\x1b[94mo\x1b[0m - фишки компьютера\n";
	print(board);
	while (gameover(board) == 0)
	{
		std::cout << "Ход человека\n";
		int res{};
		if (numOption(board, player1) > 0)
		{
			res = prov(board);
			change(board, player1, res % 10, res / 10);
			print(board);
		}
		else std::cout << "У человека нет ходов\n";
		gameover(board);
		std::cout << "Ход компьютера\n";
		res = minmax(board, 1, 99999, -99999);
		std::cout << "Компьютер сходил: " << res / 10 << " - столбец\n";
		std::cout << "                  " << res % 10 << " - строка\n";
		change(board, player2, res % 10, res / 10);
		print(board);
	}
	return 1;
}

