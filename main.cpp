#include <iostream>
#include <fstream>
#include "libs/Qr-To-Png/QrToPng.h"
#include "libs/CLI/CLI.hpp"

using namespace std;
using namespace CLI;


int qrGenerator(const std::string inputQrText)
{
    std::string qrText = inputQrText;

    //TODO: Create API to Modify Image name is hardcoded as per requirement
    std::string qrImageFile = "generatedQrImage.png";

    int imgSize = 300;
    int minModulePixelSize = 3;

    auto genQrImage = QrToPng(qrImageFile, imgSize, minModulePixelSize, qrText, true, qrcodegen::QrCode::Ecc::MEDIUM);

    if (genQrImage.writeToPNG())
        return 100;
    //std::cout << "100" << std::endl;
    else
        return 101;
    //std::cerr << "101" << std::endl;
}


int main(int argc, char **argv)
{

    CLI::App app("QRCode Generator Console Application");
    app.validate_positionals(true);

    std::string qrCodeString;
    CLI::Option *qropt = app.add_option("--qrStr", qrCodeString, "Text that needs to be embedded into QR Code Image");
    CLI11_PARSE(app, argc, argv);

    // Return code that specified application usage error.
    if(qrCodeString.empty()){
        std::cout<<103<<std::endl;
    }
    else{
        std::cout<< qrGenerator(qrCodeString)<<std::endl;
    }

    return 0;
}


//std::cout << "Working on file: " << qrCodeString << ", direct count: " << app.count("--file")
//          << ", opt count: " << opt->count() << std::endl;
//std::cout << "Working on count: " << count << ", direct count: " << app.count("--count")
//          << ", opt count: " << copt->count() << std::endl;
//std::cout << "Received flag: " << v << " (" << flag->count() << ") times\n";
//std::cout << "Some value: " << value << std::endl;


//    //***********************************************************************************
//    //Set of Inputs that the program accepts from commandline

//    std::string qrText = "https://www.sciton.com";
//    std::string fileName = "example1.png";

//    int imgSize = 300;
//    int minModulePixelSize = 3;



//    //***********************************************************************************

//    auto exampleQrPng1 = QrToPng(fileName, imgSize, minModulePixelSize, qrText, true, qrcodegen::QrCode::Ecc::MEDIUM);

// Process this information to log file if needed.
//    std::cout << "Writing Example QR code 1 (normal) to " << fileName << " with text: '" << qrText << "', size: " <<
//              imgSize << "x" << imgSize << ", qr module pixel size: " << minModulePixelSize << ". " << std::endl;

//    if (exampleQrPng1.writeToPNG())
//        std::cout << "100" << std::endl;
//    else
//        std::cerr << "101" << std::endl;
