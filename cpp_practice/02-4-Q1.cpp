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
	cin >> s1 >> s2; // cin은 공백 또는 띄어쓰기(\0) 기준으로 문자열을 입력 받음
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	cout << s1_len << "," << s2_len << endl;
	strcpy(s3, s1); // s3에 s1을 복사
	strcat(s3, s2); // s3뒤에 s2 문자열 붙여놓기

	cout << s3 << ", " << strlen(s3) << endl;

	if (!strcmp(s1, s2)) cout << "true" << endl; // s1과 s2를 비교 0을 반환하면 똑같다
	else cout << "false" << endl;


	delete s1;
	delete s2;
	delete s3;

	return 0;
}