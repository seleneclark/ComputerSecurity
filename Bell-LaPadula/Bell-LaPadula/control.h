/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/

// you may need to put something here...


#pragma once

#include <string>
#include <map>

enum Control {
    PUBLIC,
    CONFIDENTIAL,
    PRIVILEGED,
    SECRET
};

bool securityControlRead(Control assetControl, Control subjectControl);

bool securityControlWrite(Control assetControl, Control subjectControl);

Control convertToControl(std::string controlString);
