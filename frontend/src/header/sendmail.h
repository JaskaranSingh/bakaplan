/**
 *       \file       sendmail.h
 *
 *       \brief      Declaration of SendMail Class usinf jwSMTP
 *                   library
 *
 *       \version    0.6
 *       \date       Saturday 06 April 2013 07:46:27  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */
 

/**
 *  Include header.h and jwsmtp.h 
 */
#include "header.h"
#include "jwsmtp/jwsmtp.h"

using namespace jwsmtp;

/**
 *      \class  SendMail
 *      \brief  Class for sending mail to user for registeration
 */

class SendMail
{
    protected:

        string setSender,
               setSubject,
               setMessage,
               setServer,
               htmlMessage,
               url;
    public:
        /** Constructor */
        SendMail();
        
        /** Setting variables */
        void SetMailData();

        /** Setting message of mail */
        void SetHTMLMessage(string regKey);

        /** Function for sending mail to new user(registeration link) */
        void RegistrationMail(string setRecipient, string regKey);

        /** Desrtuctor */
        ~SendMail();
    
};
