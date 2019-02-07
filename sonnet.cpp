#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "vector.h"
#include "strlib.h"
#include "error.h"

int main()
{
	Vector<std::string> sonnets;
	std::string fileName = " ";

	// Asks for file name
	std::cout << "Where is Shakespeare's stuff?" << std::endl;
	std::getline(std::cin, fileName);

	// Looks and checks file
	std::ifstream spearFile(fileName);
	if (!spearFile.is_open())
	{
		error("file not found");
	}

	// Examines file via lines
	while (!spearFile.eof())
	{
		std::string spearLine;
		std::getline(spearFile, spearLine);

		// Cout the sonnets

		if (spearLine.find("THE SONNETS") != std::string::npos)
		{
			// Sonnet acquired
			std::cout << "We found them!" << std::endl;

			// Goes through every line of sonnets

			while (!spearFile.eof())
			{
				std::string sonnet;
				std::getline(spearFile, sonnet);

				// Check for the last line
				if (sonnet.find("THE END") != std::string::npos)
				{
					std::cout << "Found the end of sonnets!" << std::endl;
					break;
				}
				else if (stringIsInteger(sonnet))
				{
					// Look for end of sonnet

					// Stream to store whole sonnet
					std::ostringstream sonnetText;
					for (int i = 0; i < 14; i++)
					{
						std::string temp;
						std::getline(spearFile, temp);

						//store the text
						sonnetText << temp << std::endl;
					}

					sonnetList.add(sonnetText.str());
				}
			}
		} // Finished looking for sonnets
	} //end of while (!spearFile.eof())
	std::cout << "Read " << sonnetList.size() << " sonnets" << std::endl;

	// Loop to take user info
	while (true)
	{
		std::string userInput;

		// Get user input
		std::cout << "Sonnet number: ";
		std::getline(std::cin, userInput);

		if (stringIsInteger(userInput))
		{
			// Process user input
			int userNum = stringToInteger(userInput);

			if (userNum <= 0)
			{
				// End
				return 0;
			}
			else if (userNum > sonnetList.size())
			{
				std::cout << "No such Sonnet!" << std::endl;
			}
			else
			{
				// Gives sonnet
				std::cout << "Sonnet #" << userNum << std::endl;
				std::cout << sonnetList[userNum - 1] << std::endl;

			}
		}
		else
		{
			std::cout << "Bad user!" << std::endl;
		}
	}
	return 0;
}
