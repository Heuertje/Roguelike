#pragma once
class Randomizer
{
public:
	Randomizer();
	~Randomizer();

	static Randomizer* mInstance;
	static Randomizer *Instance()
	{
		if (mInstance == 0)
		{
			mInstance = new  Randomizer();
		}
		return mInstance;
	}

	int generateRandomRow(int rowMaximumValue);
	int generateRandomCollumn(int collumnMaximumValue);
	int generateRandomNumber(int maximumNumber);
};

