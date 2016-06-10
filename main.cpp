#include <iostream>
#include <string>

using namespace std;

int CharToInt(char letter);
void Encrypt(string text);
void Decrypt(string text);

char cypher[6][5] =
{
    {'a','b','c','d','e'},
    {'f','g','h','i','j'},
    {'l','m','n','o','p'},
    {'q','r','s','t','u'},
    {'v','w','x','y','z'},
    {'k','j','j','j','j'}
};

string input;

void Encrypt(string text)
{
    for (int x = 0; x <= text.length(); x++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (text[x] == cypher[i][y]){
                    cout << i << y;
                }
            }
        }
    }
};

int CharToInt(char letter)
{
    int x;
    if (letter == '1')
        x = 1;
    if (letter == '2')
        x = 2;
    if (letter == '3')
        x = 3;
    if (letter == '4')
        x = 4;
    if (letter == '5')
        x = 5;
    return x;
}

void Decrypt(string text)
{
  for (int i = 0; i < text.length(); i+=2)
  {
        int x = CharToInt(text[x]);
        int y = CharToInt(text[x+1]);

        cout << cypher[x][y];
  }
};

int main()
{
    cin >> input;
    Decrypt(input);
}

