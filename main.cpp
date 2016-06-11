#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Encrypt(string text);
string Decrypt(string text);
void loadCypher();

string input;
char cypher[6][5];

string Encrypt(string text)
{
	std::string Encrypted;

    for (int x = 0; x <= text.length(); x++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (text[x] == cypher[i][y])
				{
					Encrypted.append(std::to_string(i));
					Encrypted.append(std::to_string(y));
                }
            }
        }
    }

	return Encrypted;
};

string Decrypt(string text)
{
	string Decrypted;

	for (int i = 0; i < text.length(); i+=2)
	{
		int x = text[i] - '0';
        int y = text[i+1] - '0';

		char Letter = cypher[x][y];

		Decrypted += Letter;	
	}

	return Decrypted;
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
    } else {    cout << "Cypher File is not open"; }
}


int main()
{
    loadCypher();
    cin >> input;

	cout << Encrypt(input) << "\n\n";

	cin >> input;	

	cout << Decrypt(input);

	cin >> input;	//somthing to stop the program from just closing
}

