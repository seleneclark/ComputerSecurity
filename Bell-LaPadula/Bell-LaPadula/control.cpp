#include "control.h"


bool securityControlWrite(Control assetControl, Control subjectControl) {
    return subjectControl <= assetControl;
}

bool securityControlRead(Control assetControl, Control subjectControl) {
    return subjectControl >= assetControl;
}

Control convertToControl(std::string controlString) {
    if(controlString == "Confidential") return CONFIDENTIAL;
    else if (controlString == "Secret") return SECRET;
    else if (controlString == "Public") return PUBLIC;
	else if (controlString == "Privileged") return PRIVILEGED;
}
