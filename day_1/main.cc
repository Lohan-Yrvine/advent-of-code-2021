#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    ifstream file ("data.txt");

    int counter = 0, value_1 = 0, value_2 = 0, util = 0;
    int increases = 0;
    int number;
    while (file >> number)
    {
        if (counter < 3)
            value_1 += number;

        if (counter > 0)
            value_2 += number;

        if (counter >= 2)
            util += number;

        if (counter == 3)
        {
            if (value_2 > value_1)
                increases++;

            counter = 2;
            value_1 = value_2;
            value_2 = util;
            util = number;
        }

        counter++;
    }

    printf("%d\n", increases);

    return 0;
}
