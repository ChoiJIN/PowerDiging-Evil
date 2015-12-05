#include "Cinematic.h"
#include "GS.h"


Cinematic::Cinematic(){
}

Cinematic::~Cinematic(){}

bool Cinematic::readFile(const char* fileName) {
	FILE *fp = fopen(fileName, "r");
	if (!fp) return false;

	char buffer[1024];
	while (fscanf(fp, "%s", buffer) != EOF) {
		bool go_eol = true;

		cineCoordinate v;
		fscanf(fp, "%f %f %f %f", &v.x, &v.z, &v.yaw, &v.pitch);
		vertexes.push_back(v);

		if (go_eol) fgets(buffer, 1024, fp);
	}
	fclose(fp);
	return true;
}

bool Cinematic::Load(const char *cineFile)
{
	_splitpath(cineFile, NULL, _work_path, NULL, NULL);

	if (cineFile && *cineFile) {
		readFile(cineFile);
	}
	return true;
}

void Cinematic::returnVertexes(int i) {
	posX = vertexes.at(i).x;
	posZ = vertexes.at(i).z;
	yaw = vertexes.at(i).yaw;
	pitch = vertexes.at(i).pitch;
	
	
}

int Cinematic::returnVectorSize() {
	return vertexes.size();
}

float Cinematic::getposX() {
	return posX;
}

float Cinematic::getposZ() {
	return posZ;
}
float Cinematic::getYaw()
{
	return yaw;
}
float Cinematic::getPitch()
{
	return pitch;
}