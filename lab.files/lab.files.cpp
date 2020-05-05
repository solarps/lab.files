#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<sstream>
std::ofstream fout;
std::ifstream fin;
using namespace std;

struct name {
	char F[56];
	char I[32];
	char O[32];
	void setFullname() {
		cout << "F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(F, 56);

		cout << endl << "I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(I, 32);

		cin.ignore(std::cin.rdbuf()->in_avail());
		cout << endl << "o: ";
		cin.getline(O, 32);
	}
	void showFullname() {
		fout << "FIO: " << F << " " << I << " " << O << endl;
	}
};
struct adress {
	int index;
	char country[30];
	char region[30];
	char district[30];
	char city[20];
	char street[50];
	int house;
	int apartment;
	void setFulladress() {
		cout << endl << "Index:";
		while (!(cin >> index))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		cout << endl << "Country:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(country, 30);

		cout << endl << "Region:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(region, 30);

		cout << endl << "District:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(district, 30);

		cout << endl << "City:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(city, 20);

		cout << endl << "House:";
		while (!(cin >> house))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		cout << endl << "Apartment:";
		while (!(cin >> apartment))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}
	void showFulladress() {
		fout << "Index:" << index << endl;
		fout << "Country:" << country << endl;
		fout << "Region:" << region << endl;
		fout << "District:" << district << endl;
		fout << "City:" << city << endl;
		fout << "House:" << house << endl;
		fout << "Apartment:" << apartment << endl;
	}
};
struct owner {
	name person;
	long tele;
	adress home;
	char CarBrand[20];
	int NumCar;
	int NumTeh;
	void setFullInfo() {
		person.setFullname();

		cout << endl << "Telephon number:";
		while (!(cin >> tele))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		home.setFulladress();

		cout << endl << "Car brand:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(CarBrand, 30);

		cout << endl << "Car number:";
		while (!(cin >> NumCar))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		cout << endl << "Teh. passport number:";
		while (!(cin >> NumTeh))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

	}
	void outFullInfo() {
		person.showFullname();

		fout << "Telephon number:" << tele << endl;

		home.showFulladress();

		fout << "Car brand:" << CarBrand << endl;
		fout << "Car number:" << NumCar << endl;
		fout << "Teh. passport number:" << NumTeh << endl << endl;
	}
};
void InitOfArray(owner* array, int* size)
{
	for (size_t i = 0; i < *size; i++)
	{
		(array + i)->setFullInfo();
	}
}

void showArray(owner* array, int* size)
{
	for (size_t i = 0; i < *size; i++)
	{
		(array + i)->outFullInfo();
	}
}

void showVazOwner(owner* array, int* size) 
{
	for (int i = 0; i < *size; i++)
	{
		if (_strcmpi((array + i)->CarBrand, "Vaz") == 0)
		{
			(array + i)->outFullInfo();
		}
	}
}

void firstlvl() 
{

	fout.open("D:\\Vaz owners.txt"); // окрываем файл для записи
	int size;
	int number;
	int YesOrNot = 0;
	cout << "Enter size of array" << endl;
	while (!(cin >> size))
	{
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(65535, '\n');
	}
	int* ptrsize = &size;
	owner* array = new owner[size];

	InitOfArray(array, ptrsize);

	fout << "Vaz owners: " << endl;
	showVazOwner(array, ptrsize);
}

void secondlvl() 
{
	fout.open("D:\\Numbers.txt");
	double* num = new double[10];
	for (int i = 0; i < 10; i++)
	{
		double n = rand() % 100 - 50;
		if (n / 2 == 0) {
			num[i] = 1.0 + (double)(n / 10);
		}
		else {
			num[i] = (double)(n / 10);
		}
		fout << num[i] << "\t";
	}
	fout << endl;
	double sum = 0,proiz = 1;
	for (int i = 0; i < 10; i++) 
	{
		sum += num[i];
		proiz *= num[i];
	}
	sum = abs(sum);
	proiz = pow(proiz, 2);
	fout << "Modul : " << sum << endl;
	fout << "Сomposition : " << proiz << endl;
	fout.close();
}
int k = 2 + rand() % 5;
int m = 1 + rand() % 5;
int n = 1 + rand() % 5;
void randMatrix()
{
	fout.open("D:\\Matrix.csv");
	for (int i = 0; i < k; i++)
	{
		fout << "Matrix: " << i + 1 << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fout << rand() % 10 << ",";
			}
			fout << endl;
		}
	}
	fout.close();
}


void thirdlvl() 
{
	string line;
	int counterx=0;
	int countery = 0;
	fin.open("D:\\Matrix.csv");
	getline(fin, line); 


	int rows = 0;
	int cols = 0;
	if (fin.is_open())
	{
		
		while (getline(fin, line))
		{
			counterx = 0;
			if (isdigit(line[0])) 
			{
				for ( int i = 0; i < strlen(&line[0]); i++)
				{
					
					if (line[i] == ',')
					{
						counterx++;
					}
				}
				cols = 0;
				rows++;
				countery++;
			}else countery = 0;
			/*cout << counterx << endl;
			cout << countery << endl;*/
			//cout << endl;
		}
	}
	fin.close();
	fin.open("D:\\Matrix.csv");
	int i=0;
	int*** arr = new int** [k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = new int* [countery];
		for (int j = 0; j < countery; j++)
		{
			arr[i][j] = new int[counterx];
		}
	}
	for (int matrix = 0; matrix < k; matrix++)
	{
		cout << "Matrix" << matrix + 1 << endl;
		for (int rows = 0; rows < countery; rows++)
		{
			do
			{
				getline(fin, line);
			} while (!isdigit(line[0]));
			i = 0;
			for (int cols = 0; cols < counterx; cols++)
			{
				if (isdigit(line[i]))
				{
					arr[matrix][rows][cols] =(int)(line[i]-'0');
				}
				i += 2;
				cout << arr[matrix][rows][cols]<<"\t";
			}
			cout << endl;
		}
	}
	int* sum = new int[k];
	for (int i = 0; i < k; i++)
	{
		sum[i] = 0;
	}
	for (int matrix = 0; matrix < k; matrix++)
	{
		for (int rows = 0; rows < countery; rows++)
		{
			for (int cols = 0; cols < counterx; cols++)
			{
				if (arr[matrix][rows][cols] % 2 == 0) {
					sum[matrix] += arr[matrix][rows][cols];
				}
			}
		}
	}
	fin.close();
	fout.open("D:\\EditedMatrix.csv");
	for (int matrix = 0; matrix < k; matrix++)
	{
		if (sum[matrix] % 2 == 0)
		{
			fout << "Matrix:" << matrix + 1 << endl;
			for (int rows = 0; rows < countery; rows++)
			{
				for (int cols = 0; cols < counterx; cols++)
				{
					fout << arr[matrix][rows][cols] << ",";
				}
				fout << endl;
			}
		}
	}
	fout.close();
	fout.open("D:\\Matrix.csv");
	for (int matrix = 0; matrix < k; matrix++)
	{
		if (sum[matrix] % 2 == 0) 
		{
			fout << "Matrix:" << matrix + 1 << endl;
			for (int rows = 0; rows < countery; rows++)
			{
				for (int cols = 0; cols < counterx; cols++)
				{
					fout << "1,";
				}
				fout << endl;
			}
		}
	}
	fout.close();
}
int main()
{
	srand(time(0));
	//firstlvl();
	//secondlvl();
	randMatrix();
	thirdlvl();
}