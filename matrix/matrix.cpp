//未来企划：能够抛出异常
#include <iostream>

template<typename T>
class Matrix
{
public:
    Matrix() : row(0),line(0) {};
    Matrix(const Matrix&);
    Matrix(unsigned int,unsigned int);
    Matrix(unsigned int,unsigned int,T**);
    ~Matrix();
    void operator=(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const T&);
    Matrix operator/(const Matrix&);
    Matrix operator/(T&);
    T* operator[](unsigned int);
private:
    unsigned int row,line;
    T** matrix;
    void allocateMatrix(void);
    T** allocateTmpMatrix(unsigned int,unsigned int);
};

template<typename T>
T** Matrix<T>::allocateTmpMatrix(unsigned int row,unsigned int line)
{
    T** tmp=new T*[row];
    for(unsigned int i=0;i<row;++i)
        tmp[i]=new T[line];
    return tmp;
}

template<typename T>
Matrix<T>::Matrix(unsigned int row,unsigned int line)
{
    this->row=row;
    this->line=line;
    allocateMatrix();
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            matrix[i][j]=0;
}

template<typename T>
Matrix<T>::Matrix(unsigned int row,unsigned int line,T** matrix) : Matrix(row,line)
{
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            this->matrix[i][j]=matrix[i][j];
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) : row(other.row),line(other.line)
{
    allocateMatrix();
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            matrix[i][j]=other.matrix[i][j];
}

template<typename T>
Matrix<T>::~Matrix()
{
    for(unsigned int i=0;i<row;++i)
        delete[] matrix[i];
    delete[] matrix;
}

template<typename T>
void Matrix<T>::allocateMatrix(void)
{
    matrix=allocateTmpMatrix(row,line);
}

template<typename T>
void Matrix<T>::operator=(const Matrix& other)
{
    for(unsigned int i=0;i<row;++i)
        delete[] matrix[i];
    delete[] matrix;
    row=other.row;
    line=other.line;
    allocateMatrix();
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            matrix[i][j]=other.matrix[i][j];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other)
{
    T** tmp=allocateTmpMatrix(row,line);
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            tmp[i][j]=matrix[i][j]+other.matrix[i][j];
    return Matrix<T>(row,line,tmp);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other)
{
    T** tmp=allocateTmpMatrix(row,line);
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            tmp[i][j]=matrix[i][j]-other.matrix[i][j];
    return Matrix<T>(row,line,tmp);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& num)
{
    T** tmp=allocateTmpMatrix(row,line);
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<line;++j)
            tmp[i][j]=matrix[i][j]*num;
    return Matrix<T>(row,line,tmp);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other)
{
    if(line!=other.row)
        return Matrix<T>();
    T** tmp=allocateTmpMatrix(row,other.line);
    for(unsigned int i=0;i<row;++i)
        for(unsigned int j=0;j<other.line;++j)
            for(unsigned int k=0;k<line;++k)
                tmp[i][j]+=matrix[i][k]*other.matrix[k][j];
    return Matrix<T>(row,other.line,tmp);
}

template<typename T>
T* Matrix<T>::operator[](unsigned int index)
{
    return matrix[index];
}

int main()
{
    int counter=1;
    int** matrix=new int*[3];
    for(int i=0;i<3;++i)
        matrix[i]=new int[3];
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        {
            matrix[i][j]=counter;
            ++counter;
        }
    Matrix<int> a(3,3,matrix);
    Matrix<int> b=a;
    a[2][2]=100;
    b=b*12;
    for(int i=0;i<3;++i)
        std::cout<<b[i][i]<<std::endl;
    return 0;
}