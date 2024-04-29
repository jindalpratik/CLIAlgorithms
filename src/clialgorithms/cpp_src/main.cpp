#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;

namespace py = pybind11;

/*
Class for all the informations and practice code related to arrays.
*/
class Arrays
{

public:
    /*
    The functions provides the information about arrays in c++.
    */
    void info()
    {
        cout << "Arrays is the collection of elements of same datatypes placed in contigous memory allocation" << endl;
    }

    // -> Normal array operations.

    /*
    This is an example code in which we create an array with 100 elments allocated and defaulting to the value 0,
    after which we ask the number of students for which we are updating the marks for and update the marks as entered,
    displaying the marks after taking all the inputs.
    */
    void array_example_1()
    {
        int marks[100] = {-1};

        int num;
        cout << "Enter the number of students :";
        cin >> num;

        for (int i = 1; i <= num; i++)
        {
            cin >> marks[i];
        }

        cout << "The marks of students are as follows :";
        for (int i = 0; i < 100; i++)
        {
            cout << marks[i] << " ,";
        }

        cout << endl;
    }

    // -> Passing arrays to functions.

    /*
    The below example is an example of passing an array in c++ to a function but as we can see when we try to
    ``print the size of array to console we instead get the size of integer``. This is because when we pass an
    array to a function in c++ it decays to a pointer to the first element of the array.
    */
    void array_example_2()
    {
        int arr_ex_1[] = {1, 2, 3, 4, 5, 6};
        int n = sizeof(arr_ex_1) / sizeof(int);

        cout << "sizeof(arr) in base function :: " << sizeof(arr_ex_1) << endl;

        array_example_2_printArray(arr_ex_1);
    }

    /*
    To get around the issue of array decaying to a pointer when passing them to a function we have to precalculate the
    size of the array and pass the size of the array along with the array to the function. We would require something like
    this if we want to do something like printing the elements of array via a function seperate from where the array was
    initially declared.
    */
    void array_example_3()
    {
        int arr_ex_2[] = {1, 2, 3, 4, 5, 6};

        int n = sizeof(arr_ex_2) / sizeof(int);

        array_example_3_printArray(arr_ex_2, n);
    }

    // -> Searching in arrays.

    /*
    The below function implements the linear search algorithm which goes through an array in linear order to find the
    target element which we are search for trying to match each element with the target element as it goes through the
    array.
    */
    void linear_search()
    {
        int arr_ls[] = {4, 7, 8, 9, 5, 2};
        int len = sizeof(arr_ls) / sizeof(int);
        int input;
        cout << "Enter element to find via linear search :: ";
        cin >> input;
        int index = linear_search_linearSearch(arr_ls, len, input);
        if (index == -1)
        {
            cout << input << " not found" << endl;
        }
        else
        {
            cout << input << " present at index :: " << index << endl;
        }
    }

private:
    /*
    Helper funciton for array_example_2().
    */
    void array_example_2_printArray(int arr_ex_1[])
    {
        cout << "sizeof(arr) :: " << sizeof(arr_ex_1) << endl;
    }

    /*
    Helper function for array_example_3().
    */
    void array_example_3_printArray(int arr_ex_2[], int n)
    {
        cout << "sizeof(arr) :: " << n << endl;

        for (int i = 0; i < n; i++)
        {
            cout << arr_ex_2[i] << " ";
        }
        cout << endl;
    }

    /*
    Helper function for linear search().
    */
    int linear_search_linearSearch(int arr_ls[], int len, int input)
    {
        for (int i = 0; i <= len; i++)
        {
            if (arr_ls[i] == input)
            {
                return i;
            }
        }
        return -1;
    }
};

PYBIND11_MODULE(cppalgorithm, m)
{
    m.doc() = "cpp module for the python project"; // optional module docstring

    py::class_<Arrays>(m, "Arrays")
        .def(py::init<>())
        .def("info", &Arrays::info)
        .def("array_example_1", &Arrays::array_example_1)
        .def("array_example_2", &Arrays::array_example_2)
        .def("array_example_3", &Arrays::array_example_3)
        .def("linear_search", &Arrays::linear_search);
}
