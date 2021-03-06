/*
 * SaliencyMain.cpp
 *
 */
#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "SaliencyDetector.h"
#include "EdgeDetector.h"

using namespace std;

int main(int argc, char *argv[]) {
	cv::Mat1f img = cv::imread("bike.jpeg", CV_LOAD_IMAGE_GRAYSCALE);

	if (img.empty()) {
		cout << "No image loaded. Exiting.\n";
		return (EXIT_FAILURE);
	}

	sal::ImageSaliencyDetector detector(img);
	detector.setSamplingPercentage(0.10f);

	cout << "Computing...\n";
	detector.compute();

	cout << "Post-processing...\n";
	detector.performPostProcessing();

	cv::imwrite("SaliencyTestOutput.jpg", detector.getSaliencyMap());

	cout << "Done\n";

	std::cin.get();
	std::cin.get();

	return 0;
}



