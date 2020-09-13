#include <iostream>
#include "Prog1.h"

namespace Prog1 {
    double** matrix_input(int &rm, int &rn) {
        const char *pr = "";
        double **matrix = nullptr;
        int m, n;
        
        do {
            std::cout << pr;
            std::cout << "Enter the matrix dimensions: ";
            pr = "Invalid input, please try again!\n";
            if (getNum(m) < 0 || getNum(n) < 0) {
               return nullptr;
            }
        } while (m < 1 || n < 1);
        
        try {
            matrix = new double*[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "Too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }
        
        for (int i = 0; i < m; i++) {
            try {
                matrix[i] = new double[n];
            }
            catch (std::bad_alloc &ba) {
                std::cout << "Too many columns in matrix: " << ba.what() << std::endl;
                matrix_erase(matrix, i);
                return nullptr;
            }
            std::cout << "Enter the items for matrix row #" << (i + 1) << ": ";
            for (int j = 0; j < n; j++) {
                if (getNum(matrix[i][j]) < 0) {
                   matrix_erase(matrix, i + 1);
                   return nullptr;
                }
            }
        }
        
        rm = m;
        rn = n;
        return matrix;
    }
    
    void matrix_output(const char *msg, double **a, int m, int n) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void vector_output(const char *msg, double a[], int m) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    
    double **matrix_erase(double **&matrix, int m) {
        for (int i = 0; i < m; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        return nullptr;
    }
    
    double* vector_result(double **a, int m, int n) {
        double *array = nullptr;    
        try {
            array = new double[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return nullptr;
        }
        
        for (int i = 0; i < m; i++) {
            if (a[i][0] != 0) {
               array[i] = avg(a[i], n) / max(a[i], n, isgreater);
            }
            else {
               array[i] = avg(a[i], n) / first_nonzero(a, m, n);
            }
        }
        return array;
    }
    
    double first_nonzero(double **a, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                   return a[i][j];
                }
            }
        }
        return -1;
    }
    
    double avg(double a[], int n) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        return sum / n;
    }

    double max(double a[], int m, int(*f)(double, double)) {
        double res = a[0];
        for (int i = 0; i < m; i++) {
            if (f(a[i], res) > 0) {
               res = a[i];
            }
        }
        return res;
    }
}
