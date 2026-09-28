#include <iostream>
using namespace std;

void addScore(int*& scores, int& size, int& capacity, int score){
    if (size == capacity){
        capacity = capacity * 2;

    int* newScores = new int[capacity];

    for (int i = 0; i < size; i++){
        newScores[i] = scores[i];
    }
    delete[] scores;
    scores = newScores;
    }
    scores[size] = score;
    size++;
}

void removeScore(int* scores, int& size, int index){
    for (int i = index; i < size - 1; i++){
        scores[i] = scores[i+1];
    }
    size--;
}

void printScores(const int* scores, int size){
    for (int i = 0; i < size; i++){
        cout << scores[i] << " ";
    }
    cout << endl;
}

double average(const int* scores, int size){
    int total = 0;

    for (int i = 0; i < size; i++){
        total += scores[i];
    }
    return static_cast<double>(total) / size;
}

int maximum(const int* scores, int size){
    int max = scores[0];

    for (int i = 1; i < size; i++){
        if (scores[i] > max){
            max = scores[i];
        }
    }
    return max;
}


int minimum(const int* scores, int size){
    int min = scores[0];

    for(int i = 1; i < size; i++){
        if (scores[i] < min){
            min = scores[i];
        }
    }
    return min;
}

int main(){
    int size = 0;
    int capacity = 3;
    int* scores = new int[capacity];

    addScore(scores, size, capacity, 80);
    addScore(scores, size, capacity, 90);
    addScore(scores, size, capacity, 70);
    addScore(scores, size, capacity, 85);

    cout << "Scores: ";
    printScores(scores, size);


    cout << "Average: " << average(scores, size) << endl;
    cout << "Maximum: " << maximum(scores, size) << endl;
    cout << "Minimum: " << minimum(scores, size) << endl;

    removeScore(scores, size, 1);

    cout << "Scores after removal: ";
    printScores(scores, size);

    delete[] scores;
    
    return 0;
}