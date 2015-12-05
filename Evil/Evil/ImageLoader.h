#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GS.h"

#include <opencv2/highgui/highgui.hpp>\

using namespace std;
using namespace cv;

class ImageLoader {
private:
	static map<string, Mat> imgMap;
	static map<string, GLuint> textureIdMap;

	static vector<string> &split(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	static vector<string> split(const string &s, char delim) {
		vector<string> elems;
		split(s, delim, elems);
		return elems;
	}

	static unsigned char* loadImage(string file)
	{
		Mat img = imread(file);
		if (img.empty()) {
			GS::debug.log(file + "이 존재하지 않습니다.");
			exit(1);
		}
		string filename = *(split(file, '/').end() - 1);	 // name with ext
		imgMap.insert(pair<string, Mat>(filename, img));

		return imgMap.at(filename).data;
	}

public:

	static int getTextureWidth(string name)
	{
		return imgMap.at(name).cols;
	}

	static int getTextureHeight(string name)
	{
		return imgMap.at(name).rows;
	}

	static int getTextureChannel(string name)
	{
		return imgMap.at(name).channels();
	}

	static void loadTexture(string filename)
	{
		GLuint tid;
		glGenTextures(1, &tid);

		unsigned char* data = ImageLoader::loadImage("Textures/" + filename);
		int width = ImageLoader::getTextureWidth(filename);
		int height = ImageLoader::getTextureHeight(filename);
		int channel = ImageLoader::getTextureChannel(filename);

		glBindTexture(GL_TEXTURE_2D, tid);

		if (channel == 3) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
		}
		else if (channel == 4) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		textureIdMap.insert(pair<string, GLuint>(filename, tid));

		glBindTexture(GL_TEXTURE_2D, 0); // unbind
	}

	static GLuint getTextureId(string filename)
	{
		return textureIdMap.at(filename);
	}

};
