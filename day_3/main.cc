#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef unsigned long ul;

int binary_to_decimal(ul n)
{
    int dec_value = 0;
    int base = 1;

    ul temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp /= 10;

        dec_value += last_digit * base;

        base *= 2;
    }

    return dec_value;
}

ul find_oxygen_generator_rating(vector<string> numbers)
{
    size_t line_size = numbers[0].size();
    for (size_t i = 0; i < line_size; i++)
    {
        int zeros = 0;
        for (auto & number : numbers)
            if (number[i] == '0')
                zeros++;

        vector<string> tmp;
        if (zeros > numbers.size() / 2)
        {
            for (auto & number : numbers)
                if (number[i] == '0')
                    tmp.push_back(number);
        }
        else
        {
            for (auto & number : numbers)
                if (number[i] == '1')
                    tmp.push_back(number);
        }

        numbers = tmp;
    }

    return stoul(numbers[0]);
}

ul find_co2_scrubber_rating(vector<string> numbers)
{
    size_t line_size = numbers[0].size();
    for (size_t i = 0; i < line_size; i++)
    {
        int zeros = 0;
        for (auto & number : numbers)
            if (number[i] == '0')
                zeros++;

        vector<string> tmp;
        if (zeros <= numbers.size() / 2)
        {
            for (auto & number : numbers)
                if (number[i] == '0')
                    tmp.push_back(number);
        }
        else
        {
            for (auto & number : numbers)
                if (number[i] == '1')
                    tmp.push_back(number);
        }

        numbers = tmp;
    }

    return stoul(numbers[0]);
}

int find_life_support_rating(ul oxygen, ul co2)
{
    return binary_to_decimal(oxygen) * binary_to_decimal(co2);
}

int main()
{
    ifstream file ("data.txt");

    map<int, ii> counter;
    vector<string> numbers;

    string line;
    while (file >> line)
    {
        for (size_t i = 0; i < line.size(); i++)
            line[i] == '0' ? counter[i].first++ : counter[i].second++;

        numbers.push_back(line);
    }

    ostringstream gamma(""), epsilon("");
    for (auto & pii : counter)
    {
        if (pii.second.first > pii.second.second)
        {
            gamma << 0;
            epsilon << 1;
        }
        else
        {
            gamma << 1;
            epsilon << 0;
        }
    }

    int decimal_gamma = binary_to_decimal(stoul(gamma.str()));
    int decimal_epsilon = binary_to_decimal(stoul(epsilon.str()));

    printf("%d\n", decimal_gamma * decimal_epsilon);

    ul oxygen_generator_rating = find_oxygen_generator_rating(numbers);
    ul co2_scrubber_rating = find_co2_scrubber_rating(numbers);

    printf("%d\n", find_life_support_rating(oxygen_generator_rating,
                                            co2_scrubber_rating));

    return 0;
}
