#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Функция для ввода квадратной матрицы!!!
void inputMatrix(vector<vector<int>>& matrix, int size, const string& name) {
    cout << "Введите элементы матрицы " << name << " (строка за строкой):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Функция для вывода квадратной матрицы!!!
void printMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << "Матрица " << name << ":" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Функция для записи матрицы в файл!!!
void saveMatrixToFile(const vector<vector<int>>& matrix, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << matrix.size() << endl;
        for (const auto& row : matrix) {
            for (int elem : row) {
                file << elem << " ";
            }
            file << endl;
        }
        file.close();
        cout << "Матрица сохранена в файл: " << filename << endl;
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения матрицы из файла!!!
void loadMatrixFromFile(vector<vector<int>>& matrix, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int size;
        file >> size;
        matrix.resize(size, vector<int>(size));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
        cout << "Матрица загружена из файла: " << filename << endl;
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

int countElementsGreaterThanColumnSum(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int size = A.size();
    int count = 0;

    for (int j = 0; j < size; j++) {
        int columnSum = 0;
        for (int i = 0; i < size; i++) {
            columnSum += B[i][j];
        }
        for (int i = 0; i < size; i++) {
            if (A[i][j] > columnSum) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "rus");

    int size;
    cout << "Введите размерность матриц (N x N): ";
    cin >> size;

    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<int>> C(size, vector<int>(size));

    // Ввод матриц!!!
    inputMatrix(A, size, "A");
    inputMatrix(B, size, "B");
    inputMatrix(C, size, "C");

    // Вывод матриц!!!
    printMatrix(A, "A");
    printMatrix(B, "B");
    printMatrix(C, "C");

    // Сохранение матриц в файлы!!!
    saveMatrixToFile(A, "matrix_A.txt");
    saveMatrixToFile(B, "matrix_B.txt");
    saveMatrixToFile(C, "matrix_C.txt");

    // Чтение матрицы C из файла 
    vector<vector<int>> loadedMatrix;
    loadMatrixFromFile(loadedMatrix, "matrix_C.txt");
    printMatrix(loadedMatrix, "C (загруженная)");

    // Подсчет количества элементов A, превышающих сумму столбцов B!!!)
    int count = countElementsGreaterThanColumnSum(A, B);
    cout << "Количество элементов матрицы A, превышающих сумму элементов в аналогичных столбцах матрицы B: " << count << endl;

    return 0;
}