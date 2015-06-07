#include <iostream>
#include <algorithm>
#include "BankAccount.h"
using namespace std;

int main(int argc, char * argv[]) 
{
	Bank a("Kristian Karadjov", "13355912", "95113124", 3000, true);
	a += 200;
	cout << "Balance: " << a.getBalance()<<endl;
	a.drawFromBalance(22);
	cout << "Balance: " << a.getBalance() << endl;;
	cout << a << endl;
	a.frozeBankAccount();
	
	Bank arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	arr[1].AddRandomSum();
	sort(arr, arr + 5);
	cout << endl;
	cout << "Sorted bank accounts by balance : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}