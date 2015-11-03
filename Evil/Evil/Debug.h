#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Debug {
private:
	ofstream out;

public:
	Debug()
	{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);

		char time[100];
		sprintf_s(time, "%02d%02d%02d%02d", now.tm_mday+1, now.tm_mday, now.tm_hour, now.tm_sec);

		string filename = "";
		filename += "LOG";
		filename += time;
		filename += ".txt";
		out.open(filename.c_str(), ios::out);
	}

	~Debug()
	{
		out.close();
	}

	void log(string message)
	{
		message = makeTimeHeader() + ": " + message;
		cout << message << endl;
		out << message << endl;
	}

	string makeTimeHeader()
	{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);

		string header = "";
		char buf[100];
		sprintf_s(buf, "%02d.%02d.%02d", now.tm_mday, now.tm_hour, now.tm_sec);
		header = buf;

		return header;
	}
};