#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


int main()
{
/*  - chip sequence의 길이가 8
	- 4개의 transmitter가 있고 transmitter는 각각 1개의 bit를 가진다
	- 4개의 receiver
	- input은 biopolar notation(-1, 1)의 4개의 chip sequence(즉, 8로 구성된 chip sequence 4개가 입력된다).c
	- transmitter에서 보낸 4bit를 읽어야하고
	- 각각의 transmiiter / receiver 쌍은 하나의 chip sequence(8 bit)를 할당받는다
	- transmitter가 chip sequence를 통한 8 bit 시그널을 계산한다
	예를 들어 t0에서 1을 보내는 chip sequence를 지나면(1 - 1 - 1 1 - 1 1 1 - 1)의 signal이 된다
	- joiner에서 4개의 transmitter에서 보낸 signal(1 - 1 - 1 - 1 1 - 1 1 1 - 1 등의 signal)을 합치고 합친걸 receiver에 보낸다
	- receiver에서 inner product로 계산해서 어떤 transmitter에서 보냈는지 확인한다

*/

	const int chip_length = 8;

	int transmitter[4];


	//make chip sequence by random number
	srand((unsigned int)time(NULL));

	int** input_chip = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		input_chip[i] = new int[chip_length];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < chip_length; j++)
		{
			input_chip[i][j] = rand() % 2;
			if (input_chip[i][j] == 0)
				input_chip[i][j] = -1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "chip " << i + 1 << " : ";
		for (int j = 0; j < chip_length; j++)
		{
			cout << setfill(' ');
			cout << setw(5) << input_chip[i][j] << " ";
		}
		std::cout << "\n";
	}

	// Read transmit bit
	// transmitt 1 == -1 means negation  
	cout << "Read transmitter 1 : ";
	cin >> transmitter[0];
	cout << "\nRead transmitter 2 : ";
	cin >> transmitter[1];
	cout << "\nRead transmitter 3 : ";
	cin >> transmitter[2];
	cout << "\nRead transmitter 4 : ";
	cin >> transmitter[3];

	int signal[4][chip_length] = { 0 };


	//compute chip signal into signal
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < chip_length; j++)
		{
			signal[i][j] = transmitter[i] * input_chip[i][j];
		}
	}

	cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "Signal" << (i + 1) << " : ";

		for (int j = 0; j < chip_length; j++)
		{
			cout << setfill(' ');
			cout << setw(5) << signal[i][j] << " ";
		}
		cout << "\n";
	}


	cout << "\n";


	// joiner process
	// join all signal (signal1 + signal2 + signal3 + signal4)
	int joiner[chip_length] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < chip_length; j++)
		{
			joiner[j] += signal[i][j];
		}
	}

	cout << "Joiner  : ";

	for (int i = 0; i < chip_length; i++)
	{
		cout << setfill(' ');
		cout << setw(5) << joiner[i] << " ";
	}

	cout << "\n\n";

	//receive process
	int receiver[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < chip_length; j++)
		{
			receiver[i] += signal[i][j] * joiner[j];
		}
		receiver[i] /= chip_length;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "Receiver " << (i + 1) << " : ";
		cout << setfill(' ');
		cout << setw(5) << receiver[i] << endl;
	}


	for (int i = 0; i < 4; i++)
		delete[] input_chip[i];
	delete[] input_chip;

	return 0;
}