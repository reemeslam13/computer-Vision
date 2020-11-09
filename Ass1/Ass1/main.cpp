
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    
    //1st task point1
    Mat img1 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q1I1.png", IMREAD_COLOR);
    double contrast = 5.2;
    double brightness = 40;
    resize(img1, img1, cv::Size(), 0.75, 0.75);
    for (int y = 0; y < img1.cols; y++)
    {
        if (brightness > 0)
            brightness -= 0.5;
        if (contrast > 0)
            contrast -= 0.006;
        for (int x = 0; x < img1.rows; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                img1.at<Vec3b>(x, y)[c] =
                saturate_cast<uchar>((contrast*((img1.at<Vec3b>(x, y)[c]))) + brightness);
            }
        }
    }
    
    imshow("task 1.1", img1);
    
    //1st task point2
    Mat img2 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q1I2.jpg", IMREAD_COLOR);
    resize(img2, img2, cv::Size(), 0.75, 0.75);
    //cv::Mat out = cv::Mat::zeros(img2.size(), frame.type());
    img2(cv::Rect(150, 0, img2.cols - 150, img2.rows)).copyTo(img2(cv::Rect(0, 0, img2.cols - 150, img2.rows)));
    Mat dist2 = Mat::zeros(img2.size(), img2.type());
    flip(img2, dist2, 1);
    imshow("task 1.2", dist2);
    
    //1st task point 3
    Mat dist3;
    resize(dist2, dist3, Size(img1.cols, img1.rows));
    addWeighted(img1, 0.9, dist3, 0.2, 0.0, dist3);
    imshow("task 1.3", dist3);
    
    //2nd task part 1
    Mat img3 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q2I1.jpg", IMREAD_COLOR);
    Mat img4 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q2I2.jpg", IMREAD_COLOR);
    resize(img3, img3, Size(44, 70));
    resize(img4, img4, cv::Size(), 0.5, 0.5);
    img3.copyTo(img4(cv::Rect(610, 190, img3.cols, img3.rows)));
    imshow("task 2.1", img4);
    
    //2nd task part 2
    img3 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q2I1.jpg", IMREAD_COLOR);
    Mat img5 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q2I3.jpg", IMREAD_COLOR);
    
    Mat transformation = Mat::zeros(img3.rows, img3.cols, img3.type());
    
    Point2f src_affine[3];
    Point2f target_affine[3];
    
    src_affine[0] = Point2f(0, 0);
    src_affine[1] = Point2f(500, 0);
    src_affine[2] = Point2f(500, 685);
    
    target_affine[0] = Point2f(367, 92);
    target_affine[1] = Point2f(705, 127);
    target_affine[2] = Point2f(665, 560);
    
    transformation = getAffineTransform(src_affine, target_affine);
    warpAffine(img3, img5, transformation, img5.size(), 1, BORDER_TRANSPARENT);
    
    imshow("Task 2.2", img5);
    
    //3rd task
    Mat img6 = imread("/Users/reemeslam13/Downloads/MyProjects/CV/Assignments/Assignment1/Ass1/Q3I1.jpg", IMREAD_COLOR);
    
    Point2f src[4];
    Point2f target[4];
    
    Mat perspective = Mat::zeros(img3.rows, img3.cols, img3.type());
    
    src[0] = Point2f(0, 0);
    src[1] = Point2f(500,0);
    src[2] = Point2f(500, 685);
    src[3] = Point2f(0, 685);
    
    target[0] = Point2f(162, 35);
    target[1] = Point2f(469, 69);
    target[2] = Point2f(464, 353);
    target[3] = Point2f(157, 389);
    
    perspective = getPerspectiveTransform(src, target);
    warpPerspective(img3, img6, perspective, img6.size(),1,BORDER_TRANSPARENT);
    
    imshow("Task 3", img6);
    
    
    
    waitKey();
    return 0;
}
