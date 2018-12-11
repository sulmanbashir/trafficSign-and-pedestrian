#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <string>

using namespace cv;

class pietonDetector
{
public:
  pietonDetector();
  ~pietonDetector();
  virtual int run();
  
  void setImage(Mat img)
  {
    _img = img;
  }
  std::vector<Rect>	getDetectedHumans()
  {
    return _detectedHumans;
  }
    
private:
  std::string		_cascadeName;
  CascadeClassifier	_classifier;
  bool			_classifierLoaded;
    
protected:
  Mat			_img;
  std::vector<Rect>	_detectedHumans;
};
