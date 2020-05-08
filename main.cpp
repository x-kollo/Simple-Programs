#include <iostream>
using namespace std;

int sfind(char symb, char* text)
{
	if (text[0] == symb)
		return 0;
	for (int i = 1; i < strlen(text); i++)
	{
		if (text[i] == symb && text[i-1] == ' ')
		{
			return i;
		}
	}
	return -1;
}
void DeleteWord(unsigned pos, char* text)
{
	bool stop = false;
	for (int i = pos; i <= strlen(text); i++)
	{
		if(stop)
			break;
		if (text[i] == ' ' || text[i] == '\0')
		{
			for (int j = pos; j < i; j++)
			{
				text[j] = ' ';
				stop = true;
			}
		}
	}	
}
int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(0, "ukr");
	char* text = new char[255];
	char* buffer = new char[255];
	char** denyword = new char*[255];
	cout << "¬вед≥ть текст: ";
	cin.getline(text, 255);
	cout << "¬вед≥ть заборонен≥ л≥тери: ";
	cin.getline(buffer, 255);
	unsigned dw_count = 0;
	char* ChBuff[1];
	for (int i = 0; i < strlen(buffer); i+=2)
	{
		denyword[dw_count] = new char[2];
		denyword[dw_count][0] = buffer[i];
		denyword[dw_count][1] = '\0';
		dw_count++;
	}
	
	bool isfirst = false;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] != ' ' && text[i - 1] == ' ')
		{
			for (int j = 0; j < dw_count; j++)
			{
				if (sfind(denyword[j][0], text) >= 0)
					DeleteWord(sfind(denyword[j][0], text), text);
			}	
		}
		else if (i == 0)
		{
			for (int j = 0; j < dw_count; j++)
			{
				if (sfind(denyword[j][0], text) >= 0)
					DeleteWord(sfind(denyword[j][0], text), text);
			}
		}
	}
	cout << "‘орматовий текст: "  << text << endl;
	for (int i = 0; i < dw_count; i++)
		delete[] denyword[i];
	delete[] denyword;
	delete[] text;
	delete[] buffer;
	return 0;
}