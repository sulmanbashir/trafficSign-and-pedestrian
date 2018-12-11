#include <iostream>
#include "Detection/Pieton/pieton_detection.hpp"
#include "Detection/Signal-panel/signal_panel.hpp"


void    find_circles_panel(Mat);
void    find_triangles_panel(Mat&, Mat&);
void drawTriangles(Mat&, const vector< vector<Point> >&);

bool HAS_VIDEO_SERVER_ = true;

void    drawRects(Mat *img, vector<Rect> pietons)
{
  for (int i = 0; i < pietons.size(); i++)
    {
      rectangle(*img, pietons[i].tl(), pietons[i].br(), Scalar(0, 0, 255), 2, 5);
      putText(*img, 
            "DANGER : Pieton",
	    pietons[i].tl(), // Coordinates
            cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
            1.0, // Scale. 2.0 = 2x bigger
            cv::Scalar(0,0,255), // Color
            1, // Thickness1
	    CV_AA); // Anti-alias
    }
}

void    loop(pietonDetector *detector, char *vid)
{
    VideoCapture cap(vid);
    namedWindow("Detection des pietons et des panneaux", 1);
    
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        // return -1;
    }
     
    while(1)
     {
        Mat img;
        Mat grayframe;
        cap >> img;

        cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
        resize(img, img, Size(800, 400));
        if (img.empty())
            break;
        detector->setImage(img);
        detector->run();
    
        if (HAS_VIDEO_SERVER_)
          {
            drawRects(&img, detector->getDetectedHumans());
            cvtColor(img, grayframe,CV_RGB2GRAY);
            find_triangles_panel(img, grayframe);
            find_circles_panel(img);
            imshow("Detection des pietons et des panneaux ronds & triangles", img);
            if (waitKey(1) == 27)
                break;
          }
      }
    cap.release();
    destroyAllWindows();
}

int main(int ac, char **av)
{
    pietonDetector  pietonDetected;

    if (av[2] && strcmp(av[2], "noscreen") == 0)
        HAS_VIDEO_SERVER_ = false;
    loop(&pietonDetected, av[1]);
  
    return 0;
}
