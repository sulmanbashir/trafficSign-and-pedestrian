#include "../../Detection/Signal-panel/signal_panel.hpp"

/*void    drawEllipse(Mat *img, vector<Rect> sign)
{
    for (int i = 0; i < sign.size(); i++)
      {
       Point center(sign[i].x + sign[i].width/2, sign[i].y + sign[i].height/2 );
        
        ellipse(*img, center, Size(sign[i].width/2, sign[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        putText(*img, 
            "Panneau",
	    sign[i].tl(), // Coordinates
            cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
            1.0, // Scale. 2.0 = 2x bigger
            cv::Scalar(0,0,255), // Color
            1, // Thickness1
	    CV_AA); // Anti-alias
      }
}*/

void    find_circles_panel(Mat frame) 
{
    vector<Vec3f> circles;
    Mat grayframe;
    
    cvtColor(frame,grayframe,CV_BGR2GRAY);
    medianBlur(grayframe, grayframe, 5);
        
    HoughCircles(grayframe, circles, CV_HOUGH_GRADIENT, 1, grayframe.rows/16, 100, 30, 1, 17);

    for( size_t i = 0; i < circles.size(); i++ )
      {    
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        
        int radius = c[2];
        circle( frame, center, radius, Scalar(0,255, 128), 3, LINE_AA);
      }   
}