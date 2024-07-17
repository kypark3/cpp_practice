#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

int main() {

	char *s1 = new char[100];
	char *s2 = new char[100];
	char *s3 = new char[200];
	cin >> s1 >> s2; // cin�� ���� �Ǵ� ����(\0) �������� ���ڿ��� �Է� ����
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	cout << s1_len << "," << s2_len << endl;
	strcpy(s3, s1); // s3�� s1�� ����
	strcat(s3, s2); // s3�ڿ� s2 ���ڿ� �ٿ�����

	cout << s3 << ", " << strlen(s3) << endl;

	if (!strcmp(s1, s2)) cout << "true" << endl; // s1�� s2�� �� 0�� ��ȯ�ϸ� �Ȱ���
	else cout << "false" << endl;


	delete s1;
	delete s2;
	delete s3;

	return 0;
}