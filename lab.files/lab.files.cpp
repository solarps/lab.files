#include<iostream>
#include<string.h>
#include<fstream>
#include<ctime>
std::ofstream fout;

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

void showVazOwner(owner* array, int* size) {
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
int main()
{
	srand(time(0));
	//firstlvl();
	secondlvl();
}