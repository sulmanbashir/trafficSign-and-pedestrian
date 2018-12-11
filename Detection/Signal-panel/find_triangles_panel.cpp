#include "../../Detection/Signal-panel/signal_panel.hpp"


void find_triangles_panel(Mat& frame, Mat& grayframe){
    Mat canny_output, drawing;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    Canny(grayframe, canny_output, 100, 200, 3, false );      

    findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  

    drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    drawTriangles(frame, contours);
}

void drawTriangles(Mat& img, const vector< vector<Point> >& contours){
    vector<Point> approxTriangle;
    for(size_t i = 0; i < contours.size(); i++){
        approxPolyDP(contours[i], approxTriangle, arcLength(Mat(contours[i]), true)*0.24, true); //0.05
        if(approxTriangle.size() == 3){
            drawContours(img, contours, i, Scalar(243, 46, 16), 5); // fill GREEN
        }
    }
}