#include "pieton_detection.hpp"

using namespace cv;
using namespace std;

pietonDetector::pietonDetector()
  :_cascadeName("Detection/cascade/haarcascade_fullbody.xml"), _classifierLoaded(false)
{
  this->_classifier.load(this->_cascadeName);
}

pietonDetector::~pietonDetector()
{
  
}

int     pietonDetector::run()
{
  Mat   originalImage;
  int   imcount = 0;

  resize(_img, _img, Size(800, 400));
  //_img = _img(Rect(0, 75, 639, 379));
  _img.copyTo(originalImage);
  cvtColor(_img, _img, CV_BGR2GRAY);
  equalizeHist(_img, _img);
  //_classifier.detectMultiScale(_img, _detectedHumans, 1.1, 5, 0, Size(0, 0), Size(1000, 1000));
  //_classifier.detectMultiScale(_img, _detectedHumans, 1.2, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(0, 0), Size(200, 200));
  
_classifier.detectMultiScale(_img, _detectedHumans, 1.1, 2, 0|1, Size(40, 70), Size(80, 300));

  return _detectedHumans.size();
}
