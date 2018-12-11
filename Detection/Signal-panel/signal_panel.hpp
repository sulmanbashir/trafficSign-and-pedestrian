#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class signalPanel 
{
public:
  signalPanel();
  ~signalPanel();
  virtual int run();
  
  void setImage(Mat img)
  {
    _img = img;
  }
  std::vector<Rect>	getDetectedSignalPanel()
  {
    return _detectedSignalPanel;
  }
    
private:
  std::string		_cascadeName;
  CascadeClassifier	_classifier;
  bool			    _classifierLoaded;
    
protected:
  Mat			_img;
  std::vector<Rect>	_detectedSignalPanel;
};

void    find_triangles_panel(Mat&, Mat&);
void    drawTriangles(Mat&, const vector< vector<Point> >&);
void    find_circles_panel(Mat frame); 
