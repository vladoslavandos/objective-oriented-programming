namespace Prog1 {
    template <class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
           return -1;
        }
        return 1;
    }
    
    inline int isgreater(double a, double b) {
        return a > b;
    }
    
    double** matrix_input(int &, int &);
    void matrix_output(const char *, double **, int, int);
    void vector_output(const char *, double [], int);
    double **matrix_erase(double **&, int);
    double* vector_result(double **, int, int);
    double first_nonzero(double **, int, int);
    double avg(double [], int);
    double max(double [], int, int(*)(double, double));
}
