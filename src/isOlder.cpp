/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int IsValidDate(char *dob)
{

	if (dob[2] != '-' || dob[5] != '-') return -1;
	int day = 10 * (dob[0] - '0') + dob[1] - '0';
	int month = 10 * (dob[3] - '0') + dob[4] - '0';
	int year = 1000 * (dob[6] - '0') + 100 * (dob[7] - '0') + 10 * (dob[8] - '0') + dob[9] - '0';

	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//Check for leap year
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		daysInMonth[1] = 29;

	if (month>0 && month<13)
	{
		if (day > 0 && day <= daysInMonth[month - 1])
			return 1;
	}

	return -1;
}

int isOlder(char *dob1, char *dob2)
{
	int i;
	if (IsValidDate(dob1) == -1 || IsValidDate(dob2) == -1) return -1;

	for (i = 6; i <= 9; i++)
	{
		if (dob1[i] > dob2[i]) return 2;
		else if (dob1[i] < dob2[i]) return 1;
		else {}
	}

	for (i = 3; i <= 4; i++)
	{
		if (dob1[i] > dob2[i]) return 2;
		else if (dob1[i] < dob2[i]) return 1;
		else {}
	}

	for (i = 0; i <= 1; i++)
	{
		if (dob1[i] > dob2[i]) return 2;
		else if (dob1[i] < dob2[i]) return 1;
		else {}
	}

	return 0;
}
