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


#include <map>
#include <string>



enum 
    Control {
    SECRET,
	PUBLIC,
    PRIVILEGED,
	CONFIDENTIAL
    
};


bool securityControlWrite(Control assetControl, Control subjectControl);

bool securityControlRead(Control assetControl, Control subjectControl);

Control convertToControl(std::string controlString);
