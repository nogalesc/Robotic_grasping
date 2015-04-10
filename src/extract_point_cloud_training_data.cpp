#include "common.h"
#include "feature.h"
#include "extractTrainingData.h"
#include "calcRectIntersection.h"
#include <fstream>

using namespace std;

char *dirPrefix = ""; //"/misc/projects/jamming_IROS11/"; //"/misc/projects/grasping_data/11-6/";

int main(int argc, char *argv[])
{
	if (argc!=3)
	{
		printf("Usage: %s folder numFiles\n", argv[0]);
		return 0;
	}
	
  int numFiles = atoi(argv[2]);

  string dir = string(dirPrefix) + argv[1] + "/";
  vector<string> files = vector<string>();
  getdir(dir,files);

  ofstream fout((dir + "features").c_str());
	
  for (int nFile = 0; nFile < numFiles; nFile++){ //files.size(); nFile++) {
  // for (int nFile = 1; nFile < 2; nFile++) {
		vector<Rect> rects;
		vector<Rect> posRects;
		/*===========changed by Yun===================*/
		int fileNum = atoi(files[2*nFile].substr(3,4).c_str());

		loadRects(rects,(dir+"pcd"+files[2*nFile].substr(3,4) + "cpos.txt").c_str(),(dir+ "pcd"+ files[2*nFile].substr(3,4)+"cneg.txt").c_str());

		loadRects(posRects,(dir+"pcd" + files[2*nFile].substr(3,4)+"cpos.txt").c_str());

		cout << nFile << "\t"<< files[2*nFile].substr(3,4) << ", #rect= " << rects.size() << endl;
		vector< vector<float> > all_fv = extractTrainingData(dir, fileNum, rects);
		cout<<"all_fv size: "<<all_fv.size()<<endl;
		double numTotal = 0, precision = 0;

		for (unsigned int k=0;k<all_fv.size();k++) {		
			fout << (rects[k].isPos?"+1":"-1") << " qid:" << (fileNum+1);
			for (unsigned int i=0;i<all_fv[k].size();i++) {
				if (i>0 && all_fv[k][i] == 0) continue;
				fout << " " << (i+1) << ":" << all_fv[k][i];
			}
			fout<<endl;
		}
  }
  return 0;
  }
