#include <iostream>
#include <string>
using namespace std;

int isValid(string str, int st, int en) {
	if (st >= en) return 0;
	while (st < en) {
		if ('1' <= str[st] && str[st] <= '9' || str[st] == ',') { st++; }
		else { return 0; }
	}
	return 1;
}

int main() {
	string str = "1,123,456dollar123,456dollar1,759dollar9,324dollar";
	int cnt = 0;

	int prev = 0;
	int pos = str.find("dollar");
	string temp = str.substr(prev, pos - prev + 6);

	while (pos != string::npos) {
		string after = str.substr(prev);
		pos = after.find("dollar");

		if (cnt == 0) {
			cout << temp << "\n";
			prev = pos + 6;
		}
		else {
			string cut = after.substr(0, pos + 6);
			cout << cut << endl;
			prev += pos + 6;
		}
		cnt++;

		if (cnt == 4) break;
	}
	return 0;
}