#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string input;
char cypher[6][5];

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

void loadCypher()
{
    string fileText;
    ifstream file_("cypher.txt");
    if (file_.is_open())
    {
        while(getline(file_,fileText));
        int j = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int y = 0; y < 5; y++)
            {
                cypher[i][y] = fileText[j];
                j+=1;
            }
        }
        file_.close();
    } else {    cout << "File is not open"; }
}


int main()
{
    loadCypher();
    cin >> input;
}

