#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(string file1, string file2)
{
	ifstream input_file(file1);
	ofstream output_file(file2);
	cout << "asdf";

	char ch;
	while (!input_file.eof())
	{
		input_file.get(ch);
		cout << ch << endl;
		if (!input_file.good())
			break;
		if (ch == '\r')
			output_file << '\n';
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
}

//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	cout << "�Ķ���� ���� = " << argc << endl;
//	// argv[0]�� �������� �̸��� ���� �� ���� �� ��
//	for (int i = 0; i < argc; i++)
//		cout << i << "-th argement = " << argv[i] << endl;
//	return 0;
//}