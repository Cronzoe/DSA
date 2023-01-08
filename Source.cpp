#include<iostream>
#include<string>
#include<time.h>
#include<conio.h>
#include<iomanip>
#define normal "\033[0m"
#define black "\033[1;30m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
#define purple "\033[1;35m"
#define cyan "\033[1;36m"
#define white "\033[1;37m"
using namespace std;

int max_record = 3;
int tries = 0;
void login();
void menuStyle(bool isTitle, string menuNumber, string menuText)
{
	int minusLengthPress = 5;
	int minusLengthMenu = 25;

	if (isTitle)
	{
		minusLengthPress = 12;
		cout << "|" << setw(minusLengthPress - menuNumber.length()) << menuNumber << setw(minusLengthPress - menuNumber.length() - 5) << "|";
		cout << "|" << setw(minusLengthMenu - menuNumber.length() + 7) << menuText << setw(minusLengthMenu - menuNumber.length() - 5) << "|";
		cout << endl;
	}
	else
	{
		cout << "|" << setw(minusLengthPress - menuNumber.length()) << menuNumber << setw(minusLengthPress - menuNumber.length()) << "|";
		cout << "|" << setw(minusLengthMenu - menuNumber.length() + 7) << menuText << setw(minusLengthMenu - menuNumber.length() - 12) << "|";
		cout << endl;
	}
	for (int i = 0; i < minusLengthMenu * 3 - (minusLengthMenu / 1.1); i++)
	{
		cout << "-";
	}
	cout << endl;
}
void delay(int *a) {
	for (int i = 0; i < 210000; i++) { for (int j = 1; j < 900; j++) { a++; } }
}

class person {
public:
	string Fname, Lname, gender, address, ID;
	int D, M, Y, age, dose;
	person *left, *right;
	person*bro, *sis;
	void getData() {
		cout << "\nFirstname of the person: ";
		cin >> Fname;
		cout << "Lastname of the person: ";
		cin >> Lname;
	loop:
		cout << "Date of Birth: \n\tDay: ";
		cin >> D;
		cout << "\tMonth: ";
		cin >> M;
		cout << "\tYear: ";
		cin >> Y;
		age = 2022 - Y;
		if (age < 0) {
			cout << "Only positives number allowed!!\n";
			goto loop;
		}
		if (age > 100) {
			cout << "You are DEAD BRO!!!!!!\n";
			goto loop;
		}
		char g;
	loop1:
		cout << "What is the gender of " << Fname << " (M/F): ";
		cin >> g;
		if (g == 'm' || g == 'M')
			gender = "Male";
		else if (g == 'f' || g == 'F')
			gender = "Female";
		else {
			cout << "\nWrong Detail!!\n";
			goto loop1;
		}
	loop2:
		cout << "\nVaccine Dose Taken: ";
		cin >> dose;
		if (!(dose >= 0 && dose <= 2)) {
			cout << "\nWrong Detail!!\n";
			goto loop2;
		}
		cout << "\nAddress of the person: ";
		getline(cin >> ws, address);
		int I[13] = { 6,1,1,0,1,1,5,2,2,1 };
		srand(time(0));
		for (int i = 9; i < 13; i++)
			I[i] = rand() % 9;
		for (int i = 0; i < 13; i++) {
			ID.push_back(I[i]+48);
			if (i == 4 || i == 11)
				ID.push_back('-');
		}
	}
};

class familyTree {
public:
	person *root;
	familyTree() {
		root = NULL;
	}

	person *search(person *temp, string per, string g) {
		if (temp == NULL || temp->Fname == per)
			return temp;
		if (temp->Fname != per && (g == "m" || g == "M" || g == "Male" || g == "male"))
			return search(temp->right, per, g);
		else
			return search(temp->left, per, g);
	}

	void addNewPerson() {
		auto temp = new person();
		temp->getData();

		string personChild, gen;
		if (root == NULL) {
			cout << "\nFirst person added to the family!\n";
			root = temp;
		}
		else {
		again:
			cout << "Enter the name of the person \"" << temp->Fname << "\" is the parent to: ";
			cin >> personChild;
			cout << "Enter the Gender of the person \"" << temp->Fname << "\" is the parent to: ";
			cin >> gen;

			if (search(root, personChild, gen)) {
				int opt;
				cout << "\nWhat is the family relation?\n"
					<< "(1) if " << temp->Fname << " is the Mother to " << personChild
					<< "\n(2) if " << temp->Fname << " is the Father to " << personChild
					<< "\n(3) if " << temp->Fname << " is the brother to " << personChild
					<< "\n(4) if " << temp->Fname << " is the sister to " << personChild
					<< "\nEnter: ";
			loop1:
				cin >> opt;
				if (opt < 1 || opt > 4) {
					cout << "\nOnly a number of 1 or 2 is accepted!\n"
						<< "Enter: ";
					goto loop1;
				}
				switch (opt) {
				case 1:
					addMother(search(root, personChild, gen), temp);
					cout << temp->Fname << " is now added as the mother!\n";
					break;
				case 2:
					addFather(search(root, personChild, gen), temp);
					cout << temp->Fname << " is now added as the father!\n";
					break;
				case 3:
					addBrother(search(root, personChild, gen), temp);
					cout << temp->Fname << " is now added as the brother!\n";
					break;
				case 4:
					addSister(search(root, personChild, gen), temp);
					cout << temp->Fname << " is now added as the sister!\n";
					break;
				default:
					cout << "Error!!\n";
					system("pause");
					exit(1);
				}
			}
			else {
				char ch;
				cout << "\nData Not Found!!\nDo you want to Try Again (Y/N): ";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
					goto again;
				else {}
			}
		}
	}
	void addMother(person *a, person *b) {
		if (a->left == NULL)
			a->left = b;
		else
			addMother(a->left, b);
	}
	void addSister(person *a, person *b) {
		if (a->sis == NULL)
			a->sis = b;
		else
			addSister(a->sis, b);
	}
	void addFather(person *a, person *b) {
		if (a->right == NULL)
			a->right = b;
		else
			addFather(a->right, b);
	}
	void addBrother(person *a, person *b) {
		if (a->bro == NULL)
			a->bro = b;
		else
			addBrother(a->bro, b);
	}

	void show(person *ptr) {
		cout << "\nName: " << ptr->Fname + " " + ptr->Lname;
		cout << "\nAge: " << ptr->age;
		cout << "\nGender: " << ptr->gender;
		cout << "\nCNIC: " << ptr->ID;
		if (ptr->right == NULL) {
			cout << "\n\nFather Data: N/A";
		}
		else {
			cout << "\n\nFather Name: " << ptr->right->Fname + " " + ptr->right->Lname;
			cout << "\nFather Age: " << ptr->right->age;
			cout << "\nFather CNIC: " << ptr->right->ID;
		}
		if (ptr->left == NULL) {
			cout << "\n\nMother Data: N/A";
		}
		else {
			cout << "\n\nMother Name: " << ptr->left->Fname + " " + ptr->left->Lname;
			cout << "\nMother age: " << ptr->left->age;
			cout << "\nMother CNIC: " << ptr->left->ID;
		}
		if (ptr->bro == NULL) {
			cout << "\n\nBrother Data: N/A";
		}
		else {
			cout << "\n\nBrother Name: " << ptr->bro->Fname + " " + ptr->bro->Lname;
			cout << "\nBrother Age: " << ptr->bro->age;
			cout << "\nBrother CNIC: " << ptr->bro->ID;
		}
		if (ptr->sis == NULL) {
			cout << "\n\nSister Data: N/A\n";
		}
		else {
			cout << "\n\nSister Name: " << ptr->sis->Fname + " " + ptr->sis->Lname;
			cout << "\nSister age: " << ptr->sis->age;
			cout << "\nSister CNIC: " << ptr->sis->ID << endl;
		}
	}

	void card(person *ptr) {
		if (ptr->right == NULL) {
			cout << "\nFather Data Not Found!!\n";
			system("pause");
			system("cls");
		}
		else {
			string country = "Pakistan";
			int idate = 1, imonth = 5, iyear = 2023;
			int a = 0;
			system("cls");
			delay(&a);			cout << "\t\t\t\t\t****************************************" << endl;
			delay(&a);			cout << "\t\t\t\t\t******ISLAMIC REPUBLIC OF PAKISTAN******" << endl;
			delay(&a);			cout << "\t\t\t\t\t________________________________________" << endl;
			delay(&a);			cout << "\t\t\t\t\tName                                    " << endl;
			delay(&a);			cout << "\t\t\t\t\t    " << ptr->Fname << " " << ptr->Lname << endl;
			delay(&a);			cout << "\t\t\t\t\t________________________________________" << endl;
			delay(&a);			cout << "\t\t\t\t\tFather Name                             " << endl;
			delay(&a);			cout << "\t\t\t\t\t    " << ptr->right->Fname << " " << ptr->right->Lname << endl;
			delay(&a);			cout << "\t\t\t\t\t________________________________________" << endl;
			delay(&a);			cout << "\t\t\t\t\tGender       CNIC#            " << endl;
			delay(&a);			cout << "\t\t\t\t\t" << ptr->gender << "              \t|";
			delay(&a);			cout << ptr->ID << "               " << endl;
			delay(&a);			cout << "\t\t\t\t\t________________________________________" << endl;
			delay(&a);			cout << "\t\t\t\t\tIssue Date" << "    |" << "Expiry Date          " << endl;
			delay(&a);			cout << "\t\t\t\t\t    " << idate << "-" << imonth << "-" << iyear << "    \t|" << idate << "-" << imonth << "-" << iyear + 10 << endl;
			delay(&a);			cout << "\t\t\t\t\t________________________________________" << endl;
			delay(&a);			cout << "\t\t\t\t\tAddress\n\t";
			delay(&a);			cout << "\t\t\t\t\t" << ptr->address << endl;
			delay(&a);			cout << "\t\t\t\t\t****************************************\n\n\n\n\n\n";
		}
	}

	void Ccertificate(person *p) {
		system("cls");
		cout << "MINISTRY OF NATIONAL HEALTH SERVICES REGULATIONS AND CORDINATION" << endl;
		cout << "IMMUNIZATION CERTIFICATE FOR COVID-19" << endl;
		cout << "Name: " << p->Fname << " " << p->Lname << endl;
		cout << "Date of Birth: " << p->D << "-" << p->M << "-" << p->Y << endl;
		cout << "Identity No: " << p->ID;
		cout << "\nHas been administrated COVID-19 following vaccination:" << endl;
		cout << "Doses:" << p->dose << endl;
		if (p->dose == 1)
			cout << "Partially_Vaccinated!" << endl;
		else if (p->dose == 2)
			cout << "Full_Vaccinated" << endl;
		else
			cout << "Not_Vaccinated" << endl;
	}

	void printInOrder(person *person, int space) {
		auto count = 7;
		space += count;
		if (person != NULL) {
			if (person->right != NULL)
				printInOrder(person->right, space);
			for (int i = count; i < space; i++)
				cout << " ";
			cout << person->Fname << "\n";
			if (person->left != NULL)
				printInOrder(person->left, space);
		}
		else
			cout << "No tree exist!\n";
	}
};

void Menu() {
	menuStyle(true, "Press", "Main Menu");
	menuStyle(false, "1", "Add new person");
	menuStyle(false, "2", "Show information of a person.");
	menuStyle(false, "3", "Print complete family-tree.");
	menuStyle(false, "4", "Show Card View.");
	menuStyle(false, "5", "Show Corona Certificate.");
	menuStyle(false, "0", "Quit.");
	cout << "\nYour choice: ";
}

int main() {
	familyTree fT;
	string option;
	string str, g;
	system("cls");
	login();
	while (true) {
	main:
		system("cls");
		Menu();
		cin >> option;

		switch (option[0])
		{
			cin.ignore();
		case '1':
			fT.addNewPerson();
			system("pause");
			break;
		case '2':
			cout << "Enter name of person to show information: ";
			cin >> str;
			cout << "Enter gender of person to show information: ";
			cin >> g;
			if (fT.search(fT.root, str, g)) {
				fT.show(fT.search(fT.root, str, g));
			}
			else
				cout << "\nData Not Found!!\n";
			system("pause");
			break;
		case '3':
			fT.printInOrder(fT.root, 0);
			system("pause");
			break;
		case '4':
			cout << "Enter name of person to view card: ";
			cin >> str;
			cout << "Enter gender of person to show information: ";
			cin >> g;
			if (fT.search(fT.root, str, g)) {
				fT.card(fT.search(fT.root, str, g));
			}
			else
				cout << "\nData Not Found!!\n";
			system("pause");
			break;
		case '5':
			cout << "Enter name of person to view Certificate: ";
			cin >> str;
			cout << "Enter gender of person to show information: ";
			cin >> g;
			if (fT.search(fT.root, str, g)) {
				fT.Ccertificate(fT.search(fT.root, str, g));
			}
			else
				cout << "\nData Not Found!!\n";
			system("pause");
			break;
		case '0':
			exit(0);
		default:
			cout << "\nWrong Choice!!\n";
			system("pause");
			goto main;
		}
	}
}

void login() {
	string pass;
	char ch;
	int i = 0;
	cout << yellow << "\n\t\t\t\t\t   ---------- Admin Login -------\n\n" << white
		<< "\t\t\t\t\t\t    User name : Admin\n"
		<< "\n\t\t\t\t\t       Enter your password(Hint:d_a) : ";
	cout << green;
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			pass[i] = '\0';
			break;
		}
		else if (ch == 8 && i > 0)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << "*";
			pass.push_back(ch);
			i++;
		}
	}
	cout << normal;
	if (pass == "dsa") {}
	else {
		cout << red << "\n\n\t\t\t\t\t\t     Access aborted...\n" << normal;
		tries++;
		if (tries < 3)
			return login();
		else {
			tries -= 3;
			cout << "\nToo Many Tries!!\n";
			exit(1);
		}
	}
}