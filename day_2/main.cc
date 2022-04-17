#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    ifstream file ("data.txt");
    string direction;
    int horizontal = 0, vertical = 0, aim = 0;

    bool unit_line = false;
    string input;
    while (file >> input)
    {
        if (unit_line)
        {
            if (direction == "forward")
            {
                horizontal += stoi(input);
                vertical += aim * stoi(input);
            }
            else if (direction == "down")
                aim += stoi(input);
            else
                aim -= stoi(input);
        }
        else
            direction = input;

        unit_line = !unit_line;
    }

    printf("%d\n", horizontal * vertical);

    return 0;
}
