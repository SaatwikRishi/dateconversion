#include <iostream>
#include <string>
using namespace std;

int main() 
{
	const unsigned int VDI1 = 4;
	const unsigned int VDI2 = 7;
	const unsigned int VALID_D_LENGTH = 10;
	const unsigned int MIN_VALID_DAY_NUM = 1;
	string date, year, month, day, monthName;
	unsigned int dashIndex1, dashIndex2, invalidCharIndex, dateLength;
	unsigned int yearNum, dayNum, monthNum, maxValidDayNum = 31;
	bool dateValid = true;
	// Get a date from the user
	cout << "Enter date in YYYY-MM-DD format: ";
	getline(cin, date);
	// Check whether the input date has the correct format
	dashIndex1 = date.find("-");
	dashIndex2 = date.find("-", dashIndex1 + 1);
	invalidCharIndex = date.find_first_not_of("0123456789-");
	dateLength = date.size();

	if ((dashIndex1 == VDI1) &&
		(dashIndex2 == VDI2) &&
		(invalidCharIndex == string::npos) &&
		(dateLength == VALID_D_LENGTH)) {
		// Extract the year, month and day from the input date
		year = date.substr(0, dashIndex1);
		month = date.substr(dashIndex1 + 1, dashIndex2 - dashIndex1 - 1);
		day = date.substr(dashIndex2, dateLength - dashIndex2 - 1);
		// Convert the year, month and day to integers
		yearNum = stoi(year);
		monthNum = stoi(month);
		dayNum = stoi(day);
		// Determine the month name
		switch (monthNum) {
		case 1:
			monthName = "January";
			maxValidDayNum = 31;
			break;
		case 2:
			monthName = "February";
			maxValidDayNum = 29;
			break;
		case 3:
			monthName = "March";
			maxValidDayNum = 31;
			break;
		case 4:
			monthName = "April";
			maxValidDayNum = 30;
			break;
		case 5:
			monthName = "May";
			maxValidDayNum = 31;
			break;
		case 6:
			monthName = "June";
			maxValidDayNum = 30;
			break;
		case 7:
			monthName = "July";
			maxValidDayNum = 31;
			break;
		case 8:
			monthName = "August";
			maxValidDayNum = 31;
		case 9:
			monthName = "September";
			maxValidDayNum = 30;
			break;
		case 10:
			monthName = "October";
			maxValidDayNum = 31;
			break;
		case 11:
			monthName = "November";
			maxValidDayNum = 30;
			break;
		case 12:
			monthName = "December";
			maxValidDayNum = 31;
			break;
		default:
			dateValid = false;
		}
	
		if ((dayNum < MIN_VALID_DAY_NUM) && (dayNum > maxValidDayNum)) {
			dateValid = false;
		}
	}
	else 
	{
		dateValid = false;
	}
	// Output the date in expanded format
	if (dateValid) 
	{
		cout << monthName << " " << dayNum << ", " << year << endl;
	}
	else {
		cout << "Invalid date " << endl;
	}
	return 0;
}