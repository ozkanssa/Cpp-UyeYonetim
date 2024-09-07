#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

void menuHead(string menuHeadText) {
	cout << "##################" << endl << endl;
	cout << "    " << menuHeadText << endl << endl;
	cout << "##################" << endl << endl;
}

int mainMenuChoice;
void mainMenu() {
	cout << "[1] Uye Ekle" << endl;
	cout << "[2] Uye Listesi" << endl << endl;
	cout << "> ";
	cin >> mainMenuChoice;
	system("cls");
}

ofstream users;
string firstName, secondName, birthDate, phoneNumber;
void addUser() {
	MessageBox(NULL, L"Lutfen turkce karakter ve bosluk kullanmayin.", L"Bilgi", MB_ICONINFORMATION);
	menuHead("Uye Ekle");
	cout << "Ad: ";
	cin >> firstName;
	cout << "Soyad: ";
	cin >> secondName;
	cout << "Dogum Tarihi: ";
	cin >> birthDate;
	cout << "Telefon Numarasi: 0";
	cin >> phoneNumber;

	users.open("Uyeler.txt", ios::app);
	users << firstName << " " << secondName << " | " << birthDate << " | 0" << phoneNumber << endl;
	users.close();

	MessageBox(NULL, L"Uye kayit edildi.", L"Bilgi", MB_ICONINFORMATION);
	system("cls");
}

ifstream readAndListUsers("Uyeler.txt");
string line = ""; string exitListUsers;
void listUsers() {
	menuHead("Uye Listele");
	
	cout << "" << endl;
	cout << "FORMAT: AD | SOYAD | DOGUM TARIHI | TELEFON NUMARASI" << endl;
	cout << "" << endl << endl;

	if (readAndListUsers.is_open()) {
		while (getline(readAndListUsers, line)) {
			cout << line << endl;
		}
	}
	
	else {
		MessageBox(NULL, L"Dosyaya erisilirken hata meydana geldi!", L"Hata", MB_ICONERROR);
		exit(-1);
	}

	readAndListUsers.close();

	cout << "" << endl;
	cout << "Cikis yapmak icin herhangi rakam veya harf girin: ";
	cin >> exitListUsers;

	if (exitListUsers == "NULL") {
		exit(1);
	}

	else {
		exit(1);
	}
}

int main() {
	menuHead("Ana Menu");
	mainMenu();

	if (mainMenuChoice == 1) {
		addUser();
		main();
	}

	else if (mainMenuChoice == 2) {
		listUsers();
		main();
	}

	else {
		exit(-1);
	}

	return 0;
}