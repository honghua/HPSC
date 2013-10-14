/*
 *  ref: https://raw.github.com/davetcoleman/matrix_multiply/master/lab2/lab2.cpp
 */

#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

struct matrix{
    double *data;
    int rows;
    int cols;
};

void matrix_read(string &filename, matrix &data);
void matrix_dot(matrix &matrix1, matrix &matrix2, matrix &matrix_out);
void matrix_write(const string &filename, matrix &data);
void get_walltime(double* wcTime);

int main(int argc, char ** argv)
{
	double S, E, WT;    // time stamp
	get_walltime(&S);   // start timing

    // read in file names
    string file_in1 = argv[1];
    string file_in2 = argv[2];
    string file_out = argv[3];
    
    // read in matrix data
    matrix matrix1;
    matrix_read(file_in1, matrix1);

    matrix matrix2;
    matrix_read(file_in2, matrix2);

    // matrix dot product
    matrix matrix_out;
    matrix_dot(matrix1, matrix2, matrix_out);

    // write to a file
    matrix_write(file_out, matrix_out);
    
	// end timing
	get_walltime(&E);
	WT = E - S;

    cout << endl;
    cout << matrix1.rows << "X" << matrix1.cols << " times " << matrix2.rows << "X" << matrix2.cols;
    cout << " takes " << WT << " sec" << endl;
}


void matrix_read(string &filename, matrix &data)
{
    int rows, cols;

    std::ifstream input(filename.c_str());

    input >> rows >> cols;
    int size = rows*cols;
    
    data.rows = rows;
    data.cols = cols;
    data.data = new double[size];

    // Loop through data
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            const int index = i*cols + j;
            input >> data.data[index];
        }
    }

    input.close();
}

void matrix_dot(matrix &matrix1, matrix &matrix2, matrix &matrix_out)
{
	matrix_out.rows = matrix1.rows; // rows = rows of matrix 1
	matrix_out.cols = matrix2.cols; // cols = cols of matrix 2
	matrix_out.data = new double[matrix_out.rows * matrix_out.cols];

	// Loop through every cell of the output matrix
	for(int i = 0; i < matrix_out.rows; ++i)
	{
		for(int j = 0; j < matrix_out.cols; ++j)
		{
			matrix_out.data[i*matrix_out.cols + j] = 0;

			for(int inner = 0; inner < matrix1.cols; inner++)
			{
				matrix_out.data[i*matrix_out.cols + j] += matrix1.data[i*matrix1.cols + inner] *
                                                          matrix2.data[inner*matrix2.cols + j];
			}
		}
	}
}


void matrix_write(const string &filename, matrix &data)	
{
    ofstream outfile;
    outfile.open (filename.c_str());
    outfile << data.rows << " " << data.cols << endl;

    for (int i=0; i < data.rows; i++)
    {
        for (int j=0; j < data.cols; j++)
        {
            const int index = i*data.cols + j;
            outfile << data.data[index] << " ";
        }
        outfile << endl;
    }
    
    outfile.close();			   
}

// timing function
void get_walltime_(double* wcTime) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

void get_walltime(double* wcTime) {
  get_walltime_(wcTime);
}
