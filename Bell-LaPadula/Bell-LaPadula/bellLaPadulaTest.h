/***********************************************************************
 * COMPONENT:
 *    BELL-LAPADULATEST
 * Author:
 *    Selene Clark
 * Summary:
 *    This class tests the program
 ************************************************************************/

#ifndef bellLaPadulaTest_h
#define bellLaPadulaTest_h

#include <stdio.h>
#include "messages.h" // to interact with the collection of messages
#include "interact.h" // the interaction code
#include <string>     // for convenience
#include <iostream>   // standard input and output

using namespace std;

class BellLaPadulaTest
{
public:
   BellLaPadulaTest(Interact interact, Messages & messages, string userName)
   {
	  Messages * testMessages = interact.pMessages;
	  
	  getCorrectMessageList(userName, messages);
   }
   
   void getCorrectMessageList(string userName, Messages & messages)
   {
	  for (list <Message> :: const_iterator it = messages.messages.begin();
		   it != messages.messages.end();
		   ++it)
	  {
		 
//		 string printTextForKicks = it->text;
		 int printTextForKicks = it->getID();
		 cout << printTextForKicks << "  ";
	  }
	  cout << "\n";
   }
   
   
   
   
};

#endif /* bell_LaPadulaTest_h */
