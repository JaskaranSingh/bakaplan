/**
 *       \file       datesheet.cc
 *
 *       \brief      Definition of member functions of Datesheet class
 *
 *       \version    0.6
 *       \date       Sunday 31 March 2013 09:39:11  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include datesheet.h file 
 */
#include "header/datesheet.h"

/**
 *      \class  DataSheet
 *      \fn     DataSheet :: DateSheet()
 *      \brief  Constructor
 */

DateSheet :: DateSheet()
{
    // Constructor
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: AddRollNoWithDateSheet()
 *      \brief  Adding roll no to with exam code in datesheet
 */

void DateSheet :: AddRollNoWithDateSheet()
{
    dateSheetRNoSize.resize(totalDays);
    dateSheetRNo.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        dateSheetRNoSize[i].resize(totalExams[i]);
        dateSheetRNo[i].resize(totalExams[i]);
/*        for(j = 0; j < totalExams[i]; j++)
        {
            dateSheetRNo[i][j].resize(0);
        }*/
    }
  
    for(i = 0; i < totalDays; i++)
    { 
        for(j = 0; j < totalExams[i]; j++)
        {
            dateSheetRNoSize[i][j] = 0;
        }
     }
   

    for(i = 0; i < totalDays; i++)
    { 
        for(j = 0; j < totalExams[i]; j++)
        {
            for(k = 0; k < totalClasses; k++)
            {
                for(l = 0; l < totalSubjects[k]; l++)
                {
                    if(examCode[i][j] == subjectCode[k][l])
                    {
                        dateSheetRNoSize[i][j] += rollNoSize[k];

                        int size = dateSheetRNo[i][j].size();

                        dateSheetRNo[i][j].resize(dateSheetRNoSize[i][j]);
                        for(m = 0; m < rollNoSize[k]; m++)
                        {
                            dateSheetRNo[i][j][size + m] = prefixRollNo[k][m];
                        }
                    }
                }
            }
        }
    }
}

/**
 *      \class  DataSheet
 *      \fn     DataSheet :: WriteDateSheetWithRollNo(string projectID)
 *      \brief  Writing Date sheet to file with roll nos.
 *              datesheet.out will be used for generating seating plan
 *      \param  projectID ProjectID of use's project
 */

void DateSheet :: WriteDateSheet(string projectID)
{
    temp = FileName(DATESHEET, projectID, 0);

    outFile.open(temp.c_str());

    for(i = 0; i < totalDays; i++)
    {
        outFile << totalDays << endl
             << date[i] << endl
             << totalExams[i] << endl;

        for(j = 0; j < totalExams[i]; j++)
        {
            outFile << examCode[i][j] << endl
                    << dateSheetRNoSize[i][j] << endl;

            for(k = 0; k < dateSheetRNoSize[i][j]; k++)
            {
                outFile << dateSheetRNo[i][j][k] << endl;
            }
        }
    }

    outFile.close();
}

/**
 *      \class  DataSheet
 *      \fn     DataSheet :: Main(string pID)
 *      \brief  Main method to call func. in sequence
 *      \param  pID project ID
 */

void DateSheet :: Main(string pID)
{
    projectID = pID;

    ArrangeRollNo::Main(projectID);

    ReadClassDetail(projectID);
    ReadDateSheet(projectID);
    AddRollNoWithDateSheet(); 
    WriteDateSheet(projectID);
}

/**
 *      \class  DataSheet
 *      \fn     DataSheet :: ~DateSheet()
 *      \brief  Destructor
 */

DateSheet :: ~DateSheet()
{
    // Destructor
}
