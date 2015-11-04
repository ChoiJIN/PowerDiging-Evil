#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "date.h"

using namespace std;

class Debug {
private:
	ofstream out;

public:
	Debug()
	{
		out.open(makeNewFilename().c_str(), ios::out);
	}

	~Debug()
	{
		out.close();
	}

	inline void log(string message)
	{
		message = makeTimeHeader() + message;
		cout << message << endl;
		out << message << endl;
	}

	inline string makeNewFilename()
	{
		return string("LOG" + getTimeString("%02d%02d%02d") + ".txt");
	}

	inline string makeTimeHeader()
	{
		return string("[" + getTimeString("%02d:%02d:%02d:") + "]\t");
	}

	inline string getTimeString(const char* c)
	{
		auto tp = std::chrono::system_clock::now(); // tp is a C::system_clock::time_point
		auto dp = date::floor<date::days>(tp);  // dp is a day_point, which is a
												// type alias for a C::time_point
		auto time = date::make_time(std::chrono::duration_cast<std::chrono::milliseconds>(tp - dp));
		auto hour = (time.hours().count() + 9) % 24;
		auto minute = time.minutes().count();
		auto second = time.seconds().count();
		auto millisecond = time.subseconds().count();

		char buf[100];
		sprintf_s(buf, c, hour, minute, second);

		string format(c);
		size_t n = std::count(format.begin(), format.end(), ':');
		if (n == 3) {
			strcat_s(buf, to_string(millisecond).substr(0, 3).c_str());
		}
		else {

		}

		return string(buf);
	}
};