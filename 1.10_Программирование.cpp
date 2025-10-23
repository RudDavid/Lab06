/****************************
 * Автор:       Руднев Д.А. *
 * Дата:        23.10.2025  *
 * Название:    Вариант 11  *
 * **************************/

#include <iostream>
#include <fstream> 
#include <string> 

using namespace std;

struct organization {
  string divisionName;
  string configuration;
  int countOfComputers;
  int yearOfPurchase;
};

int main() {
ifstream inputFile("1.10_Программирование.txt");  

  int countIndex;
  organization variable[99];
  string line; 
  int currentLine = 1;
  int sum = 0;
  int borderOfCountIndex = 3;
  int borderOfCountIndex2 = 2;
  int minimum = 2500;

  cout << "Count" << endl;
  cin >> countIndex;

  if (inputFile.is_open() == 0) {
    cout << "Error of Open" << endl;
  }
  else {
    while (getline(inputFile, line)) {
      if (currentLine == countIndex) {
        inputFile >> variable[countIndex].divisionName
          >> variable[countIndex].configuration
          >> variable[countIndex].countOfComputers
          >> variable[countIndex].yearOfPurchase;

        cout << variable[countIndex].divisionName << " "
          << variable[countIndex].configuration << " "
          << variable[countIndex].countOfComputers << " "
          << variable[countIndex].yearOfPurchase << endl;
      
        sum += variable[countIndex].countOfComputers;
        if (countIndex == currentLine or countIndex == borderOfCountIndex == borderOfCountIndex2) {
          cout << "Count of all computers: " << sum << endl;
        }
        if (minimum > variable[countIndex].yearOfPurchase) {
          minimum = variable[countIndex].yearOfPurchase;
          if (countIndex == currentLine or countIndex == borderOfCountIndex == borderOfCountIndex2) {
            cout << "Oldest computers: " << minimum << endl;
          }
        }
        
        
        break;

      }
      currentLine++;
      
      inputFile >> variable[countIndex].divisionName
        >> variable[countIndex].configuration
        >> variable[countIndex].countOfComputers
        >> variable[countIndex].yearOfPurchase;

      sum += variable[countIndex].countOfComputers;
      if (minimum > variable[countIndex].yearOfPurchase) {
        minimum = variable[countIndex].yearOfPurchase;
      }

      }
    }
    
 

  inputFile.close(); 

  return 0;
}