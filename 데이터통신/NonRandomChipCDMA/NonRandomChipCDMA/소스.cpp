#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


int main()
{
	/*-chip sequence�� ���̰� 8
	- 4���� transmitter�� �ְ� transmitter�� ���� 1���� bit�� ������
	- 4���� receiver
	- input�� biopolar notation(-1, 1)�� 4���� chip sequence(��, 8�� ������ chip sequence 4���� �Էµȴ�).c
	- transmitter���� ���� 4bit�� �о���ϰ�
	- ������ transmiiter / receiver ���� �ϳ��� chip sequence(8 bit)�� �Ҵ�޴´�
	- transmitter�� chip sequence�� ���� 8 bit �ñ׳��� ����Ѵ�
	���� ��� t0���� 1�� ������ chip sequence�� ������(1 - 1 - 1 1 - 1 1 1 - 1)�� signal�� �ȴ�
	- joiner���� 4���� transmitter���� ���� signal(1 - 1 - 1 - 1 1 - 1 1 1 - 1 ���� signal)�� ��ġ�� ��ģ�� receiver�� ������
	- receiver���� inner product�� ����ؼ� � transmitter���� ���´��� Ȯ���Ѵ�

*/
	const int chip_length = 8;

	int transmitter[4];


	//make chip sequence by non-random number

	int** input_chip = new int* [4];
	for (int i = 0; i < 4; i++)
		input_chip[i] = new int[chip_length];

	input_chip[0][0] = -1;
	input_chip[0][1] = -1;
	input_chip[0][2] = -1;
	input_chip[0][3] = 1;
	input_chip[0][4] = 1;
	input_chip[0][5] = -1;
	input_chip[0][6] = 1;
	input_chip[0][7] = 1;

	input_chip[1][0] = -1;
	input_chip[1][1] = -1;
	input_chip[1][2] = 1;
	input_chip[1][3] = -1;
	input_chip[1][4] = 1;
	input_chip[1][5] = 1;
	input_chip[1][6] = 1;
	input_chip[1][7] = -1;

	input_chip[2][0] = -1;
	input_chip[2][1] = 1;
	input_chip[2][2] = -1;
	input_chip[2][3] = 1;
	input_chip[2][4] = 1;
	input_chip[2][5] = 1;
	input_chip[2][6] = -1;
	input_chip[2][7] = -1;

	input_chip[3][0] = -1;
	input_chip[3][1] = 1;
	input_chip[3][2] = -1;
	input_chip[3][3] = -1;
	input_chip[3][4] = -1;
	input_chip[3][5] = -1;
	input_chip[3][6] = 1;
	input_chip[3][7] = -1;

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