#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Encrypt(string text);
string Decrypt(string text);
void loadCypher();

const unsigned CypherWidth = 6;
const unsigned CypherHeight = 5;

string input;
char cypher[CypherWidth][CypherHeight];

string Encrypt(string text)
{
	std::string Encrypted;

    for (int iLetter = 0; iLetter <= text.length(); iLetter++)
    {
        for (int i = 0; i < CypherWidth; i++)
        {
            for (int y = 0; y < CypherHeight; y++)
            {
                if (text[iLetter] == cypher[i][y] || text[iLetter] == cypher[i][y] - 32)	//32 is the offset to make uppcase equal to lowercase
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
		//You set j to 0, then add one to j every time, why just not use a for loop? - Kieren

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

