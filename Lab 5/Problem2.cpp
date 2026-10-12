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

    MyString(const MyString& other){
        length = other.length;

        data = new char[length + 1];

        for(int i = 0; i < length; i++){
            data[i] = other.data[i];
        }
        data[length] = '\0';
    }

    MyString& operator=(const MyString& other){
        if (this != &other){
            char* newData = new char[other.length + 1];

            for (int i = 0; i < other.length; i++){
                newData[i] = other.data[i];
            }
            newData[other.length] = '\0';

            delete[] data;
            data = newData;
            length = other.length;
        }
        return *this;
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

int main() {
    MyString s1("hello");

    // Test copy constructor
    MyString s2 = s1;

    s2.setChar(0, 'H');

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    // Test copy assignment
    MyString s3("UAB");
    s3 = s1;

    s3.setChar(1, 'A');

    cout << "s1: ";
    s1.print();

    cout << "s3: ";
    s3.print();

    // Test self-assignment
    s1 = s1;

    cout << "After self-assignment, s1: ";
    s1.print();

    return 0;
}