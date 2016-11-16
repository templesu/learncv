#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

void CallBackFunc(int event, int x, int y, int flags, void* ptr)
{
	cv::Point *mouseP = (cv::Point*)ptr;

	if (event == cv::EVENT_LBUTTONDOWN)
	{
		mouseP->x = x;
		mouseP->y = y;
		std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if (event == cv::EVENT_RBUTTONDOWN)
	{
		//std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if (event == cv::EVENT_MBUTTONDOWN)
	{
		//std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if (event == cv::EVENT_MOUSEMOVE)
	{
		//std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;

	}

}

int main(int argc, char *argv[])
{
	std::cout << "Learn OpenCV" << std::endl;
	std::string imageName = "sample00001.jpg";
	if (argc > 1)
		imageName = argv[1];

	cv::Mat inputImage;
	inputImage = cv::imread(imageName.c_str(), cv::IMREAD_GRAYSCALE);

	if (inputImage.empty())
		std::cout << "Could not open or find the image: " << imageName << std::endl;
	
	//cv::Scalar intensity = inputImage.at<uchar>(0, 0);
	//std::cout << "Scalar: " << intensity << std::endl;
	cv::Vec3b intensity = inputImage.at<cv::Vec3b>(0, 0);
	uchar blue = intensity.val[0];
	uchar green = intensity.val[1];
	uchar red = intensity.val[2];
	std::cout << "Color: " << int(blue) << int(green) << int(red) << std::endl;
	std::cout << inputImage.rows << inputImage.cols << std::endl;

	for (int i=0; i<inputImage.rows; i++)
		for (int j = 0; j < inputImage.cols; j++)
		{
			cv::Scalar curI = inputImage.at<uchar>(i, j);
			int modifyI = int(((int)curI[0] + 1) / 32);
			//std::cout << modifyI << std::endl;
			modifyI = std::max(modifyI * 32 - 1, 0);
			inputImage.at<uchar>(i, j) = (uchar)modifyI;
			cv::Scalar afterI = inputImage.at<uchar>(i, j);
			//std::cout << curI << ": " << afterI << std::endl;
		}

	std::cout << inputImage.type() << std::endl;
	std::cout << "Image Depth: " << inputImage.depth() << inputImage.type() << std::endl;
	//cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Display window", cv::WINDOW_KEEPRATIO);

	cv::Point mouseP;
	cv::imshow("Display window", inputImage);
	cv::setMouseCallback("Display window", CallBackFunc, &mouseP);

	cv::waitKey(0);
	std::cout << "Mouse: " << mouseP.x << " : " << mouseP.y << std::endl;

	cv::imwrite("test.jpg", inputImage);
	
	return 1;
}