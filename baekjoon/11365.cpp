#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string result = "";

	while (1)
	{
		getline(cin, str);
		if (str == "END") {
			cout << result;
			return 0;
		}

		int len = str.length();
		for (int i = 0; i < len / 2; i++)
		{
			char tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
		}

		result += (str + "\n");
	}
}
