#include < iostream > 
#include < iomanip > 
#include < fstream >
using namespace std;
void printFile(); //prints out to a file
void table(char sign, short n, ostream & b); //prints out the table for file
void table(char sign, short n); //overloaded for printing to screen
short getValue(char sign, short i, short j); //gets the value for each table
short getTotal(short n); //finds the total number values
short getMax(char sign, short n); //finds the max of the value
short getTableSize(string operation); //finds the size of the operation table
char getUserInput(); //gets the input of the size of the table the user wants
int main() {
    cout << "\tWelcome to the Math table Program!!! \n";
    char input;
    string in ;
    short tableSize;
    bool isTrue = true;
    while (isTrue) {
      cout << "Print to screen or file?" << endl;
      cout << "1) Screen" << endl;
      cout << "2) File" << endl;
      cout << "3) Quit" << endl;
      input = getUserInput();
      switch (input) {
      case '1’:
      case 's’:
      case 'S’:
        while (isTrue) {
          cout << "Table Menu" << endl << endl;
          cout << "1) Addition table" << endl;
          cout << "2) Multiplication table" << endl;
          cout << "3) Subtraction table" << endl;
          cout << "4) Division table" << endl;
          cout << "5) Remainder table" << endl;
          cout << "6) Quit" << endl << endl;
          cout << "Choice: ";
          input = getUserInput();
          switch (input) {
          case '1’:
          case 'a’:
          case 'A’:
            tableSize = getTableSize("Addition");
            table(’+’, tableSize);
            break;
          case ’2’:
          case ’m’:
          case ’M’:
            tableSize = getTableSize("Multiplication");
            table(’ * ’, tableSize);
            break;
          case ’3’:
          case ’s’:
          case ’S’:
            tableSize = getTableSize("Subration");
            table(’-’, tableSize);
            break;
          case ’4’:
          case ’d’:
          case ’D’:
            tableSize = getTableSize("Division");
            table(’/’, tableSize);
              break;
            case ’5’:
            case ’r’:
            case ’R’:
              tableSize = getTableSize("Remainder"); table(’ % ’, tableSize);
              break;
            case ’6’:
            case ’q’:
            case ’Q’:
              cout << "Thank you for using MTP!!!" << endl; cout << "Aspire to have a propitious day!" << en dl;
              return 0;
            }
          }
        case ’2’:
        case ’f’:
        case ’F’:
          printFile();
          break;
        case ’3’:
        case ’q’:
        case ’Q’:
          cout << "See ya!" << endl;
          return 0;
        }
      }
      return 0;
    }
    void printFile() {
        ofstream output;
        string fname;
        char input;
        string in ;
        short tableSize;
        bool isTrue = true;
        while (isTrue) {
          cout << "What is the file name of the output: " << endl;

          typescript Sun Oct 29 20: 15: 42 2017 2
          cin >> fname;
          cout << "Table Menu" << endl << endl;
          cout << "1) Addition table" << endl;
          cout << "2) Multiplication table" << endl;
          cout << "3) Subtraction table" << endl;
          cout << "4) Division table" << endl;
          cout << "5) Remainder table" << endl;
          cout << "6) Quit" << endl << endl;
          cout << "Choice: ";
          input = getUserInput();
          output.open(fname.c_str());
          switch (input) {
          case ’1’:
          case ’a’:
          case ’A’:
            tableSize = getTableSize("Addition");
            table(’+’, tableSize, output);
            output.close();
            isTrue = false;
            break;
          case ’2’:
          case ’m’:
          case ’M’:
            tableSize = getTableSize("Multiplication");
            table(’ * ’, tableSize, output);
            output.close();
            isTrue = false;
            break;
          case ’3’:
          case ’s’:
          case ’S’:
            tableSize = getTableSize("Subration");
            table(’-’, tableSize, output);
            output.close();
            isTrue = false;
            break;
          case ’4’:
          case ’d’:
          case ’D’:
            tableSize = getTableSize("Division");
            table(’/’, tableSize, output);
              output.close(); isTrue = false;
              break;
            case ’5’:
            case ’r’:
            case ’R’:
              tableSize = getTableSize("Remainder"); table(’ % ’, tableSize, output); output.close(); isTrue = false;
              break;
            case ’6’:
            case ’q’:
            case ’Q’:
              cout << "Thank you for using MTP!!!" << endl; cout << "Aspire to have a propitious day!" << endl; output.close(); isTrue = false;
              break;
            }
          }

        }
        void table(char sign, short n, ostream & b) {
          short max = getMax(sign, n);
          b << setw(max) << sign << "|";
          for (int i = 1; i <= n; ++i)
            b << setw(max) << i;
          b << endl;
          for (int i = 0; i < max; ++i)
            b << "-";
          b << "+";
          for (int i = 0; i < n * max; ++i)
            b << "-";
          b << endl;
          for (int i = 1; i <= n; ++i) {
            b << setw(max) << i << "|";
            for (int j = 1; j <= n; ++j)
              b << setw(max) << getValue(sign, i, j);
            b << endl;
            b << endl;
          }
        }
        void table(char sign, short n) {
          short max = getMax(sign, n);
          cout << setw(max) << sign << "|";
          for (int i = 1; i <= n; ++i)
            cout << setw(max) << i;
          cout << endl;
          for (int i = 0; i < max; ++i)
            cout << "-";
          cout << "+";
          for (int i = 0; i < n * max; ++i)
            cout << "-";
          cout << endl;
          for (int i = 1; i <= n; ++i) {
            cout << setw(max) << i << "|";
            for (int j = 1; j <= n; ++j)
              cout << setw(max) << getValue(sign, i, j);
            cout << endl;
            cout << endl;
          }
        }
        short getValue(char sign, short i, short j) {
          switch (sign) {
          case ’+’:
            return i + j;
          case ’-’:
            return i - j;
          case ’*’:
            return i * j;
          case ’/’: return i /
          j;
          case ’%’:
            return i % j;
          default:
            return 0;
          }
        }
        short getTotal(short n) {
          short total = 0;
          if (n <= 0)
            ++total;
          while (n != 0) {
            n /= 10;
            ++total;
          }
          return total;
        }
        short getMax(char sign, short n) {
          short max = 0;
          for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
              short n = getTotal(getValue(sign, i, j));
              if (n > max)
                max = n;
            }
          }
          return max + 1;
        }
        short getTableSize(string operation) {
          short size;
          while (true) {
            cout << "What size should the " << operation << " table be? ";
            cin >> size;
            if (size <= 0) {
              cout << "I’m sorry, " << size << " would be stupid..." << endl;
            } else if (size >= 20) {
              cout << "I’m sorry, " << size << " is too large of a table to
              print on the screen..." << endl;
            } else {
              cout << endl << "Thank you...calculating..." << endl << endl;
              return size;
            }
          }
        }
        char getUserInput() {
          char input;
          cin >> input;
          return input;
        }
