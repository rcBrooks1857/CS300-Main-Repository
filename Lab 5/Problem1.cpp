#include <iostream>
using namespace std;

class MyString {
private:
    char* data;
    int length;

public:
    MyString(){
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    MyString(const char* str){
        length = 0;

        while (str[length] != '\0'){
            length++;
        }

        data = new char[length + 1];

        for (int i = 0; i < length; i++){
            data[i] = str[i];
        }

        data[length] = '\0';
    }

    ~MyString(){
     delete[] data;
    }

    int size() const{
        return length;
    }

    char getChar(int index) const{
        if (index >= 0 && index < length){
            return data[index];
        }
        return '\0';
    }

    void setChar (int index, char c){
        if (index >= 0 && index < length){
            data[index] = c;
        }
    }

    void setString(const char* str){
        int newLength = 0;

        while (str[newLength] != '\0'){
            newLength++;
        }

        char* newData = new char[newLength + 1];

        for (int i = 0; i < newLength; i++){
            newData[i] = str[i];
        }

        newData[newLength] = '\0';

        delete[] data;

        data = newData;
        length = newLength;


    }

    void print() const{
        cout << data << endl;
    }
};

int main(){
    MyString s("hello");

    cout << "Initial string: ";
    s.print();

    cout << "Length: " << s.size() << endl;

    cout << "Character at index 1: "
         << s.getChar(1) << endl;

    s.setChar(0, 'H');

    cout << "After setChar: ";
    s.print();

    s.setString("Computer Science");

    cout << "After setString: ";
    s.print();

    cout << "New length: "
         << s.size() << endl;

    return 0;
}