#pragma once
#include <vector>
#include <fstream>

using namespace std;
struct cineCoordinate
{
	float x, z, lookx, looky,lookz;
};


class Cinematic {
public:
	Cinematic();
	~Cinematic();

	bool readFile(const char* fileName);
	bool Load(const char *cineFile);
	void returnVertexes(int i);
	int returnVectorSize();

	float getposX();
	float getposZ();
	float getlookx();
	float getlooky();
	float getlookz();
	

private:
	float posX;
	float posZ;
	float lookx;
	float looky;
	float lookz;
	
	
	vector<cineCoordinate> vertexes;

	char _work_path[_MAX_DIR];
};