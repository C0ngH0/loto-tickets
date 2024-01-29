//Name: Cong Ho
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	unsigned int ubWin, ubPow, powerball, matchingNum, matchingPow, num1, num2, num3, num4, num5;
	std::vector <unsigned int> winNumarray;
	std::vector <unsigned int> notWinarray;
	int i = 0;

	std::cin >> ubWin >> ubPow;
	while (ubWin > 69 || ubPow > 26 || ubWin == 0 || ubPow == 0)
	{
		std::cout << "Plese enter a valid value.\nThe upper bound of the 5 winner numbers should be 1-69\nThe upper bound of the power ball number should be 1-26\n";
		std::cin >> ubWin >> ubPow;
	}
	std::cin >> num1 >> num2 >> num3 >> num4 >> num5 >> powerball;
	winNumarray.push_back(num1);
	winNumarray.push_back(num2);
	winNumarray.push_back(num3);
	winNumarray.push_back(num4);
	winNumarray.push_back(num5);
	std::sort(winNumarray.begin(),winNumarray.end());

	std::cin >> matchingNum >> matchingPow;
	while (matchingNum > 5 || matchingPow > 1)
	{
		std::cout << "Plese enter a valid value.\nThe matching of the 5 winner numbers should be 0-5\nThe matching of the power ball number should be 0-1\n";
		std::cin >> matchingNum >> matchingPow;
	}
	std::cout << std::endl << std::endl;

	//make a new array for not winning num
	for (unsigned int index = 1; index <= ubWin; index++)
	{
		notWinarray.push_back(index);
	}

	//for removing winning num in the not winning num array
	std::vector<unsigned int> resultNotWinarray; // Create a new vector to store elements to keep

	for (unsigned index = 0; index < notWinarray.size(); index++)
	{
		bool shouldKeep = true; // Assume we should keep the element

		for (int indie = 0; indie < winNumarray.size(); indie++)
		{
			if (notWinarray.at(index) == winNumarray.at(indie))
			{
				shouldKeep = false; // If it matches, don't keep the element
				break; // No need to check further
			}
		}

		if (shouldKeep)
		{
			resultNotWinarray.push_back(notWinarray.at(index)); // Add to the new vector
		}
	}

	notWinarray = resultNotWinarray; // Update notWinarray with the new vector

	//to count number of lines
	int count = 0;
	if (matchingNum == 0)
	{
		for (int a = 0; resultNotWinarray.size(); a++) //1st num
		{
			for (int b = a + 1; b < resultNotWinarray.size(); b++) //2nd num
			{
				for (int c = b + 1; c < resultNotWinarray.size(); c++) //3rd num
				{
					for (int d = c + 1; d < resultNotWinarray.size(); d++) //4th num
					{
						for (int e = d + 1; e < resultNotWinarray.size(); e++) //5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << resultNotWinarray.at(a) << " " << resultNotWinarray.at(b) << " " << resultNotWinarray.at(c)
											<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << resultNotWinarray.at(a) << " " << resultNotWinarray.at(b) << " " << resultNotWinarray.at(c)
									<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (matchingNum == 1)
	{
		for (int a = 0; a < 5; a++) //1st num
		{
			for (int b = 0; b < resultNotWinarray.size(); b++) //2nd num
			{
				for (int c = b + 1; c < resultNotWinarray.size(); c++) //3rd num
				{
					for (int d = c + 1; d < resultNotWinarray.size(); d++) //4th num
					{
						for (int e = d + 1; e < resultNotWinarray.size(); e++) //5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << winNumarray.at(a) << " " << resultNotWinarray.at(b) << " " << resultNotWinarray.at(c)
											<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << winNumarray.at(a) << " " << resultNotWinarray.at(b) << " " << resultNotWinarray.at(c)
									<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (matchingNum == 2) 
	{
		for (int a = 0; a < 4; a++) //1st num
		{
			for (int b = a + 1; b < 5; b++) //2nd num
			{
				for (int c = 0; c < resultNotWinarray.size(); c++) //3rd num
				{
					for (int d = c + 1; d < resultNotWinarray.size(); d++) //4th num
					{
						for (int e = d + 1; e < resultNotWinarray.size(); e++) //5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << resultNotWinarray.at(c)
											<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << resultNotWinarray.at(c)
									<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (matchingNum == 3)
	{
		for (int a = 0; a < 3; a++) //for 1st num
		{
			for (int b = a + 1; b < 4; b++) //for 2nd num
			{
				for (int c = b + 1; c < 5; c++) //for 3rd num
				{
					for (int d = 0; d < resultNotWinarray.size(); d++) //for 4th num
					{
						for (int e = d + 1; e < resultNotWinarray.size(); e++) //for 5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
											<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
									<< " " << resultNotWinarray.at(d) << " " << resultNotWinarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (matchingNum == 4)
	{
		for (int a = 0; a < 2; a++) //for 1st num
		{
			for (int b = a + 1; b < 3; b++) //for 2nd num
			{
				for (int c = b + 1; c < 4; c++) //for 3rd num
				{
					for (int d = c + 1; d < 5; d++) //for 4th num
					{
						for (int e = 0; e < resultNotWinarray.size(); e++) //for 5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
											<< " " << winNumarray.at(d) << " " << resultNotWinarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
									<< " " << winNumarray.at(d) << " " << resultNotWinarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (matchingNum == 5)
	{
		for (int a = 0; a < 1; a++) //for 1st num
		{
			for (int b = a + 1; b < 2; b++) //for 2nd num
			{
				for (int c = b + 1; c < 3; c++) //for 3rd num
				{
					for (int d = c + 1; d < 4; d++) //for 4th num
					{
						for (int e = d + 1; e < 5; e++) //for 5th num
						{
							if (matchingPow == 0)
							{
								for (unsigned int power = 1; power <= ubPow; power++) // for powerball
								{
									if (power != powerball)
									{
										std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
											<< " " << winNumarray.at(d) << " " << winNumarray.at(e) << " " << power << std::endl;
										count++;
									}
								}
							}
							else
							{
								std::cout << winNumarray.at(a) << " " << winNumarray.at(b) << " " << winNumarray.at(c)
									<< " " << winNumarray.at(d) << " " << winNumarray.at(e) << " " << powerball << std::endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	std::cout << "The number of ticket: " << count;
}
