#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<conio.h>
#include <locale>
#include <Windows.h>
#include<iomanip>
#define normal "\033[0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
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
		cout <<white<< "\t\t|" << setw(minusLengthPress - menuNumber.length()) << menuNumber << setw(minusLengthPress - menuNumber.length() - 5) << "|";
		cout << "\|" << setw(minusLengthMenu - menuNumber.length() + 7) << menuText << setw(minusLengthMenu - menuNumber.length() - 5) << "|";
		cout << endl << "\t\t" << normal;
	}
	else
	{
		cout << "|" << setw(minusLengthPress - menuNumber.length()) << menuNumber << setw(minusLengthPress - menuNumber.length()) << "|";
		cout << "|" << setw(minusLengthMenu - menuNumber.length() + 7) << menuText << setw(minusLengthMenu - menuNumber.length() - 12) << "|";
		cout << endl << "\t\t";
	}
	for (int i = 0; i < minusLengthMenu * 3 - (minusLengthMenu / 1.1); i++)
	{
		cout << "-";
	}
	cout << endl << "\t\t";
}
void delay(int *a) {
	for (int i = 0; i < 210000; i++) { for (int j = 1; j < 900; j++) { a++; } }
}
void logo() {
	cout << yellow <<
		R"(
                       _   _     _     _____   ____      _    
                      | \ | |   / \   |  __ \ |  _ \    / \   
                      |  \| |  / _ \  | |  \ || |_) |  / _ \  
                      | |\  | / ___ \ | |__/ ||  _ <  / ___ \ 
                      |_| \_|/_/   \_\|_____/ |_| \_\/_/   \_\
        )" << endl << normal;
}


struct node {
	int value;
	node* link;
};
struct Queue {
	node *front, *rear;
	int counter;
};
void enQueue(Queue *queue, int value) {
	node *temp = new node;
	temp->value = value;
	if (queue->front == NULL)
		queue->front = temp;
	else
		queue->rear->link = temp;
	queue->rear = temp;
	queue->rear->link = queue->front;
}
string checkCounter(string token) {
	int i = 0;
	string Return;
	while (1) {
		Return = token[i];
		i++;
		if (token[i] == '\0')
			break;
	}
	return Return;
}
int checkTokenNumber(string token) {
	int i = 0; int j = 0;
	char Return[20] = "";
	while (1) {
		i++;
		if (token[i] == '\0') {
			i--;
			break;
		}
	}
	for (j = 0; j < i; j++)
		Return[j] = token[j];
	Return[j] = '\0';
	int a;
	a = atoi(Return);
	return a;
}

class person {
public:
	string Fname, Lname, gender, address, ID;
	int D, M, Y, age, dose;
	person *left, *right;
	void getData() {
		system("cls");
		cout <<white<< "\n\t\t\t\t\tFirst-Name: "<<yellow;
		cin >> Fname;
		cout <<white<< "\t\t\t\t\tLast-Name: "<<yellow;
		cin >> Lname;
	loop:
		cout << white << "\t\t\t\t\tDate of Birth:" << white << " \n\t\t\t\t\t\tDay: " << yellow;
		cin >> D;
		cout <<white<< "\t\t\t\t\t\tMonth: "<<yellow;
		cin >> M;
		cout <<white<< "\t\t\t\t\t\tYear: "<<yellow;
		cin >> Y;
		age = 2022 - Y;
		if (age < 0) {
			cout << red << "\t\t\t\t\tOnly positives number allowed!!\n";
			goto loop;
		}
		if (age > 100) {
			cout << red << "\t\t\t\t\tYou are DEAD BRO!!!!!!\n";
			goto loop;
		}
		char g;
	loop1:
		cout << white << "\t\t\t\t\tGender of " << yellow << Fname << white << " (M/F): " << yellow;
		cin >> g;
		if (g == 'm' || g == 'M')
			gender = "Male";
		else if (g == 'f' || g == 'F')
			gender = "Female";
		else {
			cout << red << "\n\t\t\t\t\tWrong Detail!!\n";
			goto loop1;
		}
	loop2:
		cout << white << "\n\t\t\t\t\tVaccine Dose Taken: " << yellow;
		cin >> dose;
		if (!(dose >= 0 && dose <= 2)) {
			cout <<red<< "\n\t\t\t\t\tWrong Detail!!\n";
			goto loop2;
		}
		cout << white << "\n\t\t\t\t\tAddress: " << yellow;
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
			cout << green << "\n\t\t\t\t\tFirst person added to the family!\n" << normal;
			root = temp;
		}
		else {
		again:
			cout << normal << "\t\t\t\t\tEnter Name of Person \"" << yellow << temp->Fname << normal << "\" is related to: " << blue;
			cin >> personChild;
			cout << "\t\t\t\t\t" << yellow << personChild << normal << " is Male?(Y/N): " << green;
			cin >> gen;
			cout << normal;
			if (search(root, personChild, (gen == "y" || gen == "Y" ? "M" : "F"))) {
				int opt;
				cout << blue << "\n\t\t\t\t\tWhat is the family relation?\n" << normal
					<< "\t\t\t\t\t1: If " << yellow << temp->Fname << normal << " is " << cyan << "Mother" << normal << " of " << yellow << personChild
					<< normal << "\n\t\t\t\t\t2: If " << yellow << temp->Fname << normal << " is " << cyan << "Father" << normal << " of " << yellow << personChild
					<< normal << "\n\t\t\t\t\tEnter: " << green;
			loop1:
				cin >> opt;
				cout << normal;
				if (opt < 1 || opt > 2) {
					cout << red << "\n\t\t\t\t\tOnly a number of 1 or 2 is accepted!\n"
						<< normal << "\t\t\t\t\tEnter: " << green;
					goto loop1;
				}
				switch (opt) {
				case 1:
					addMother(search(root, personChild, gen), temp);
					cout << "\t\t\t\t\t" << cyan << temp->Fname << yellow << " is added as Mother!\n" << normal;
					break;
				case 2:
					addFather(search(root, personChild, gen), temp);
					cout << "\t\t\t\t\t" << cyan << temp->Fname << yellow << " is added as Father!\n" << normal;
					break;
				default:
					cout << red << "\t\t\t\t\tError!!\n" << normal;
					system("pause");
				}
			}
			else {
				char ch;
				cout <<red<< "\n\t\t\t\t\tData Not Found!!"<<normal<<"\n\t\t\t\t\tDo you want to Try Again (Y/N): "<<green;
				cin >> ch;
				cout << normal;
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
	void addFather(person *a, person *b) {
		if (a->right == NULL)
			a->right = b;
		else
			addFather(a->right, b);
	}

	void show(person *ptr) {
		cout << yellow << "\n\t\t\t\t\tName: " << cyan << ptr->Fname + " " + ptr->Lname;
		cout << yellow << "\n\t\t\t\t\tAge: " << cyan << ptr->age;
		cout << yellow << "\n\t\t\t\t\tGender: " << cyan << ptr->gender;
		cout << yellow << "\n\t\t\t\t\tCNIC: " << cyan << ptr->ID;
		if (ptr->right == NULL) {
			cout << red << "\n\n\t\t\t\t\tFather Data: N/A\n" << normal;
		}
		else {
			cout << yellow << "\n\n\t\t\t\t\tFather Name: " << cyan << ptr->right->Fname + " " + ptr->right->Lname;
			cout << yellow << "\n\t\t\t\t\tFather Age: " << cyan << ptr->right->age;
			cout << yellow << "\n\t\t\t\t\tFather CNIC: " << cyan << ptr->right->ID;
		}
		if (ptr->left == NULL) {
			cout << red << "\n\n\t\t\t\t\tMother Data: N/A\n" << normal;
		}
		else {
			cout << yellow << "\n\n\t\t\t\t\tMother Name: " << cyan << ptr->left->Fname + " " + ptr->left->Lname;
			cout << yellow << "\n\t\t\t\t\tMother age: " << cyan << ptr->left->age;
			cout << yellow << "\n\t\t\t\t\tMother CNIC: " << cyan << ptr->left->ID;
		}
	}

	void card(person *ptr) {
		if (ptr->right == NULL) {
			cout << red << "\n\t\t\t\t\tFather Data Not Found!!\n" << normal;
			system("pause");
			system("cls");
		}
		else {
			string country = "Pakistan";
			int idate = 1, imonth = 5, iyear = 2023;
			int a = 0;
			system("cls");
			delay(&a);			cout <<green<< "\t\t\t\t\t****************************************" << endl;
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
			delay(&a);			cout << "\t\t\t\t\t****************************************\n\n\n\n\n\n" << normal;
		}
	}

	void Ccertificate(person *p) {
		system("cls");
		cout << blue << "\t\t\t\t\tMINISTRY OF NATIONAL HEALTH SERVICES REGULATIONS AND CORDINATION" << endl;
		cout << "\t\t\t\t\tIMMUNIZATION CERTIFICATE FOR COVID-19" << endl;
		cout << "\t\t\t\t\tName: " << p->Fname << " " << p->Lname << endl;
		cout << "\t\t\t\t\tDate of Birth: " << p->D << "-" << p->M << "-" << p->Y << endl;
		cout << "\t\t\t\t\tIdentity No: " << p->ID;
		cout << "\n\t\t\t\t\tHas been administrated COVID-19 following vaccination:" << endl;
		cout << "\t\t\t\t\tDoses:" << p->dose << endl;
		if (p->dose == 1)
			cout <<yellow<< "\t\t\t\t\tPartially_Vaccinated!\n" << normal;
		else if (p->dose == 2)
			cout <<green<< "\t\t\t\t\tFull_Vaccinated.\n" << normal;
		else
			cout <<red<< "\t\t\t\t\tNot_Vaccinated!!!\n" << normal;
	}

	void printInOrder(person *person, int space) {
		auto count = 7;
		cout << white;
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
			cout << red << "No tree exist!\n";
		cout << normal;
	}

	void saveData(person *person) {
		if (person != NULL) {
			addToFile(person);
			if (person->right != NULL)
				saveData(person->right);
			if (person->left != NULL)
				saveData(person->left);
		}
		else
			cout << red << "No Data Exist!\n";
	}
	void addToFile(person *temp)
	{
		ofstream myFile;
		myFile.open("Record.txt", ios::app);

		myFile << "\t\t\tName: " << temp->Fname + " " + temp->Lname + "\n";
		myFile << "\t\t\tAge: " << to_string(temp->age) + "\n";
		myFile << "\t\t\tGender: " << temp->gender + "\n";
		myFile << "\t\t\tCNIC: " << temp->ID + "\n";
		myFile << "\t\t\tAddress: " << temp->address + "\n";
		myFile << "\t\t\tDOB: " << to_string(temp->D) + "-";
		myFile << to_string(temp->M) + "-";
		myFile << to_string(temp->Y) + "\n";
		myFile << "\t\t\tVaccine Dose: " << to_string(temp->dose) + "\n";
		if (temp->right == NULL) {
			myFile << "\n\n\t\t\tFather Data: N/A\n";
		}
		else {
			myFile << "\n\n\t\t\tFather Name: " << temp->right->Fname + " " + temp->right->Lname;
			myFile << "\n\t\t\tFather Age: " << temp->right->age;
			myFile << "\n\t\t\tFather CNIC: " << temp->right->ID << endl;
		}
		if (temp->left == NULL) {
			myFile << "\n\n\t\t\tMother Data: N/A\n";
		}
		else {
			myFile << "\n\n\t\t\tMother Name: " << temp->left->Fname + " " + temp->left->Lname;
			myFile << "\n\t\t\tMother age: " << temp->left->age;
			myFile << "\n\t\t\tMother CNIC: " << temp->left->ID << endl;
		}
		myFile << "*-------------------------------------------------------------*\n";

		myFile.close();
	}
	void readFromFile() {
		cout << cyan;
		string myText;
		ifstream MyFile("Record.txt");
		cout << cyan;
		while (getline(MyFile, myText))
		{
			cout << myText << "\n";
		}
		cout << endl << normal;
		MyFile.close();
		cout << normal;
	}
};

void Menu() {
	menuStyle(true, "Press", "Main Menu");
	menuStyle(false, "1", "Add new person");
	menuStyle(false, "2", "Show information of a person.");
	menuStyle(false, "3", "Print complete family-tree.");
	menuStyle(false, "4", "Show Card View.");
	menuStyle(false, "5", "Show Corona Certificate.");
	menuStyle(false, "6", "Show All Data.");
	menuStyle(false, "0", "Quit.");
	cout << "\n\t\tYour choice: ";
}

int main() {
	familyTree fT;
	string option;
	string str, g;
	int tokencounterA = 0;
	auto *queueA = new Queue; queueA->front = queueA->rear = NULL; queueA->counter = 1;
	system("cls");
	login();
menu:
	tokencounterA++;
	system("cls");
	cout << "\n\t\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t\t\tToken Number : " << tokencounterA << "A " << endl;
	cout << "\t\t\t\t\t---------------------------------" << endl;
	enQueue(queueA, tokencounterA);
	cout << "\t\t\t\t\t      ---------------------" << endl;
	cout << "\t\t\t\t\t      | Counter Number : A |" << endl;
	cout << "\t\t\t\t\t      ---------------------\n\t\t\t\t\t";
	system("pause");
	system("cls");
	logo();
	string token;
countermenu:
	cout << "\t\t\t\tEnter Token Number: ";
	cin >> token;
	while (true) {
	main:
		system("cls"); 
		string counter = checkCounter(token);
		int tokenNumber = checkTokenNumber(token);
		if (counter == "A" || counter == "a")
		{
			system("cls");
			logo();
			cout << "\t\t\t************************************" << endl;
			cout << "\t\t\t|       Welcome To Counter A       |" << endl;
			cout << "\t\t\t************************************" << endl;
			cout << "\t\t\t\tCurrent Number is : " << queueA->counter << "A" << endl;
			cout << "\t\t ---------------------------------------------------" << endl;
			if (tokenNumber > queueA->counter)
			{
				cout << "\t\t\t\t\tPlease wait For your Turn." << endl;
				system("pause");
				system("cls");
				goto countermenu;

			}
			else if (tokenNumber < queueA->counter)
			{
				cout << "\t\t\t\t\tToken Already Used -- Please Get a New Token Number." << endl;
				system("pause");
				system("cls");
				goto menu;
			}
		}
		else {
			cout << "\t\t\t\t\tInvalid Token Number! Please Try Again." << endl;
			system("pause");
			system("cls");
			goto menu;
		}
		Menu();
		cout << blue;
		cin >> option;
		cout << normal;
		switch (option[0])
		{
			cin.ignore();
		case '1':
			fT.addNewPerson();
			cout << "\t\t\t\t\t";
			system("pause");
			break;
		case '2':
			system("cls");
			cout << "\t\t\t\t\tEnter name of person to show information: " << yellow;
			cin >> str;
			cout << "\t\t\t\t\t" << str << normal << " is Male?(Y/N): " << green;
			cin >> g;
			cout << normal;
			if (fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F"))) {
				fT.show(fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F")));
				fT.addToFile(fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F")));
			}
			else
				cout << red << "\n\t\t\t\t\tData Not Found!!\n" << normal;
			system("pause");
			break;
		case '3':
			system("cls"); 
			cout << "\n\n\n\n\n\t";
			fT.printInOrder(fT.root, 0);
			cout << "\n\n\n\n\n\n\n\n\n\n";
			system("pause");
			break;
		case '4':
			system("cls");
			cout << "\t\t\t\t\tEnter name of person to view card: "<<yellow;
			cin >> str;
			cout << "\t\t\t\t\t" << str << normal << " is Male?(Y/N): " << green;
			cin >> g;
			cout << normal;
			if (fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F"))) {
				fT.card(fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F")));
			}
			else
				cout << red << "\n\t\t\t\t\tData Not Found!!\n" << normal;
			system("pause");
			break;
		case '5':
			system("cls");
			cout << "\t\t\t\t\tEnter name of person to view Certificate: "<<yellow;
			cin >> str;
			cout << "\t\t\t\t\t" << str << normal << " is Male?(Y/N): " << green;
			cin >> g;
			cout << normal;
			if (fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F"))) {
				fT.Ccertificate(fT.search(fT.root, str, (g == "y" || g == "Y" ? "M" : "F")));
			}
			else
				cout << red << "\n\t\t\t\t\tData Not Found!!\n" << normal;
			system("pause");
			break;
		case '6':
			system("cls");
			fT.readFromFile();
			system("pause");
			break;
		case '0':
			fT.saveData(fT.root);
			exit(0);
		default:
			cout << red << "\n\t\t\t\t\tWrong Choice!!\n" << normal;
			system("pause");
			goto main;
		}
	}
}

void login() {
	string pass;
	char ch;
	int i = 0;
	cout << yellow << "\n\t\t\t\t\t   ---------- User Login -------\n\n" << white
		<< "\t\t\t\t\t\t    User name : User\n"
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
			cout <<red<< "\n\t\t\t\t\tToo Many Tries!!\n";
			exit(1);
		}
	}
}