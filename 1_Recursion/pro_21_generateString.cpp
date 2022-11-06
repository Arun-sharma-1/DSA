#include <bits/stdc++.h>
using namespace std;
void generateString(string str, char *output, int index = 0, int Oindex = 0)
{

    if (str[index] == '\0')
    {
        output[Oindex] = '\0';
        cout << output << endl;
        return;
    }
    // one digit at a time
    int digit = int(str[index]) - '0';
    char ch = digit + 'A' - 1;
    output[Oindex] = ch;
    generateString(str, output, index + 1, Oindex + 1);

    // two digit
    if (str[index + 1] != '\0')
    {
        int secondDigit = int(str[index + 1]) - '0';
        int no = digit * 10 + secondDigit;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            output[Oindex] = ch;
            generateString(str, output, index + 2, Oindex + 1);
        }
    }
}
int main()
{
    char output[100];
    generateString("1234", output);
}