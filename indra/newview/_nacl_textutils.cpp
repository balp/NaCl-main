// (C) 2010 Balp Allen
// Using LGPL, or any other OSI Licence

#include "llviewerprecompiledheaders.h"
#include "llviewercontrol.h"

#include <string>

void AutoCloseOOC(std::string &utf8text)
{
	std::string OOCOpen = gSavedSettings.getString("_nacl_OOCOpenString");
	std::string OOCClose = gSavedSettings.getString("_nacl_OOCCloseString");
	LL_DEBUGS("BalpText") << "AutoCloseOOC(" << utf8text << ")" << LL_ENDL;
	if (gSavedSettings.getBOOL("_nacl_AutoCloseOOC"))
	{
		if (utf8text.find(OOCOpen) != std::string::npos && utf8text.find(OOCClose) == std::string::npos )
		{
			if(' ' == utf8text[utf8text.length() - 1])
			{
				utf8text += OOCClose;
			}
			else
			{
				utf8text += " " + OOCClose;
			}
		}
		LL_DEBUGS("BalpText") << "AutoCloseOOC(" << utf8text << "): after"
			<< LL_ENDL;

	}
}

void ExpandMUPose(std::string &utf8text)
{
	LL_DEBUGS("BalpText") << "ExpandMUPose(" << utf8text << ")" << LL_ENDL;
	if (gSavedSettings.getBOOL("_nacl_ExpandMUPose"))
	{
		if(0 == utf8text.compare(0,2,":'")) {
			utf8text.replace(0,1,"/me");
		} else if(0 == utf8text.compare(0,2,": ")) {
			utf8text.replace(0,1,"/me");
		}
		LL_DEBUGS("BalpText") << "ExpandMUPose: to " << utf8text << LL_ENDL;
	}
}
