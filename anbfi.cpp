#include <iostream>
#include <fstream>
using namespace std;

unsigned char arr[30000];
short i = 0;

void check_code(string code){
    for(int j = 0; j < code.length(); j ++) {
        switch (code[j]) {
        case '+':
            arr[i] ++;
            break;
        case '-':
            arr[i] --;
            break;
        case '>':
            i ++;
            break;
        case '<':
            i --;
            break;
        case '.':
            cout << arr[i];
            break;
        case ',':
            cin >> arr[i];
            break;
        case '[':
            while(arr[i] != 0){
                check_code(code.substr(j + 1, code.substr(j + 1, code.length()).find(']')));
            }
            j += code.substr(j + 1, code.length()).find(']') + 1;
            break;
        default:
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream indata;
    indata.open(argv[1]);
    string code;
    getline(indata, code, (char)0);
    check_code(code);
}