#include <iostream>
#include <fstream>
#include "libs/Qr-To-Png/QrToPng.h"
#include "libs/CLI/CLI.hpp"
#include "QrReturnCodes.h"

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

    if (genQrImage.writeToPNG()){
        return QR_GENERATION_SUCESS_CODE;
    }
    else {
        return QR_GENERATION_FAILURE_CODE;
    }
}


int main(int argc, char **argv)
{

    CLI::App app("QRCode Generator Console Application");
    app.validate_positionals(true);

    std::string qrCodeString;
    CLI::Option *qropt = app.add_option("--qrStr", qrCodeString, "Text that needs to be embedded into QR Code Image");
    (void)qropt;
    CLI11_PARSE(app, argc, argv);

    // Return code that specified application usage error.
    if(qrCodeString.empty()){
        std::cout<<QR_GENERATION_APPLICATION_USAGE_ERROR_CODE<<std::endl;
    }
    else{
        std::cout<< qrGenerator(qrCodeString)<<std::endl;
    }

    return 0;
}



