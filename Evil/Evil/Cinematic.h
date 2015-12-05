#pragma once
#include <vector>
using namespace std;
struct cineCoordinate
{
	float x, z, yaw, pitch;
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
	float getYaw();
	float getPitch();
	

private:
	float posX;
	float posZ;
	float yaw;
	float pitch;
	
	vector<cineCoordinate> vertexes;

	char _work_path[_MAX_DIR];
};