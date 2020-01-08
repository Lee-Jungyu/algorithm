#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		string url;
		string protocol;
		string host;
		string port;
		string path;
		cin >> url;
		int check = 0;
		for (int j = 0; j < url.length(); j++)
		{
			if (check == 0 && url.substr(j, 3) == "://")
			{
				protocol = url.substr(0, j);
				j = j + 2;
				check = 1;
			}
			else if (check == 1)
			{
				if (url[j] != ':' && url[j] != '/')
				{
					host += url[j];
				}
				else if (url[j] == ':')
				{
					check = 2;
				}
				else if (url[j] == '/')
				{
					check = 3;
				}
			}
			else if (check == 2)
			{
				if (url[j] != '/')
				{
					port += url[j];
				}
				else
				{
					check = 3;
				}
			}
			else if (check == 3)
			{
				path += url[j];
			}
		}
		check = 0;

		cout << "URL #" << i + 1 << endl;
		cout << "Protocol" << " = "<< protocol << endl;
		cout << "Host" <<"     = "<< host << endl;
		if (port.length() == 0)
			port = "<default>";
		cout << "Port" <<"     = " << port << endl;
		if (path.length() == 0)
			path = "<default>";
		cout << "Path" <<"     = " << path << endl;
		cout << endl;
	}
}
