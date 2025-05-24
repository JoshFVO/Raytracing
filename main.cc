#include "color.h"
#include "vec3.h"

int main() {

    // Rendered image set up

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the height based on the aspect ratio, ensure it's at least 1
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Viewport widths less than one are ok since they are real valued
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / double(image_height));

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render 

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
           auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
           write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.           \n";
}