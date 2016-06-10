#include <iostream>
#include <string>

using namespace std;

string input;
char cypher[6][5] =
{
    {'a','b','c','d','e'},
    {'f','g','h','i','j'},
    {'l','m','n','o','p'},
    {'q','r','s','t','u'},
    {'v','w','x','y','z'},
    {'k','@','!','%','-'}
};

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

void Decrypt(string text)
{
  for (int i = 0; i < text.length(); i+=2)
  {
        int x = text[i] - '0';
        int y = text[i+1] - '0';

        cout << cypher[x][y];
  }
};

int main()
{
    cin >> input;
    Decrypt(input);

}

