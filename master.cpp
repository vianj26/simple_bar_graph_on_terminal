#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
int find_max_value(T (&arr)[N]);

template<typename T, size_t N>
void graph(T (&arr)[N], int);

int main()
{
    const int SIZE = 5;
    int values[SIZE];
    string legends[SIZE];

    //Input section
    for(int i = 0; i < SIZE; i++)
    {
        cout << "What is legend " << i + 1 << ": ";
        cin >> legends[i];
        cout << "What is value " << i + 1 << ": ";
        cin >> values[i];
    }

    int bar_values[SIZE];
    int max_value = find_max_value(values);
    
    for(int i = 0; i < SIZE; i++)
    {
        bar_values[i] = values[i] - max_value;
    }

    cout << endl;

    graph(bar_values, max_value);

    
    cout << endl <<  "\t" << "\t";

    for(int i = 0; i < SIZE; i++)
    {
        cout << legends[i] << "\t" ;
    }

    return 0;
}

//finding max values inside the value list
template<typename T, size_t N>
int find_max_value(T (&arr)[N])
{
    int max = 0;

    for(int i = 0; i < N; i++)
    {
        arr[i] > max ? max = arr[i] : max = max;
    }

    return max;
}

//generate the bar graph
template<typename T, size_t N>
void graph(T (&arr)[N], int max_value)
{
    while(max_value > 0 )
    {
        cout << "  "<< max_value << "\t" << "|" << "\t";

        for(int i = 0; i < N; i++)
        {
            cout << (arr[i] >= 0 ? char(219) : ' ') << "\t";
        }

        for(int i = 0; i < N; i++){arr[i] += 1;}

        cout << endl;

        max_value--;
    }
}