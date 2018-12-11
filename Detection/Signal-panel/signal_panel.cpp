#include "signal_panel.hpp"

using namespace cv;
using namespace std;

signalPanel::signalPanel()
  :_cascadeName("Detection/cascade/sign-panel.xml"), _classifierLoaded(false)
{
  this->_classifier.load(this->_cascadeName);
}

signalPanel::~signalPanel()
{
  
}

int     signalPanel::run()
{
  Mat   originalImage;
  int   imcount = 0;

  resize(_img, _img, Size(800, 600));
  _img.copyTo(originalImage);
  equalizeHist(_img, _img);
    _classifier.detectMultiScale(_img, _detectedSignalPanel, 1.4, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(20, 20), Size(800, 800));

  return _detectedSignalPanel.size();
}
