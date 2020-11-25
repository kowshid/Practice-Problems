#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile("D:\\input.txt");
    string line, temp;
    int count;

    while(getline(infile, line)) //here delimiter for getline is '\n'
    {
        count = 0;
        stringstream str(line);
        //cout << line << "\n";

        while(getline(str, temp, ' ')) //using delimiter '\n' to seperate
            count++;

        printf("%d\n", count);
    }

    return 0;
}
