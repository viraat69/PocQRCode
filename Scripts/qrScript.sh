#! /bin/bash
# $0: qrScript.sh
# $1: qrString that needs to be embedded into the QRCode

# TODO : $2: png File location to be created at.
# TODO : $3: png file siz


# collect all the information from the client(callers) perspective.
qrString=""

# Default qrString that gets embedded into the QRCode
DEFAULT_QR_STRING="www.sciton.com"

# Default response code that gets send to caller client(in this case UI Application)
DEFAULT_QR_STRING_RESPONSE_CODE=105

# Check for input agrument from the script invocation
if [[ $1 ]]; then
    qrString=$1
    # Change PWD, Since The shell script is invoked programatically, execution should be in contextual.
    cd /application/src/QRPackage/bin/

    # execute the QRCode generated binary by passing the collected arguments from the script invocations.
    RESPONSE_FROM_BINARY=$(/application/src/QRPackage/bin/scitonQRCode --qrStr $qrString 2>&1)

    # Change back to the previous the directory in context to the time of invocation.
    cd -
else
    qrString=$DEFAULT_QR_STRING
    # Change PWD, Since The shell script is invoked programatically, execution should be in contextual.
    cd /application/src/QRPackage/bin/

    # execute the QRCode generated binary by passing the collected arguments from the script invocations.
    RESPONSE_FROM_BINARY=$(/application/src/QRPackage/bin/scitonQRCode --qrStr $qrString 2>&1)
                           /application/src/QRPackage/bin
    # Change back to the previous the directory in context to the time of invocation.
    cd -

    RESPONSE_FROM_BINARY=$DEFAULT_QR_STRING_RESPONSE_CODE
fi

echo -n $RESPONSE_FROM_BINARY
