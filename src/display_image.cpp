#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
	std::cout << "usage: display_image <Image_Path>" << std::endl;
	return -1;
    }

    cv::Mat image;
    image = cv::imread( argv[1], 1 );
    if ( !image.data ) {
	std::cout << "No Image Data" << std::endl;
	return -1;
    }

    cv::imshow(argv[1], image);

    cv::waitKey(0);

    return 0;
}
